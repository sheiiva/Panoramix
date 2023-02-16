/* File: Core.hpp
**
** Description: Defines Core class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <cstddef>

    namespace panoramix
    {
        class Core
        {
            public:
                Core() = delete;
                Core(std::size_t, std::size_t, std::size_t, std::size_t);
                Core(Core const& b) noexcept = default;
                Core(Core&& b) noexcept = default;
                ~Core() noexcept = default;
        
                Core& operator=(Core const& rhs) noexcept = default;
                Core& operator=(Core&& rhs) noexcept = default;

                void run();

            private:
                bool    _running;
                size_t  _nb_villagers;
                size_t  _pot_size;
                size_t  _nb_fights;
                size_t  _nb_refills;
        };
    }

#endif /* !CORE_HPP_ */