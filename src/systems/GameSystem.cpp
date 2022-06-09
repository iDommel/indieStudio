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

static float vol = 50;

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
        sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
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

    void GameSystem::createEventListener(std::shared_ptr<Entity> &entity, SceneManager::SceneType scenetype)
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

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        ButtonCallbacks spaceCallbacks(
            std::bind(&GameSystem::printStuff, this, std::placeholders::_1),
            [](SceneManager &scenemanager) {
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

        scene->addEntities({entity2, e, e2, cam, e3, e4});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createMainMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png", 666, 374);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - component->getX() / 2, 600 / 2 - component->getY() / 2);

        entity1->addComponent(component2)
            .addComponent(component);

        scene->addEntity(entity1);
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/play_unpressed.png", Position(800 / 2 - 60, 500 / 2 - 18), 120, 36);
        std::shared_ptr<Entity> entity3 = createButton("assets/MainMenu/sound.png", Position(800 - 80, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity4 = createButton("assets/MainMenu/controller.png", Position(0, 600 - 80), 80, 80);
        std::shared_ptr<Entity> entity5 = createButton("assets/MainMenu/help.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity6 = createButton("assets/MainMenu/quit_unpressed.png", Position(800 / 2 - 60, 700 / 2 - 18), 120, 36);

        createEventListener(entity2, SceneManager::SceneType::GAME);
        createEventListener(entity3, SceneManager::SceneType::SOUND);
        createEventListener(entity4, SceneManager::SceneType::CONTROLLER);
        createEventListener(entity5, SceneManager::SceneType::HELP);
        createEventListener(entity6, SceneManager::SceneType::NONE);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6});
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createSoundMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createSoundMenu, this));

        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);
        std::shared_ptr<Entity> entity3 = createButton("assets/MainMenu/minus.png", Position(250, 150), 80, 80);
        std::shared_ptr<Entity> entity4 = createButton("assets/MainMenu/plus.png", Position(500, 150), 80, 80);

        createEventListener(entity2, SceneManager::SceneType::MAIN_MENU);
        createEventListener(entity3, SceneManager::SceneType::MINUS);
        createEventListener(entity4, SceneManager::SceneType::PLUS);

        scene->addEntity(entity2);
        scene->addEntity(entity3);
        scene->addEntity(entity4);
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createHelpMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createHelpMenu, this));
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);

        createEventListener(entity2, SceneManager::SceneType::MAIN_MENU);

        scene->addEntity(entity2);
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createControllerMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createControllerMenu, this));
        std::shared_ptr<Entity> entity2 = createButton("assets/MainMenu/fleche.png", Position(0, 0), 80, 80);

        createEventListener(entity2, SceneManager::SceneType::MAIN_MENU);

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