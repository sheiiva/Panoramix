/* File: Villager.cpp
**
** Description: Defines Villager methods
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Villager.hpp"

namespace panoramix
{
    Villager::Villager(std::size_t const &id, std::size_t const &nb_fights) noexcept :
        _id(id), _nb_fights(nb_fights)
    {
        std::cout << "Villager " << _id << ": Going into battle!" << std::endl;
    }

    Villager::~Villager() noexcept
    {
        std::cout << "Villager " << _id << ": I'm going to sleep now." << std::endl;
    }

    void Villager::run(std::size_t &pot)
    {
        while (_nb_fights > 0) {
            drink(pot);
            fight();
        }
    }

    void Villager::drink(std::size_t &pot)
    {
        std::cout << "Villager " << _id << ": I need a drink... ";
        std::cout << "I see " << pot << " servings left." << std::endl;

        if (pot == 0) {
            std::cout << "Villager " << _id << ": Hey Pano wake up! We need more potion. " << std::endl;
            // ping Druid
            // Wait for refill
        }

        // Drink
        pot--;
    }

    void Villager::fight()
    {
        // Fight
        _nb_fights--;

        std::cout << "Villager " << _id << ": Take that roman scum! ";
        std::cout << "Only " << _nb_fights << " left .";
    }
}