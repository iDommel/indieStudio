/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.hpp
*/

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "System.hpp"
#include "../Scene.hpp"

namespace Indie {

    class GameSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager) final override;
        void destroy() final override;

    private:
    };

}

#endif /* GAME_SYSTEM_HPP */