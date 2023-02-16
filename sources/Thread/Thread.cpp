/* File: Thread.cpp
**
** Description: [DESCRIPTION]
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Thread.hpp"

namespace panoramix
{

    void Thread::join()
    {
        _thread.join();
    }

}