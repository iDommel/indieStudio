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
         * @brief Types of systems: systems init and destroy calls are effectued by ascending order
         */
        enum class SystemType {
            GAME,
            EVENT,
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
