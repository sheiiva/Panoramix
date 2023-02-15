/* File: main.cpp
**
** Description: Main file of the project
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <iostream>

#include "Thread.hpp"

void f(char *arg)
{
    std::cout << std::string(arg) << std::endl;
}

int main(int ac, char **av)
{
    Thread t(&f,"Hello world");
    Thread t2(&f,"Hello world 2");

    t.join();
    t2.join();

    // try {
    //     // Argument checking
    //     ArgumentsHandler(ac, av);
    //     // Launch system
    //     nts::System system(av[1]);

    //     system.run();
    // } catch (const nts::Usage &e) {
    //     std::cout << e.what() << std::endl;
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << std::string(e.what()) << std::endl;
    //     return 84;
    // }
    return 0;
}