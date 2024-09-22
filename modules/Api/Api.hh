#ifndef API_HH__
#define API_HH__

#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

#include "Head.hh"

#if 0

class Timer {
  public:
    // 构造函数：设置定时时间（单位为毫秒）和回调函数
    Timer(unsigned int timeout, std::function<void()> callback)
        : timeout_(timeout), callback_(callback), running_(false) {}

    // 启动定时器
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

    // 停止定时器（在定时结束前调用）
    void stop() {
        running_ = false;
        condition_.notify_one();
        if (timer_thread_.joinable()) {
            timer_thread_.join();
        }
    }

    // 析构函数
    ~Timer() {
        stop(); // 确保定时器停止并线程结束
    }

  private:
    unsigned int timeout_;              // 定时时间（毫秒）
    std::function<void()> callback_;    // 回调函数
    bool running_;                      // 运行状态标志
    std::mutex mutex_;                  // 互斥锁
    std::condition_variable condition_; // 条件变量
    std::thread timer_thread_;          // 定时器线程
};
#endif

void UseHeadFunc(void);
void LoadSharedLib(void);

void DoSomething(void);

#endif