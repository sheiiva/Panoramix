/* File: main.cpp
**
** Description: Main file of the project
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "ThreadPool.hpp"

void my_function(int param)
{
    // Do some work here
    std::cout << "my_function executed with param " << param << std::endl;
}

int main()
{
    // Create a thread pool with 4 worker threads
    ThreadPool pool(4);

    // Add some tasks to the thread pool
    for (int i = 0; i < 10; ++i) {
        pool.enqueue(my_function, i);
    }

    // Wait for all tasks to complete
    // This is not strictly necessary, but it ensures that the program
    // doesn't exit before all tasks have completed
    pool.wait();

    return 0;
}