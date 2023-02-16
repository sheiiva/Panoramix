/* File: Druid.cpp
**
** Description: Defines Druid methods
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Druid.hpp"

namespace panoramix
{

    Druid::Druid() noexcept
    {
        std::cout << "Druid: I'm ready... but sleepy..." << std::endl;
    }

    void Druid::refill(size_t const pot_size, std::size_t &pot)
    {
        if (_nb_refills == 0)
            return;
        // Refill the pot
        pot = pot_size;
        //
        std::cout << "Druid: Ah! Yes, yes, I'm awake! Working on it!";
        std::cout << "Beware I can only make " << --_nb_refills << " more refills after this one." << std::endl;
    }

    Druid::~Druid() noexcept
    {
        std::cout << "Druid: I'm out of viscum. I'm going to sleep." << std::endl;
    }

}