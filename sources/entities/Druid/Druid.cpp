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

    Druid::Druid(std::mutex& mutex, std::condition_variable& condition, std::size_t const& pot_size, std::size_t& pot, std::size_t const& nb_refills) :
        nb_refills_(nb_refills), mutex_(mutex), condition_(condition)
    {
        thread_ = std::thread(&Druid::awake, this, pot_size, std::ref(pot));
    }

    void Druid::awake(std::size_t const& pot_size, std::size_t& pot)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Druid: I'm ready... but sleepy..." << std::endl;
        }

        while (nb_refills_ > 0) {
            // Wait for the pot to be empty
            {
                std::unique_lock<std::mutex> lock(mutex_);
                condition_.wait(lock, [&pot] { return pot == 0; });
            }
            refill(pot_size, pot);
        }

        {
            std::lock_guard<std::mutex> lock(mutex_);
            std::cout << "Druid: I'm out of viscum. I'm going to sleep." << std::endl;
        }
    }

    void Druid::refill(size_t const& pot_size, std::size_t& pot)
    {
        if (nb_refills_ == 0)
            return;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            // Refill the pot
            pot = pot_size;
            std::cout << "Druid: Ah! Yes, yes, I'm awake! Working on it! ";
            std::cout << "Beware I can only make " << --nb_refills_ << " more refills after this one." << std::endl;
        }
        condition_.notify_all();
    }

    void Druid::join()
    {
        thread_.join();
    }

}