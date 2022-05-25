/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core.hpp
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <map>

#include "Systems/ISystem.hpp"
#include "SceneManager.hpp"

#define UPDATE_DELTA     17

namespace indie {
    class Core
    {
    public:

        /**
         * @brief Types of systems: systems call are by ascending order
         */
        enum class SystemType {
            GAME,
            GRAPHIC,
            AUDIO
        };

        Core();

        void mainLoop();

    private:
        std::map<SystemType, std::unique_ptr<ISystem>> _systems;
        SceneManager _sceneManager;
        bool _end = false;
    };
}

#endif /* CORE_HPP */
