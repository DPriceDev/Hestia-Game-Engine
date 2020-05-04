#ifndef HESTIA_UTIL_LOGGER_HPP_
#define HESTIA_UTIL_LOGGER_HPP_

#include <iostream>
#include <string>
#include <queue>

#include <thread>

namespace HGE {
    class Logger {

        static Logger mLogger;
        std::queue<std::string> mMsgQueue;
        std::thread mThread;
        bool mThreadRunning;

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
            mMsgQueue.push("DEBUG: " + tag + " - " + msg);
        }

        void logError(const std::string &tag, const std::string &msg) {
            mMsgQueue.push("ERROR: " + tag + " - " + msg);
        }
    };
}
#endif