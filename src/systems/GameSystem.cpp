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
#include "../components/String.hpp"
#include "Bomb.hpp"

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
        std::vector<std::shared_ptr<indie::IComponent>> components;

        std::cout << "GameSystem::update" << std::endl;

        for (auto &bomb : _bombs) {
            components = bomb->getComponents();
            for (auto &component : components) {
                if (component->getType() == IComponent::Type::BOMB) {
                    auto bombComponent = Component::castComponent<Bomb>(component);
                    bombComponent->setTimer(bombComponent->getTimer() - deltaTime);
                    if (bombComponent->getTimer() <= 0) {
                        bombComponent->explode();
                    }
                }
            }
        }
        // sceneManager.getCurrentScene().addEntity(std::make_shared<Entity>());
        auto e = sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_2D][0];
        auto comp = (*e)[Component::Type::SPRITE];
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

        entity2->addComponent(component)
            .addComponent(component4);

        entity->addComponent(component2)
            .addComponent(component3);

        scene->addEntities({entity, entity2});
        return scene;
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::BOMB))
            _bombs.push_back(entity);
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity>)
    {
    }

}