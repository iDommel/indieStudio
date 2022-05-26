/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SceneManager.cpp
*/

#include <stdexcept>

#include "SceneManager.hpp"

namespace indie
{
    void SceneManager::addScene(std::unique_ptr<IScene> scene, SceneType sceneType)
    {
        if (_scenes.find(sceneType) != _scenes.end())
            throw std::invalid_argument("SceneManager: Scene already exists");
        _scenes[sceneType] = std::move(scene);
    }

    IScene &SceneManager::getCurrentScene()
    {
        if (_scenes.find(_currentScene) == _scenes.end())
            throw std::runtime_error("SceneManager: Invalid current scene");
        _sceneChanged = false;
        return *_scenes[_currentScene];
    }

    void SceneManager::setCurrentScene(SceneType sceneType)
    {
        if (_scenes.find(sceneType) == _scenes.end())
            throw std::invalid_argument("SceneManager: Invalid scene type");
        _currentScene = sceneType;
        _sceneChanged = true;
    }

    bool SceneManager::hasSceneChanged() const
    {
        return _sceneChanged;
    }
}