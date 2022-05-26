/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include <iostream>

#include "GameSystem.hpp"
#include "../Scene.hpp"
#include "../Entity.hpp"
#include "../Components/String.hpp"

namespace indie {

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(std::move(createScene()), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
    }

    void GameSystem::update(indie::SceneManager &, uint64_t)
    {
        std::cout << "GameSystem::update" << std::endl;
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>();
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        std::shared_ptr<String> component = std::make_shared<String>("vector");
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");

        component->setTag(Component::Tags::SOUND);
        // component2->setTag(Component::Tags::SPRITE);
        entity->addComponent(component);
        // entity->addComponent(component2);
        scene->addEntity(std::move(entity));
        return scene;
    }

}