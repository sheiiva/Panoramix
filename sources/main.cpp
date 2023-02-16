/* File: main.cpp
**
** Description: Main file of the project
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "ArgumentChecker.hpp"

int main(int ac, char **av)
{
    try {
        // Argument checking
        panoramix::ArgumentChecker(ac, av);
        // // Launch system
        // panoramix::System system(av[1]);

        // system.run();
    } catch (const panoramix::Usage &e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << std::string(e.what()) << std::endl;
        return 84;
    }
    return 0;
}