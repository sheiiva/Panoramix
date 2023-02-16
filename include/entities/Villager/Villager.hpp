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

    namespace panoramix
    {

        class Villager
        {
            public:
                Villager() noexcept = delete;
                Villager(std::size_t const &id, std::size_t const &nb_fights) noexcept;
                Villager(Villager const& b) noexcept = default;
                Villager(Villager&& b) noexcept = default;
                ~Villager() noexcept;
        
                Villager& operator=(Villager const& rhs) noexcept = default;
                Villager& operator=(Villager&& rhs) noexcept = default;

                void run(std::size_t &pot);

                void drink(std::size_t &pot);
                void fight();

            private:
                std::size_t _id;
                std::size_t _nb_fights;
        };

    }

#endif /* !VILLAGER_HPP_ */