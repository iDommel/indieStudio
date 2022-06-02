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
        ButtonCallbacks enterCallbacks(
            []() {
                std::cout << "---------- enter pressed" << std::endl;
            },
            []() {
                std::cout << "---------- enter released" << std::endl;
            },
            []() {
                std::cout << "---------- enter down" << std::endl;
            });

        std::cout << "GameSystem::update" << std::endl;

        static int i = 3;
        if (i > 2) {
            std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            listener->addKeyboardEvent(KEY_ENTER, enterCallbacks);
            std::shared_ptr<String> string = std::make_shared<String>("Hello world");
            string->setType(String::Type::TEXT);
            entity->addComponent(listener);
            entity->addComponent(string);

            sceneManager.getCurrentScene().addEntity(entity);
            i--;
            return;
        }
        if (i > 1) {
            std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            auto tmp1 = sceneManager.getCurrentScene().getTaggedEntities({Entity::Tags::CALLABLE})[0];
            // sceneManager.getCurrentScene().removeEntity(tmp1);

            i--;
            return;
        }

        if (i > 0) {
            auto entity = sceneManager.getCurrentScene().getTaggedEntities({Entity::Tags::CALLABLE})[1];

            auto listener = Component::castComponent<EventListener>(entity->getComponents({Component::Type::EVT_LISTENER})[0]);
            listener->replaceKeyboardEvent(KEY_ENTER, KEY_SPACE);
            i--;
            return;
        }
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
        std::shared_ptr<String> component = std::make_shared<String>("audio");
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
        component->setType(Component::Type::SOUND);
        component2->setType(Component::Type::SPRITE);
        component3->setType(Component::Type::VECTOR);
        entity2->addComponent(listener);
        entity->addComponent(component2);
        entity->addComponent(component3);
        scene->addEntity(entity);
        scene->addEntity(entity2);
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