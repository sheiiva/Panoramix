/* File: Thread.hpp
**
** Description: [DESCRIPTION]
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef THREAD_HPP_
    #define THREAD_HPP_

    #include <thread>

    namespace panoramix
    { 

        class Thread
        {
            public:
                Thread() noexcept = default;
                Thread(Thread const& b) noexcept = delete;
                Thread(Thread&& b) noexcept = default;
                ~Thread() noexcept = default;
        
                Thread& operator=(Thread const& rhs) noexcept = delete;
                Thread& operator=(Thread&& rhs) noexcept = delete;

                void join();

            private:
                std::thread thread_;
        };

    }

#endif /* !THREAD_HPP_ */