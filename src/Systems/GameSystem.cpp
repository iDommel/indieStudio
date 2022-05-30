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
#include "../Core.hpp"

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
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(&createScene, &Core::addEntityCallback);
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        std::shared_ptr<String> component = std::make_shared<String>("audio");
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<String> component4 = std::make_shared<String>("evt");

        component->setType(Component::Type::SOUND);
        component2->setType(Component::Type::SPRITE);
        component3->setType(Component::Type::VECTOR);
        component4->setType(Component::Type::EVT_LISTENER);
        entity2->addComponent(component);
        entity->addComponent(component2);
        entity->addComponent(component3);
        entity2->addComponent(component4);
        scene->addEntity(std::move(entity));
        scene->addEntity(std::move(entity2));
        return scene;
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::cout << "GameSystem::loadEntity"<< std::endl;
    }

}