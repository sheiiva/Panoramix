/* File: Usage.hpp
**
** Description: Defines Usage class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef USAGE_HPP_
    #define USAGE_HPP_

    #include <iostream>
    #include <exception>

    #define USAGE_ "\
    USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights_> <nb_refills>\n\
    \n\
    DESCRIPTION\n\
        nb_villagers:\tindicates the number of villagers (must be >0)\n\
        pot_size:\tindicates the maximum number that can be contained in the cooking pot (must be >0)\n\
        nb_fights_:\tindicates the maximum number of fights a villager will engage in (must be >0)\n\
        nb_refills:\tincicates the maximum number of time the druid will refill the pot (must be >0)."

    namespace panoramix
    {
        class Usage : public std::exception {
            public:
                const char *what() const noexcept override { return USAGE_; }
        };
    }

#endif /* !USAGE_HPP_ */