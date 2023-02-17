/* File: Villager.hpp
**
** Description: Defines Villager class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef VILLAGER_HPP_
    #define VILLAGER_HPP_

    #include <cstddef>
    #include <iostream>
    #include <thread>
    #include <mutex>
    #include <condition_variable>
    #include <thread>

    namespace panoramix
    {

        class Villager
        {
            public:
                Villager(std::mutex &mutex, std::condition_variable &condition, std::size_t const id, std::size_t &pot, std::size_t const nb_fights_);
                Villager() noexcept = delete;
                Villager(Villager const& b) noexcept = delete;
                Villager(Villager&& b) noexcept = default;
                ~Villager() noexcept = default;
        
                Villager& operator=(Villager const& rhs) noexcept = delete;
                Villager& operator=(Villager&& rhs) noexcept = delete;

                void join();

            // private methods
            private:
                void awake(std::size_t &pot);
                void drink(std::size_t &pot);
                void fight();

            private:
                const std::size_t       id_;
                std::size_t             nb_fights_;
                std::mutex              &mutex_;
                std::condition_variable &condition_;
                std::thread             thread_;
        };

    }

#endif /* !VILLAGER_HPP_ */