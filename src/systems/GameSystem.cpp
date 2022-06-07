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
        sceneManager.addScene(createSoundMenu(), SceneManager::SceneType::SOUND);
        sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        // int count = 0;
        // for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D]) {
        //     if (count == 0) {
        //         auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
        //         Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 333);
        //         Component::castComponent<Position>(components[1])->setOrdinate(Window::getScreenHeight() / 2 - 187);
        //     } else if (count == 1) {
        //         auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
        //         Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 60);
        //         Component::castComponent<Position>(components[1])->setOrdinate((Window::getScreenHeight() - 100) / 2 - 18);
        //     } else if (count == 2) {
        //         auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
        //         Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() - 80);
        //         Component::castComponent<Position>(components[1])->setOrdinate(Window::getScreenHeight() - 80);
        //     } else if (count == 3) {
        //         auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
        //         Component::castComponent<Position>(components[1])->setAbscissa(0);
        //         Component::castComponent<Position>(components[1])->setOrdinate(Window::getScreenHeight() - 80);
        //     } else if (count == 4) {
        //         auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
        //         Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 60);
        //         Component::castComponent<Position>(components[1])->setOrdinate((Window::getScreenHeight() + 100) / 2 - 18);
        //     }
        //     count++;
        // }

    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::shared_ptr<Entity> GameSystem::createButton(std::string path, Position position, int heigh, int width)
    {
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>(path, heigh, width);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(position);

        entity->addComponent(component)
            .addComponent(component2);
        
        return (entity);
    }

    void GameSystem::createEventListener(std::shared_ptr<Entity> &entity, SceneManager::SceneType scenetype)
    {
        MouseCallbacks mouseCallbacks(
            [scenetype, entity](SceneManager &sceneManger, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                auto pos = Component::castComponent<Position>(comp[1]);
                auto sprite = Component::castComponent<Sprite>(comp[0]);

                if (mousePosition.x > pos->getAbscissa() && mousePosition.x < pos->getAbscissa() + sprite->getX() &&
                    mousePosition.y > pos->getOrdinate() && mousePosition.y < pos->getOrdinate() + sprite->getY()) {
                    sceneManger.setCurrentScene(scenetype);
                }
            },
            [](SceneManager &, Vector2 mousePosition) {},
            [](SceneManager &, Vector2 mousePosition) {},
            [](SceneManager &, Vector2 mousePosition) {});
        
        std::shared_ptr<EventListener> eventListener = std::make_shared<EventListener>();

        eventListener->addMouseEvent(MOUSE_BUTTON_LEFT, mouseCallbacks);
        
        entity->addComponent(eventListener);
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
        std::shared_ptr<Sprite> component2 = std::make_shared<Sprite>("sprite", 0, 0);
        std::shared_ptr<Sprite> component3 = std::make_shared<Sprite>("vector", 0, 0);
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png", 0, 0);

        component2->setType(Component::Type::TEXT);
        component3->setType(Component::Type::HITBOX);
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        entity2->addComponent(component)
            .addComponent(component4);
        entity->addComponent(component2)
            .addComponent(component3);

        scene->addEntities({entity, entity2});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createMainMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png", 666, 374);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - component->getX() / 2, 600 / 2 - component->getY() / 2);

        entity1->addComponent(component)
            .addComponent(component2);
    
        scene->addEntity(entity1);
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/play_unpressed.png", Position(800 / 2 - 60, 500 / 2 - 18), 120, 36);
        std::shared_ptr<Entity> entity3 = createButton("assets/MainMenu/sound.png", Position(800 - 80, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity4 = createButton("assets/MainMenu/controller.png", Position(0, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity5 = createButton("assets/MainMenu/quit_unpressed.png", Position(800 / 2 - 60, 700 / 2 - 18), 120, 36);

        createEventListener(entity2, SceneManager::SceneType::GAME);
        createEventListener(entity3, SceneManager::SceneType::SOUND);
        createEventListener(entity4, SceneManager::SceneType::NONE);
        createEventListener(entity5, SceneManager::SceneType::NONE);
        scene->addEntity(entity2);
        scene->addEntity(entity3);
        scene->addEntity(entity4);
        scene->addEntity(entity5);
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createSoundMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createSoundMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png", 666, 374);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - component->getX() / 2, 600 / 2 - component->getY() / 2);

        entity1->addComponent(component)
            .addComponent(component2);
    
        scene->addEntity(entity1);
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/sound.png", Position(800 - 80, 600 - 80), 80, 80);
        scene->addEntity(entity2);
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