/* File: Druid.hpp
**
** Description: Defines Druid class
**
** 2023, February 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef DRUID_HPP_
    #define DRUID_HPP_

    #include <cstddef>
    #include <iostream>

    namespace panoramix 
    {

        class Druid
        {
            public:
                Druid() noexcept;
                Druid(Druid const& b) noexcept = default;
                Druid(Druid&& b) noexcept = default;
                ~Druid() noexcept;
        
                Druid& operator=(Druid const& rhs) noexcept = default;
                Druid& operator=(Druid&& rhs) noexcept = default;

                void refill(std::size_t const pot_size, std::size_t &pot);

            private:
                std::size_t _nb_refills;
        };

    }

#endif /* !DRUID_HPP_ */