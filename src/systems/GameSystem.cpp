/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "raylib.h"
#include "Position.hpp"
#include "Window.hpp"

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
        std::cout << "GameSystem::update" << std::endl;

        auto e = sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_2D][0];
        auto comp = (*e)[Component::Type::SPRITE];
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        ButtonCallbacks spaceCallbacks(
            std::bind(&GameSystem::printStuff, this),
            []() {
                std::cout << "---------- space released" << std::endl;
            },
            std::bind(&GameSystem::printStuff, this));

        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("audio");
        std::shared_ptr<Sprite> component2 = std::make_shared<Sprite>("sprite");
        std::shared_ptr<Sprite> component3 = std::make_shared<Sprite>("vector");
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
        component->setType(Component::Type::SOUND);
        component2->setType(Component::Type::SPRITE);
        component3->setType(Component::Type::VECTOR);

        entity2->addComponent(component)
            .addComponent(listener);
        entity->addComponent(component2)
            .addComponent(component3);

        scene->addEntities({entity, entity2});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createMainMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png");
        std::shared_ptr<Position> component2 = std::make_shared<Position>(0, 0);
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component3 = std::make_shared<Sprite>("assets/MainMenu/play_unpressed.png");
        std::shared_ptr<Position> component4 = std::make_shared<Position>(0, 0);
        std::shared_ptr<Entity> entity3 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component5 = std::make_shared<Sprite>("assets/MainMenu/option_unpressed.png");
        std::shared_ptr<Position> component6 = std::make_shared<Position>(0, 0);
        std::shared_ptr<Entity> entity4 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component7 = std::make_shared<Sprite>("assets/MainMenu/quit_unpressed.png");
        std::shared_ptr<Position> component8 = std::make_shared<Position>(0, 0);

        entity1->addComponent(component)
            .addComponent(component2);
        entity2->addComponent(component3)
            .addComponent(component4);
        entity3->addComponent(component5)
            .addComponent(component6);
        entity4->addComponent(component7)
            .addComponent(component8);
    
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

    void GameSystem::printStuff()
    {
        std::cout << "GameSystem::printStuff" << std::endl;
    }
}