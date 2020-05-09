#ifndef HESTIA_UTIL_LOGGER_H
#define HESTIA_UTIL_LOGGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <thread>

#include "util/atomic_queue.h"

namespace HGE {
    class Logger {
        static Logger mLogger;
        AtomicQueue<std::string> mMsgQueue;
        std::thread mThread;
        bool mThreadRunning;

        const int maxMsgQueueSize = 1000;
        const int tagLength = 24;

        const std::string colourRed = "\033[31m";
        const std::string colourWhite = "\033[37m";
        const std::string colourGreen = "\033[32m";
        const std::string colourYellow = "\033[33m";

        void loggingThreadLoop() {
          while (mThreadRunning) {
            if (!mMsgQueue.empty()) {
                std::cout << mMsgQueue.front();
                mMsgQueue.pop();
            }
          }
        }

        Logger() {
          mThreadRunning = true;
          mThread = std::thread(&Logger::loggingThreadLoop, this);
        }

        template<typename T, typename... Ts>
        void buildString(std::stringstream &ss, T nextArg, Ts&&... args) {
            ss << ' ' << nextArg;
            buildString(ss, args...);
        }

        template<typename T>
        void buildString(std::stringstream &ss, T&& lastArg) {
            ss << ' ' << lastArg << '\n';
        }

        template<typename... Ts>
        std::string buildString(Ts&&... args) {
            std::stringstream ss;
            buildString(ss, args...);
            return ss.str();
        }

        std::string structureTag(const std::string &tag) {
            if(tag.size() > tagLength) {
                std::string s = tag.substr(0, tagLength - 3) + "..."; 
                return s;
            } else {
                std::string s = tag + std::string(tagLength - tag.size(), ' ');
                return s;
            }
        }
        
        public:
        static Logger* getInstance() {
            return &mLogger;
        }

        ~Logger() {
          mThreadRunning = false;
          mThread.join();
        }

        template<typename... Ts>
        void logDebug(const std::string &tag, Ts&&... args) {
            if(mMsgQueue.size() > maxMsgQueueSize) {
                mMsgQueue.pop();
            } 
            mMsgQueue.push(buildString(colourGreen + "DEBUG: " + colourWhite, structureTag(tag), " - ", args...));
        }

        template<typename... Ts>
        void logWarning(const std::string &tag, Ts&&... args) {
            if(mMsgQueue.size() < maxMsgQueueSize) {
                mMsgQueue.pop();
            }
            mMsgQueue.push(buildString(colourYellow + "WARNING: " + colourWhite, structureTag(tag), " - ", args...));
        }

        template<typename... Ts>
        void logError(const std::string &tag, Ts&&... args) {
            if(mMsgQueue.size() < maxMsgQueueSize) {
                mMsgQueue.pop();
            }
            mMsgQueue.push(buildString(colourRed + "ERROR: " + colourWhite, structureTag(tag), " - ", args...));
        }
    };
}
#endif