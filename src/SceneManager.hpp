/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SceneManager.hpp
*/

#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <map>
#include <memory>

#include "IScene.hpp"

namespace indie {
    class SceneManager
    {
    public:
        enum class SceneType {
            NONE = -1,
            GAME,
            MAIN_MENU,
            PAUSE,
            OPTION
        };

        /**
         * @brief Add a scene to the scene manager
         * @param scene Scene to add
         * @param sceneType Type of the scene, needs to be unique for each scene
         */
        void addScene(std::unique_ptr<IScene> scene, SceneType sceneType);

        /**
         * @brief Returns the current scene
         * @return Reference of the current scene
         */
        IScene &getCurrentScene();

        /**
         * @brief Set the current scene to the scene corresponding to the given sceneType
         * @param sceneType Type of the scene to set as the current scene
         * @param initScene Boolean to reinitialize the scene, set too false by default
         */
        void setCurrentScene(SceneType scene, bool initScene = false);

    private:
        std::map<SceneType, std::unique_ptr<IScene>> _scenes;
        SceneType _currentScene = SceneType::NONE;
    };
}

#endif /* SCENE_MANAGER_HPP */