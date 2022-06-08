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
#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "Bonus.hpp"
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
        /*static int i = 0;
        // std::cout << "GameSystem::update" << std::endl;
        // auto e = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][0];
        // auto comp = (*e)[Component::Type::SPRITE];
        i++;
        if (i == 100) {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            std::shared_ptr<Position> component = std::make_shared<Position>(500, 100);
            std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
            entity->addComponent(component).addComponent(component4);
            sceneManager.getCurrentScene().addEntity(entity);
        } else if (i == 200) {
            sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]);
        }*/

        //Check if there is any bonus
        for (auto &bonus : sceneManager.getCurrentScene()[IEntity::Tags::BONUS]) {
            auto comp = Component::castComponent<Bonus>((*bonus)[IComponent::Type::BONUS]);
            std::cout << "Bonuuuuuuuss !!!!!" << std::endl;
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
        /*std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();*/
        std::shared_ptr<Entity> bonus = std::make_shared<Entity>();
        /*std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");*/
        std::shared_ptr<Bonus> bonusComp = std::make_shared<Bonus>(Bonus::Type::BOMB);
        std::shared_ptr<Position> bonusPos = std::make_shared<Position>(10, 10);

        //component2->setType(Component::Type::TEXT);
        //component3->setType(Component::Type::HITBOX);
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        bonus->addComponent(bonusComp).addComponent(bonusPos);
        /*entity2->addComponent(component)
            .addComponent(component4);
        entity->addComponent(component2)
            .addComponent(component3);*/

        scene->addEntities({/*entity, entity2*/bonus});
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