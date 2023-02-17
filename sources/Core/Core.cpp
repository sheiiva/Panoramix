/* File: Core.cpp
**
** Description: Defines Core methods
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <mutex>
#include <condition_variable>

#include "Core.hpp"

#include "Druid.hpp"
#include "Villager.hpp"

namespace panoramix
{
    Core::Core(std::size_t nb_villagers, std::size_t pot_size, std::size_t nb_fights_, std::size_t nb_refills) :
        nb_villagers_(nb_villagers), pot_size_(pot_size), nb_fights_(nb_fights_), nb_refills_(nb_refills)
    {
        pot_ = pot_size_;
    }

    void Core::run()
    {

        std::mutex              mutex;
        std::condition_variable condition;

        Druid                   druid(std::ref(mutex), std::ref(condition),
                                        pot_size_, std::ref(pot_), nb_refills_);
        std::vector<Villager*>   villagers;

        for (std::size_t i = 0; i < nb_villagers_; i++) {
            villagers.push_back(
                new Villager(std::ref(mutex), std::ref(condition), i, std::ref(pot_), nb_fights_)
            );
        }

        druid.join();
        for (auto &villager : villagers)
            villager->join();
    }
}