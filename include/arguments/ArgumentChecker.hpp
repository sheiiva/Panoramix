/* File: ArgumentChecker.hpp
**
** Description: Defines ArgumentChecker class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef ARGUMENTCHECKER_HPP_
    #define ARGUMENTCHECKER_HPP_

    #include <string>
    #include <iostream>

    #include "Usage.hpp"

    namespace panoramix
    {
        class ArgumentChecker
        {
            public:
                ArgumentChecker() noexcept = delete;
                ArgumentChecker(int ac, char **av);
                ArgumentChecker(ArgumentChecker const& b) noexcept = default;
                ArgumentChecker(ArgumentChecker&& b) noexcept = default;
                ~ArgumentChecker() noexcept = default;
        
                ArgumentChecker& operator=(ArgumentChecker const& rhs) noexcept = default;
                ArgumentChecker& operator=(ArgumentChecker&& rhs) noexcept = default;

            private:
                void run(int ac, char **av);
        };
    }

#endif /* !ARGUMENTCHECKER_HPP_ */