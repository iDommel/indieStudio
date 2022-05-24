/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core.hpp
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <map>

#include "Systems/System.hpp"
#include "SceneManager.hpp"

namespace Indie {
    class Core
    {
    public:

        enum class SystemType {
            GRAPHIC,
            AUDIO,
            GAME
        };

        Core();

        void mainLoop();

    private:
        std::map<SystemType, std::unique_ptr<ISystem>> _systems;
        SceneManager _sceneManager;
    };
}

#endif /* CORE_HPP */
