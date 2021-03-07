#ifndef HESTIA_UTIL_ATOMIC_QUEUE_H
#define HESTIA_UTIL_ATOMIC_QUEUE_H

#include <mutex>
#include <queue>

template<typename T>
class AtomicQueue {
    std::queue<T> mQueue;
    mutable std::mutex mMutex;

public:
    void push(const T &value) {
        std::lock_guard<std::mutex> lock(mMutex);
        mQueue.push(value);
    }

    void pop() {
        std::lock_guard<std::mutex> lock(mMutex);
        mQueue.pop();
    }

    T front() {
        std::lock_guard<std::mutex> lock(mMutex);
        return mQueue.front();
    }

    long unsigned int size() {
        std::lock_guard<std::mutex> lock(mMutex);
        return mQueue.size();
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mMutex);
        return mQueue.empty();
    }
};

#endif