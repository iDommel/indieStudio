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
        sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        int count = 0;
        // std::cout << "GameSystem::update" << std::endl;
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D]) {
            if (count == 0) {
                auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 333);
                Component::castComponent<Position>(components[1])->setOrdinate(Window::getScreenHeight() / 2 - 187);
            } else if (count == 1) {
                auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 60);
                Component::castComponent<Position>(components[1])->setOrdinate((Window::getScreenHeight() - 100) / 2 - 18);
            } else if (count == 2) {
                auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 60);
                Component::castComponent<Position>(components[1])->setOrdinate(Window::getScreenHeight() / 2 - 18);
            } else if (count == 3) {
                auto components = e->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                Component::castComponent<Position>(components[1])->setAbscissa(Window::getScreenWidth() / 2 - 60);
                Component::castComponent<Position>(components[1])->setOrdinate((Window::getScreenHeight() + 100) / 2 - 18);
            }
            count++;
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
        std::shared_ptr<Sprite> component2 = std::make_shared<Sprite>("sprite");
        std::shared_ptr<Sprite> component3 = std::make_shared<Sprite>("vector");
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");

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
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png");
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - 333, 600 / 2 - 187);

        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component3 = std::make_shared<Sprite>("assets/MainMenu/play_unpressed.png");
        std::shared_ptr<Position> component4 = std::make_shared<Position>(800 / 2 - 60, 500 / 2 - 18);
        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();

        listener->addMouseEvent(MOUSE_BUTTON_LEFT, MouseCallbacks(
            [](SceneManager &sceneManager, Vector2 mousePosition) {
                if (mousePosition.x < 800 / 2 + 60 && mousePosition.x > 800 / 2 - 60 &&
                    mousePosition.y < 500 / 2 + 18 && mousePosition.y > 500 / 2 - 18) {
                    sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
                }
            },
            [](SceneManager &, Vector2 mousePosition) {
                
                // std::cout << "---------- mouse released" << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            }));

        std::shared_ptr<Entity> entity3 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component5 = std::make_shared<Sprite>("assets/MainMenu/option_unpressed.png");
        std::shared_ptr<Position> component6 = std::make_shared<Position>(800 / 2 - 60, 600 / 2 - 18);
        std::shared_ptr<EventListener> listener2 = std::make_shared<EventListener>();

        listener2->addMouseEvent(MOUSE_BUTTON_LEFT, MouseCallbacks(
            [](SceneManager &sceneManager, Vector2 mousePosition) {
                if (mousePosition.x < 800 / 2 + 60 && mousePosition.x > 800 / 2 - 60 &&
                    mousePosition.y < 600 / 2 + 18 && mousePosition.y > 600 / 2 - 18) {
                    sceneManager.setCurrentScene(SceneManager::SceneType::OPTION);
                }
            },
            [](SceneManager &, Vector2 mousePosition) {
                
                // std::cout << "---------- mouse released" << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            }));

        std::shared_ptr<Entity> entity4 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component7 = std::make_shared<Sprite>("assets/MainMenu/quit_unpressed.png");
        std::shared_ptr<Position> component8 = std::make_shared<Position>(800 / 2 - 60, 700 / 2 - 18);
        std::shared_ptr<EventListener> listener3 = std::make_shared<EventListener>();

        listener3->addMouseEvent(MOUSE_BUTTON_LEFT, MouseCallbacks(
            [](SceneManager &sceneManager, Vector2 mousePosition) {
                if (mousePosition.x < 800 / 2 + 60 && mousePosition.x > 800 / 2 - 60 &&
                    mousePosition.y < 700 / 2 + 18 && mousePosition.y > 700 / 2 - 18) {
                    sceneManager.setCurrentScene(SceneManager::SceneType::NONE);
                }
            },
            [](SceneManager &, Vector2 mousePosition) {
                
                // std::cout << "---------- mouse released" << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            },
            [](SceneManager &, Vector2 mousePosition) {
                // std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
            }));

        entity1->addComponent(component)
            .addComponent(component2);
        entity2->addComponent(component3)
            .addComponent(component4)
            .addComponent(listener);
        entity3->addComponent(component5)
            .addComponent(component6)
            .addComponent(listener2);
        entity4->addComponent(component7)
            .addComponent(component8)
            .addComponent(listener3);
    
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

    void GameSystem::printStuff(SceneManager &)
    {
        std::cout << "GameSystem::printStuff" << std::endl;
    }
}