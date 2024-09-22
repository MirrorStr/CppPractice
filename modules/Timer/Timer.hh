#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

class Timer {
  public:
    Timer(unsigned int timeout, std::function<void()> callback)
        : timeout_(timeout), callback_(callback), running_(false) {}

    void start() {
        running_ = true;
        timer_thread_ = std::thread([this]() {
            std::unique_lock<std::mutex> lock(this->mutex_);
            condition_.wait_for(lock, std::chrono::milliseconds(timeout_),
                                [this] { return !this->running_; });
            if (running_) {
                callback_(); // 执行回调函数
            }
        });
    }

    void stop() {
        running_ = false;
        condition_.notify_one();
        if (timer_thread_.joinable()) {
            timer_thread_.join();
        }
    }

    ~Timer() {
        stop(); // 确保定时器停止并线程结束
    }

  private:
    unsigned int timeout_;
    std::function<void()> callback_;
    bool running_;
    std::mutex mutex_;
    std::condition_variable condition_;
    std::thread timer_thread_;
};

#endif