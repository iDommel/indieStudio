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
#include "AudioDevice.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "Model3D.hpp"
#include "Grid.hpp"
#include "CameraComponent.hpp"
#include "raylib.h"
#include "Position.hpp"
#include "Window.hpp"


#include <raylib.h>

static int vol = 50;

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.addScene(createMainMenu(), SceneManager::SceneType::MAIN_MENU);
        sceneManager.addScene(createSoundMenu(), SceneManager::SceneType::SOUND);
        sceneManager.addScene(createHelpMenu(), SceneManager::SceneType::HELP);
        sceneManager.addScene(createControllerMenu(), SceneManager::SceneType::CONTROLLER);
        sceneManager.setCurrentScene(SceneManager::SceneType::GAME);
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t)
    {
        // static int i = 0;
        // static int j = 0;

        // i++;
        // if (i % 3 == 0) {
        //     auto components = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]->getFilteredComponents({ IComponent::Type::RECT });
        //     auto r = Component::castComponent<Rect>(components[0]);
        //     r->left = r->width * j;
        //     if (++j > 5)
        //         j = 0;
        // }
        // if (i == 100) {
        //     std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        //     std::shared_ptr<Position> component = std::make_shared<Position>(500, 100);
        //     std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png", 0, 0);
        //     entity->addComponent(component).addComponent(component4);
        //     sceneManager.getCurrentScene().addEntity(entity);
        // } else if (i == 200) {
        //     sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][2]);
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

        entity->addComponent(component2)
            .addComponent(component);
        
        return (entity);
    }

    std::shared_ptr<Entity> GameSystem::createText(std::string text, Position position, float fontSize)
    {
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<String> component = std::make_shared<String>(text, "", fontSize);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(position);

        entity->addComponent(component2)
            .addComponent(component);
        
        return (entity);
    }

    void GameSystem::createSceneEvent(std::shared_ptr<Entity> &entity, SceneManager::SceneType scenetype)
    {
        MouseCallbacks mouseCallbacks(
            [scenetype, entity](SceneManager &sceneManger, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
                auto pos = Component::castComponent<Position>(comp[1]);
                auto sprite = Component::castComponent<Sprite>(comp[0]);

                if (mousePosition.x > pos->getAbscissa() && mousePosition.x < pos->getAbscissa() + sprite->getX() &&
                    mousePosition.y > pos->getOrdinate() && mousePosition.y < pos->getOrdinate() + sprite->getY()) {
                    if (vol < 100 && scenetype == SceneManager::SceneType::PLUS) {
                        AudioDevice::setVolume(vol + 10);
                        vol += 10;
                        std::cout << "volume is set at: " << vol << std::endl;
                    } else if (vol > 0 && scenetype == SceneManager::SceneType::MINUS) {
                        AudioDevice::setVolume(vol - 10);
                        vol -= 10;
                        std::cout << "volume is set at: " << vol << std::endl;
                    } else 
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

    // void GameSystem::createBindingsEvent(std::shared_ptr<Entity> &entity)
    // {
    //     MouseCallbacks mouseCallbacks(
    //         [entity](SceneManager &sceneManger, Vector2 mousePosition) {
    //             auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR });
    //             auto pos = Component::castComponent<Position>(comp[1]);
    //             auto sprite = Component::castComponent<Sprite>(comp[0]);

    //             if (mousePosition.x > pos->getAbscissa() && mousePosition.x < pos->getAbscissa() + sprite->getX() &&
    //                 mousePosition.y > pos->getOrdinate() && mousePosition.y < pos->getOrdinate() + sprite->getY()) {
    //                 while (GetKeyPressed() == 0) {
    //                     if (GetKeyPressed() == KEY_ENTER) {
    //                         std::cout << "bindings" << std::endl;
    //                         break;
    //                     }
    //                 }
    //             }
    //         },
    //         [](SceneManager &, Vector2 mousePosition) {},
    //         [](SceneManager &, Vector2 mousePosition) {},
    //         [](SceneManager &, Vector2 mousePosition) {});
        
    //     std::shared_ptr<EventListener> eventListener = std::make_shared<EventListener>();

    //     eventListener->addMouseEvent(MOUSE_BUTTON_LEFT, mouseCallbacks);
        
    //     entity->addComponent(eventListener);
    // }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        ButtonCallbacks spaceCallbacks(
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1),
            [](SceneManager &scenemanager) {
                scenemanager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
                std::cout << "---------- space released" << std::endl;
            },
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1));

        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png", 0, 0);

        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 0, 0);
        std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png", 0, 0, 6);

        std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");

        std::shared_ptr<Entity> cam = std::make_shared<Entity>();
        Vector3 camPos = {50.0f, 50.0f, 50.0f};
        Vector3 camTarget = {0.0f, 10.0f, 0.0f};
        std::shared_ptr<CameraComponent> camera = std::make_shared<CameraComponent>(camTarget, camPos);

        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos3 = std::make_shared<Position>(10, 0, 0);
        std::shared_ptr<String> text = std::make_shared<String>("Coucou");

        std::shared_ptr<Entity> e4 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos4 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 1.0f);

        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        entity2->addComponent(component)
            .addComponent(component4)
            .addComponent(listener);

        e->addComponent(rect)
            .addComponent(pos)
            .addComponent(sprite);

        e2->addComponent(pos2)
            .addComponent(model);

        cam->addComponent(camera);

        e3->addComponent(pos3)
            .addComponent(text);

        e4->addComponent(grid);

        scene->addEntities({entity2, e, cam, e4, e2});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createMainMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png", 800, 600);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - component->getX() / 2, 600 / 2 - component->getY() / 2);

        entity1->addComponent(component2)
            .addComponent(component);

        scene->addEntity(entity1);
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/play_unpressed.png", Position(800 / 2 - 60, 500 / 2 - 18), 120, 36);
        std::shared_ptr<Entity> entity3 = createButton("assets/MainMenu/sound.png", Position(800 - 80, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity4 = createButton("assets/MainMenu/controller.png", Position(0, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity5 = createButton("assets/MainMenu/help.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity6 = createButton("assets/MainMenu/quit_unpressed.png", Position(800 / 2 - 60, 700 / 2 - 18), 120, 36);

        createSceneEvent(entity2, SceneManager::SceneType::GAME);
        createSceneEvent(entity3, SceneManager::SceneType::SOUND);
        createSceneEvent(entity4, SceneManager::SceneType::CONTROLLER);
        createSceneEvent(entity5, SceneManager::SceneType::HELP);
        createSceneEvent(entity6, SceneManager::SceneType::NONE);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createSoundMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createSoundMenu, this));
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity3 = createButton("assets/MainMenu/minus.png", Position(220, 250), 80, 80);
        std::shared_ptr<Entity> entity4 = createButton("assets/MainMenu/plus.png", Position(500, 250), 80, 80);
        std::shared_ptr<Entity> entity5 = createText("Sound Menu", Position(250, 50), 50);
        std::shared_ptr<Entity> entity6 = createText("Master Volume", Position(300, 200), 25);

        createSceneEvent(entity2, SceneManager::SceneType::MAIN_MENU);
        createSceneEvent(entity3, SceneManager::SceneType::MINUS);
        createSceneEvent(entity4, SceneManager::SceneType::PLUS);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createHelpMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createHelpMenu, this));
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity3 = createText("How to play", Position(250, 50), 50);

        std::shared_ptr<Entity> entity4 = createText("Welcome in our game: Boomberman made by Indie Studio.", Position(10, 150), 25);

        std::shared_ptr<Entity> entity5 = createText("You will be able to plant water bombs to destroy destructible\nblocks and maybe get some boosts.", Position(10, 250), 25);
        std::shared_ptr<Entity> entity6 = createText("If your bombs hit an opponent you will kill him.\nThe goal is to be the last man standing.", Position(10, 350), 25);

        createSceneEvent(entity2, SceneManager::SceneType::MAIN_MENU);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createControllerMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createControllerMenu, this));
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity3 = createText("Controller Menu", Position(200, 50), 50);
        std::shared_ptr<Entity> entity4 = createText("Player 1", Position(50, 150), 25);
        std::shared_ptr<Entity> entity5 = createText("Player 2", Position(500, 150), 25);
        std::shared_ptr<Entity> entity6 = createText("Player 3", Position(50, 400), 25);
        std::shared_ptr<Entity> entity7 = createText("Player 4", Position(500, 400), 25);
        std::shared_ptr<Entity> entity8 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(10, 200), 20);
        std::shared_ptr<Entity> entity12 = createText("A", Position(50, 200), 20);
        std::shared_ptr<Entity> entity9 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(10, 450), 20);
        std::shared_ptr<Entity> entity10 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(500, 200), 20);
        std::shared_ptr<Entity> entity11 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(500, 450), 20);

        createSceneEvent(entity2, SceneManager::SceneType::MAIN_MENU);
        // createBindingsEvent(entity12);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6, entity7});
        scene->addEntities({entity8, entity9, entity10, entity11, entity12});
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