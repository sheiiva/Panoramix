/* File: Thread.hpp
**
** Description: Definition for the Thread class
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef THREAD_HPP_
    #define THREAD_HPP_

    #include <thread>

    typedef void (*_f)(char*);

    class Thread
    {
        public:
            Thread(_f f, char*);
            Thread() noexcept = delete;
            Thread(Thread const& b) noexcept = default;
            Thread(Thread&& b) noexcept = default;
            ~Thread() noexcept = default;
    
            Thread& operator=(Thread const& rhs) noexcept = default;
            Thread& operator=(Thread&& rhs) noexcept = default;

            void join();

        private:
            std::thread _thread;
    };

#endif /* !THREAD_HPP_ */