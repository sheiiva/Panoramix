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
    Villager::Villager(std::mutex &mutex, std::condition_variable &condition, std::size_t const id, std::size_t &pot, std::size_t const nb_fights_) :
        id_(id), nb_fights_(nb_fights_), mutex_(mutex), condition_(condition)
    {
        thread_ = std::thread(&Villager::awake, this, std::ref(pot));
    }

    void Villager::awake(std::size_t &pot)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Villager " << id_ << ": Going into battle!" << std::endl;
        }

        while (nb_fights_ > 0) {
            drink(pot);
            fight();
        }

        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Villager " << id_ << ": I'm going to sleep now." << std::endl;
        }

    }

    void Villager::drink(std::size_t &pot)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Villager " << id_ << ": I need a drink... ";
            std::cout << "I see " << pot << " servings left." << std::endl;
        }

        if (pot == 0) {
            {
                std::lock_guard<std::mutex> lock(mutex_);
                std::cout << "Villager " << id_ << ": Hey Pano wake up! We need more potion. " << std::endl;
            }
            // Notify Druid
            condition_.notify_all();
            // Wait for refill
            {
                std::unique_lock<std::mutex> lock(mutex_);
                condition_.wait(lock, [&pot] { return pot; });
            }
        }

        {
            std::lock_guard<std::mutex> lock(mutex_);
            // Drink
            pot--;
        }

    }

    void Villager::fight()
    {
        // Fight
        nb_fights_--;

        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Villager " << id_ << ": Take that roman scum! ";
            std::cout << "Only " << nb_fights_ << " left." << std::endl;
        }
    }

    void Villager::join()
    {
        thread_.join();
    }
}