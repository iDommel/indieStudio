/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <iostream>

#include "../Core.hpp"
#include "../Entity.hpp"
#include "../Scene.hpp"
#include "String.hpp"
#include "Vector.hpp"

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.addScene(createMainMenu(), SceneManager::SceneType::MAIN_MENU);
        sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        // std::cout << "GameSystem::update" << std::endl;
        
        // sceneManager.getCurrentScene().addEntity(std::make_shared<Entity>());
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(&createScene);
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
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
        scene->addEntity(entity);
        scene->addEntity(entity2);
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(&createScene);
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<String> component = std::make_shared<String>("assets/MainMenu/menu.png");
        std::shared_ptr<Vector2> component2 = std::make_shared<Vector2>(0, 0);
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<String> component3 = std::make_shared<String>("assets/MainMenu/play_unpressed.png");
        std::shared_ptr<Vector2> component4 = std::make_shared<Vector2>(0, 0);
        std::shared_ptr<Entity> entity3 = std::make_shared<Entity>();
        std::shared_ptr<String> component5 = std::make_shared<String>("assets/MainMenu/option_unpressed.png");
        std::shared_ptr<Vector2> component6 = std::make_shared<Vector2>(0, 0);
        std::shared_ptr<Entity> entity4 = std::make_shared<Entity>();
        std::shared_ptr<String> component7 = std::make_shared<String>("assets/MainMenu/quit_unpressed.png");
        std::shared_ptr<Vector2> component8 = std::make_shared<Vector2>(0, 0);

        component->setType(Component::Type::SPRITE);
        component2->setType(Component::Type::VECTOR);
        component3->setType(Component::Type::SPRITE);
        component4->setType(Component::Type::VECTOR);
        component5->setType(Component::Type::SPRITE);
        component6->setType(Component::Type::VECTOR);
        component7->setType(Component::Type::SPRITE);
        component8->setType(Component::Type::VECTOR);
        entity1->addComponent(component);
        entity1->addComponent(component2);
        entity2->addComponent(component3);
        entity2->addComponent(component4);
        entity3->addComponent(component5);
        entity3->addComponent(component6);
        entity4->addComponent(component7);
        entity4->addComponent(component8);
        scene->addEntity(entity1);
        scene->addEntity(entity2);
        scene->addEntity(entity3);
        scene->addEntity(entity4);
        return scene;
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity>)
    {
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

}