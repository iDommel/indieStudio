/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.hpp
*/

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "ISystem.hpp"
#include "../SceneManager.hpp"

namespace indie {

    class GameSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager, uint64_t deltaTime) final override;
        void destroy() final override;

    private:
        std::unique_ptr<IScene> createScene();
    };

}

#endif /* GAME_SYSTEM_HPP */