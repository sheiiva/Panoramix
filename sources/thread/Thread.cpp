/* File: Thread.cpp
**
** Description: Defines Thread class methods
**
** 2023, February 15
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Thread.hpp"

Thread::Thread(_f f, char *arg) :
    _thread(f, arg)
{
}

void Thread::join()
{
    _thread.join();
}