/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SceneManager.cpp
*/

#include "SceneManager.hpp"

#include <iostream>
#include <stdexcept>
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
        return *_scenes[_currentScene];
    }

    void SceneManager::setCurrentScene(SceneType sceneType, bool initScene)
    {
        if (_scenes.find(sceneType) == _scenes.end())
            throw std::invalid_argument("SceneManager: Invalid scene type");
        _currentScene = sceneType;
        if (initScene) {
            _scenes[_currentScene] = _scenes[_currentScene]->initScene();
        }
    }

    std::map<SceneManager::SceneType, std::unique_ptr<IScene>> &SceneManager::getScenes()
    {
        return _scenes;
    }

    void SceneManager::setAddEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback)
    {
        for (auto &scene : _scenes) {
            scene.second->setAddEntityCallback(callback);
        }
    }

    void SceneManager::setShouldClose(bool shouldClose)
    {
        _shouldClose = shouldClose;
    }

    bool SceneManager::getShouldClose()
    {
        return _shouldClose;
    }

    void SceneManager::setRemoveEntityCallback(std::function<void(std::shared_ptr<IEntity>)> callback)
    {
        for (auto &scene : _scenes) {
            scene.second->setRemoveEntityCallback(callback);
        }
    }
}