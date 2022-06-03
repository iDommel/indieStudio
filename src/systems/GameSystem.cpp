/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>
#include <raylib.h>

#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "String.hpp"
#include "Bomb.hpp"
#include "Player.hpp"

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t deltaTime)
    {
        std::cout << "GameSystem::update" << std::endl;

        for (auto &bomb : sceneManager.getCurrentScene()[IEntity::Tags::BOMB]) {
            auto comp = Component::castComponent<Bomb>((*bomb)[IComponent::Type::BOMB]);
            comp->setTimer(comp->getTimer() - deltaTime);
            if (comp->getTimer() <= 0) {
                comp->explode();
            }
        }

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
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1),
            [](SceneManager &) {
                std::cout << "---------- space released" << std::endl;
            },
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1));

        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<String> component = std::make_shared<String>("audio");
        std::shared_ptr<String> component2 = std::make_shared<String>("sprite");
        std::shared_ptr<String> component3 = std::make_shared<String>("vector");
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        std::shared_ptr<Entity> player1 = std::make_shared<Entity>();
        std::shared_ptr<Player> playerComp = std::make_shared<Player>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
        component->setType(Component::Type::SOUND);
        component2->setType(Component::Type::SPRITE);
        component3->setType(Component::Type::VECTOR);

        player1->addComponent(playerComp);
        entity2->addComponent(component)
            .addComponent(listener);
        entity->addComponent(component2)
            .addComponent(component3);

        scene->addEntities({entity, entity2, player1});
        return scene;
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity> entity)
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