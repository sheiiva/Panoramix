/* File: Core.cpp
**
** Description: Defines Core methods
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Core.hpp"

namespace panoramix
{
    Core::Core(std::size_t nb_villagers, std::size_t pot_size, std::size_t nb_fights, std::size_t nb_refills) :
        _running(false), _nb_villagers(nb_villagers), _pot_size(pot_size), _nb_fights(nb_fights), _nb_refills(nb_refills)
    {
    }

    void Core::run()
    {
        _running = true;
        while (_running) {
        }
    }
}