/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "Position.hpp"
#include "Sprite.hpp"
#include "Rect.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "raylib.h"

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        static int i = 0;
        static int j = -1;

        i++;
        if (i % 3 == 0) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]->getFilteredComponents({ IComponent::Type::RECT });
            auto r = Component::castComponent<Rect>(components[0]);
            r->left = 100 * (j++);
            if (j  > 5)
                j = -1;
        }
        if (i == 100) {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            std::shared_ptr<Position> component = std::make_shared<Position>(500, 100);
            std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
            entity->addComponent(component).addComponent(component4);
            sceneManager.getCurrentScene().addEntity(entity);
        } else if (i == 200) {
            sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][2]);
        }
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        ButtonCallbacks spaceCallbacks(
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1),
            [](SceneManager &) {
                std::cout << "---------- space released" << std::endl;
            },
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1));

        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");

        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 100, 100);
        std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png");

        component2->setType(Component::Type::TEXT);
        component3->setType(Component::Type::HITBOX);
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        entity2->addComponent(component)
            .addComponent(component4);
        entity->addComponent(component2)
            .addComponent(component3);

        e->addComponent(rect)
            .addComponent(pos)
            .addComponent(sprite);

        scene->addEntities({entity, entity2, e});
        return scene;
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity>)
    {
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

    void GameSystem::printStuff(SceneManager &)
    {
        std::cout << "GameSystem::printStuff" << std::endl;
    }
}