/* File: ArgumentChecker.cpp
**
** Description: Defines ArgumentChecker class methods
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "ArgumentChecker.hpp"

namespace panoramix
{
    ArgumentChecker::ArgumentChecker(int ac, char **av)
    {
        this->run(ac, av);
    }

    void ArgumentChecker::run(int ac, char **av)
    {
        // Check if the user wants to see the help message
        if ((ac == 2) && ((std::string(av[1]) == "-h") || (std::string(av[1]) == "--help")))
            throw Usage();

        // Check arguments
        if (ac != 5)
            throw std::invalid_argument("Invalid number of arguments.");
        for (int i = 1; i < ac; i++) {
            if (atoi(av[i]) <= 0) {
                throw std::invalid_argument("Invalid argument: \"" + std::string(av[i]) + "\" is not a valid number.");
            }
        }
    }
}