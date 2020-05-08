#ifndef HESTIA_UTIL_LOGGER_H
#define HESTIA_UTIL_LOGGER_H

#include <iostream>
#include <string>
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

        void loggingThreadLoop() {
          while (mThreadRunning) {
            if (!mMsgQueue.empty()) {
                std::cout << mMsgQueue.front() << "\n";
                mMsgQueue.pop();
            }
          }
        }

        Logger() {
          mThreadRunning = true;
          mThread = std::thread(&Logger::loggingThreadLoop, this);
        }
        
        public:
        static Logger* getInstance() {
            return &mLogger;
         }

        ~Logger() {
          mThreadRunning = false;
          mThread.join();
        }

        void logDebug(const std::string &tag, const std::string &msg) {
            if(mMsgQueue.size() > maxMsgQueueSize) {
                mMsgQueue.pop();
            } 
            mMsgQueue.push("DEBUG: " + tag + " - " + msg);
            
        }

        void logError(const std::string &tag, const std::string &msg) {
            if(mMsgQueue.size() < maxMsgQueueSize) {
                mMsgQueue.pop();
            }
            mMsgQueue.push("ERROR: " + tag + " - " + msg);
        }
    };
}
#endif