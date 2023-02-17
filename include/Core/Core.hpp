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
    #include <vector>

    namespace panoramix
    {
        class Core
        {
            public:
                Core() = delete;
                Core(std::size_t, std::size_t, std::size_t, std::size_t);
                Core(Core const& b) noexcept = delete;
                Core(Core&& b) noexcept = delete;
                ~Core() noexcept = default;
        
                Core& operator=(Core const& rhs) noexcept = delete;
                Core& operator=(Core&& rhs) noexcept = delete;

                void run();

            private:
                std::size_t         pot_;
                const std::size_t   nb_villagers_;
                const std::size_t   pot_size_;
                std::size_t         nb_fights_;
                std::size_t         nb_refills_;
        };
    }

#endif /* !CORE_HPP_ */