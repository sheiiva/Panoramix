/* File: Druid.hpp
**
** Description: Defines Druid class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef DRUID_HPP_
    #define DRUID_HPP_

    #include <condition_variable>
    #include <cstddef>
    #include <iostream>
    #include <mutex>
    #include <thread>

    namespace panoramix 
    {

        class Druid
        {
            public:
                Druid(std::mutex& mutex, std::condition_variable& condition, std::size_t const& pot_size, std::size_t& pot, std::size_t const& nb_refills);
                Druid() noexcept = delete;
                Druid(Druid const& b) noexcept = delete;
                Druid(Druid&& b) noexcept = delete;
                ~Druid() noexcept = default;
        
                Druid& operator=(Druid const& rhs) noexcept = delete;
                Druid& operator=(Druid&& rhs) noexcept = delete;

                void join();

            // private methods
            private:
                void awake(std::size_t const& pot_size, std::size_t& pot);
                void refill(std::size_t const& pot_size, std::size_t& pot);

            private:
                std::size_t             nb_refills_;
                std::mutex              &mutex_;
                std::condition_variable &condition_;
                std::thread             thread_;
        };

    }

#endif /* !DRUID_HPP_ */