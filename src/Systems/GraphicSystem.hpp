/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicSystem.hpp
*/

#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP

#include "ISystem.hpp"
#include "../SceneManager.hpp"

namespace indie {

    class GraphicSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager, uint64_t deltaTime) final override;
        void destroy() final override;

    private:
    };

}

#endif /* GRAPHIC_SYSTEM_HPP */