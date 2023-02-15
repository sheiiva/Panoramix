/* File: ThreadPool.hpp
**
** Description: Definition for the ThreadPool class
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

    #include <condition_variable>
    #include <functional>
    #include <future>
    #include <iostream>
    #include <mutex>
    #include <queue>
    #include <thread>
    #include <vector>

    using Task = std::function<void()>;

    class ThreadPool
    {
        public:
            ThreadPool(size_t nbThreads);
            ThreadPool() noexcept = delete;
            ThreadPool(ThreadPool const& b) noexcept = delete;
            ThreadPool(ThreadPool&& b) noexcept = delete;
            ~ThreadPool();
    
            ThreadPool& operator=(ThreadPool const& rhs) noexcept = delete;
            ThreadPool& operator=(ThreadPool&& rhs) noexcept = delete;

            template<class F, class... Args>
            auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
            {
                using return_type = typename std::result_of<F(Args...)>::type;

                auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

                std::future<return_type> result = task->get_future();
                {
                    std::unique_lock<std::mutex> lock(_mutex);
                    if (_stop) {
                        throw std::runtime_error("enqueue on stopped ThreadPool");
                    }
                    _tasks.emplace([task]() { (*task)(); });
                }
                _condition.notify_one();
                return result;
            }

            void wait();

        private:
            std::vector<std::thread>    _threads;
            std::queue<Task>            _tasks;

            std::mutex              _mutex;
            std::condition_variable _condition;
            bool                    _stop;
    };

#endif /* !THREADPOOL_HPP_ */