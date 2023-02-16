/* File: ThreadPool.cpp
**
** Description: Defines ThreadPool class methods
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t nbThreads) :
    _stop(false)
{
    for (size_t i = 0; i < nbThreads; ++i) {
        _threads.emplace_back(
            [this] {
                for (;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(_mutex);
                        _condition.wait(lock, [this] { return _stop || !_tasks.empty(); });
                        if (_stop && _tasks.empty()) {
                            return;
                        }
                        task = std::move(_tasks.front());
                        _tasks.pop();
                        _condition.notify_one();
                    }
                    task();
                }
            }
        );
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _stop = true;
    }
    _condition.notify_all();
    for (std::thread &thread : _threads)
        thread.join();
}

void ThreadPool::wait()
{
    std::unique_lock<std::mutex> lock(_mutex);
    _condition.wait(lock, [this] { return _tasks.empty(); });
}