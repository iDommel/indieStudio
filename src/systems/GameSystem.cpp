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
#include "HitboxComponent.hpp"
#include "AudioDevice.hpp"
#include "Scene.hpp"
#include "String.hpp"
#include "Model3D.hpp"
#include "Grid.hpp"
#include "CameraComponent.hpp"
#include "ModelAnim.hpp"
#include "Window.hpp"
#include "raylib.h"
#include "Position.hpp"
#include "Window.hpp"

namespace indie
{

    void GameSystem::init(indie::SceneManager &sceneManager)
    {
        std::cout << "GameSystem::init" << std::endl;

        sceneManager.addScene(createScene(), SceneManager::SceneType::GAME);
        sceneManager.addScene(createSplashScreen(), SceneManager::SceneType::SPLASH);
        sceneManager.addScene(createMainMenu(), SceneManager::SceneType::MAIN_MENU);
        sceneManager.addScene(createSoundMenu(), SceneManager::SceneType::SOUND);
        sceneManager.addScene(createHelpMenu(), SceneManager::SceneType::HELP);
        sceneManager.addScene(createControllerMenu(), SceneManager::SceneType::CONTROLLER);
        sceneManager.setCurrentScene(SceneManager::SceneType::SPLASH);
        AudioDevice::getMasterVolume() += 50;
    }

    void GameSystem::replaceTextBindings(indie::SceneManager &sceneManager, std::shared_ptr<Player> players, int firstText)
    {
        if (SceneManager::getCurrentSceneType() == SceneManager::SceneType::CONTROLLER) {
            if (players->changeUp == 2 || players->changeUp == 0) {
                auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText];
                auto text = components->getFilteredComponents({ IComponent::Type::TEXT});
                auto value = Component::castComponent<String>(text[0]);
                value->getValue() = players->getUp();
                players->changeUp = 0;
            }
            if (players->changeLeft == 2 || players->changeLeft == 0) {
                auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 1];
                auto text = components->getFilteredComponents({ IComponent::Type::TEXT});
                auto value = Component::castComponent<String>(text[0]);
                value->getValue() = players->getLeft();
                players->changeLeft = 0;
            } 
            if (players->changeRight == 2 || players->changeRight == 0) {
                auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 2];
                auto text = components->getFilteredComponents({ IComponent::Type::TEXT});
                auto value = Component::castComponent<String>(text[0]);
                value->getValue() = players->getRight();
                players->changeRight = 0;
            }
            if (players->changeDown == 2 || players->changeDown == 0) {
                auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 3];
                auto text = components->getFilteredComponents({ IComponent::Type::TEXT});
                auto value = Component::castComponent<String>(text[0]);
                value->getValue() = players->getDown();
                players->changeDown = 0;
            }
        }
    }
    
    void GameSystem::updateTextBindings(indie::SceneManager &sceneManager, std::shared_ptr<Player> players, int firstText)
    {
        if (players->changeUp == 1) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText];
            auto test = components->getFilteredComponents({ IComponent::Type::TEXT});
            auto text = Component::castComponent<String>(test[0]);
            text->getValue() = "|";
        } else if (players->changeLeft == 1) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 1];
            auto test = components->getFilteredComponents({ IComponent::Type::TEXT});
            auto text = Component::castComponent<String>(test[0]);
            text->getValue() = "|";
        } else if (players->changeRight == 1) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 2];
            auto test = components->getFilteredComponents({ IComponent::Type::TEXT});
            auto text = Component::castComponent<String>(test[0]);
            text->getValue() = "|";
        } else if (players->changeDown == 1) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::TEXT][firstText + 3];
            auto test = components->getFilteredComponents({ IComponent::Type::TEXT});
            auto text = Component::castComponent<String>(test[0]);
            text->getValue() = "|";
        }
    }

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t delta)
    {
        int firstText = 9;
        for (auto &scene : sceneManager.getScenes()) {
            for (auto &e : (*scene.second)[IEntity::Tags::PLAYER]) {
                auto players = Component::castComponent<Player>(e->getFilteredComponents({ IComponent::Type::PLAYER })[0]);
                updateTextBindings(sceneManager, players, firstText);
                replaceTextBindings(sceneManager, players, firstText);
                firstText += 4;
            }
        }
        if (sceneManager.getCurrentSceneType() == SceneManager::SceneType::SPLASH) {
            timeElasped += delta;
            if (timeElasped > 3000) {
                sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
            }
        }
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
        //     std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
        //     entity->addComponent(component).addComponent(component4);
        //     sceneManager.getCurrentScene().addEntity(entity);
        // } else if (i == 200) {
        //     sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][2]);
        // }
        // auto component = Component::castComponent<ModelAnim>((*sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D][0])[IComponent::Type::ANIMATION]);
        // component->getCurrentFrame()++;
        // if (component->getCurrentFrame() >= component->getNbFrames())
        //     component->getCurrentFrame() = 0;
    }

    std::unique_ptr<IScene> GameSystem::createSplashScreen()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createSplashScreen, this));

        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Position> pos = std::make_shared<Position>(550, 350);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/raylib_logo.png");

        entity->addComponent(pos)
            .addComponent(sprite);

        std::shared_ptr<Entity> entity2 = createText("Super Bomberman", Position(200, 50), 50);
        std::shared_ptr<Entity> entity3 = createText("Made by Indie Studio", Position(250, 100), 30);
        std::shared_ptr<Entity> entity4 = createText("Iona Dommel-Prioux\nAntoine Penot\nCamille Maux\nIzaac Carcenac-Sautron\nLéo Maman\nMaxence Folio\nRoxanne Baert", Position(10, 450), 15);

        scene->addEntities({entity, entity2, entity3, entity4});
        return scene;
    }

    void GameSystem::destroy()
    {
        std::cout << "GameSystem::destroy" << std::endl;
    }

    std::shared_ptr<Entity> GameSystem::createButton(std::string path, Position position, int heigh, int width)
    {
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>(path);
        std::shared_ptr<Position> component2 = std::make_shared<Position>(position);
        std::shared_ptr<Rect> component3 = std::make_shared<Rect>(0, 0, heigh, width);

        entity->addComponent(component2)
            .addComponent(component)
            .addComponent(component3);
        
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

    void GameSystem::createSoundEvent(std::shared_ptr<Entity> &entity, std::string value) {
        MouseCallbacks mouseCallbacks(
            [value, entity](SceneManager &sceneManger, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR , IComponent::Type::RECT});
                auto pos = Component::castComponent<Position>(comp[1]);
                auto sprite = Component::castComponent<Sprite>(comp[0]);
                auto rect = Component::castComponent<Rect>(comp[2]);

                if (mousePosition.x > pos->x && mousePosition.x < pos->x + rect->width &&
                    mousePosition.y > pos->y && mousePosition.y < pos->y + rect->height) {
                    auto comp2 = sceneManger.getCurrentScene()[IEntity::Tags::TEXT][2];
                    auto text = comp2->getFilteredComponents({ IComponent::Type::TEXT });
                    auto value2 = Component::castComponent<String>(text[0]);
                    if (AudioDevice::getMasterVolume() < 100 && value == "+") {
                        AudioDevice::getMasterVolume() += 10;
                        AudioDevice::setVolume(AudioDevice::getMasterVolume());
                        value2->getValue() = std::to_string(AudioDevice::getMasterVolume());
                    } else if (AudioDevice::getMasterVolume()  > 0 && value == "-") {
                        AudioDevice::getMasterVolume() -= 10;
                        AudioDevice::setVolume(AudioDevice::getMasterVolume() );
                        value2->getValue() = std::to_string(AudioDevice::getMasterVolume());
                    }
                }
            },
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {});

        std::shared_ptr<EventListener> eventListener = std::make_shared<EventListener>();

        eventListener->addMouseEvent(MOUSE_BUTTON_LEFT, mouseCallbacks);

        entity->addComponent(eventListener);
    }

    void GameSystem::createSceneEvent(std::shared_ptr<Entity> &entity, SceneManager::SceneType scenetype)
    {
        MouseCallbacks mouseCallbacks(
            [scenetype, entity](SceneManager &sceneManger, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::VECTOR , IComponent::Type::RECT});
                auto pos = Component::castComponent<Position>(comp[1]);
                auto sprite = Component::castComponent<Sprite>(comp[0]);
                auto rect = Component::castComponent<Rect>(comp[2]);

                if (mousePosition.x > pos->x && mousePosition.x < pos->x + rect->width &&
                    mousePosition.y > pos->y && mousePosition.y < pos->y + rect->height) {
                    sceneManger.setCurrentScene(scenetype);
                }
            },
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {});

        std::shared_ptr<EventListener> eventListener = std::make_shared<EventListener>();

        eventListener->addMouseEvent(MOUSE_BUTTON_LEFT, mouseCallbacks);

        entity->addComponent(eventListener);
    }

    void GameSystem::createBindingsEvent(std::shared_ptr<Entity> &entity, int id_player, int button)
    {
        MouseCallbacks mouseCallbacks(
            [entity, button, id_player](SceneManager &sceneManager, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::VECTOR });
                auto pos = Component::castComponent<Position>(comp[0]);

                if (mousePosition.x > pos->x && mousePosition.x < pos->x + 50 &&
                    mousePosition.y > pos->y && mousePosition.y < pos->y + 20) {
                    auto entity = sceneManager.getCurrentScene()[IEntity::Tags::PLAYER][id_player];
                    auto component = entity->getFilteredComponents({ IComponent::Type::PLAYER});
                    auto player = Component::castComponent<Player>(component[0]);
                    switch (button) {
                        case 0:
                            player->changeUp = 1;
                            player->changeDown = 0;
                            player->changeLeft = 0;
                            player->changeRight = 0;
                            break;
                        case 1:
                            player->changeLeft = 1;
                            player->changeDown = 0;
                            player->changeRight = 0;
                            player->changeUp = 0;
                            break;
                        case 2:
                            player->changeRight = 1;
                            player->changeDown = 0;
                            player->changeLeft = 0;
                            player->changeUp = 0;
                            break;
                        case 3:
                            player->changeDown = 1;
                            player->changeLeft = 0;
                            player->changeRight = 0;
                            player->changeUp = 0;
                            break;
                    }
                }
            },
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [entity, button, id_player](SceneManager &sceneManager, Vector2 /*mousePosition*/) {
                auto component = sceneManager.getCurrentScene()[IEntity::Tags::PLAYER][id_player];
                auto comp = component->getFilteredComponents({ IComponent::Type::PLAYER});
                auto player = Component::castComponent<Player>(comp[0]);
                std::string get = "";
                char input = 0;

                if (player->changeUp == true) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setUP(get);
                        player->changeUp = 2;
                    }
                } else if (player->changeLeft == true) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setLEFT(get);
                        player->changeLeft = 2;
                    }
                } else if (player->changeRight == true) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setRIGHT(get);
                        player->changeRight = 2;
                    }
                } else if (player->changeDown == true) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setDOWN(get);
                        player->changeDown = 2;
                    }
                }
            });

        std::shared_ptr<EventListener> eventListener = std::make_shared<EventListener>();

        eventListener->addMouseEvent(MOUSE_BUTTON_LEFT, mouseCallbacks);
        
        entity->addComponent(eventListener);
    }

    // std::unique_ptr<indie::IScene> GameSystem::createScene()
    // {
    //     ButtonCallbacks spaceCallbacks(
    //         std::bind(&GameSystem::printStuff, this, std::placeholders::_1),
    //         [](SceneManager &scenemanager) {
    //             scenemanager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
    //             std::cout << "---------- space released" << std::endl;
    //         },
    //         std::bind(&GameSystem::printStuff, this, std::placeholders::_1));

    //     std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
    //     std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
    //     std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
    //     std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
    //     std::shared_ptr<Rect> component5 = std::make_shared<Rect>(0, 0, 250, 250);
    //     std::shared_ptr<Component> component3 = std::make_shared<Component>();

    //     std::shared_ptr<Entity> e = std::make_shared<Entity>();
    //     std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 0, 0);
    //     std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
    //     std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png", 6);

    //     std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
    //     std::shared_ptr<Position> pos2 = std::make_shared<Position>(0, 0, 0);
    //     std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");

    //     std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
    //     listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);
    //     component3->setType(Component::Type::HITBOX);

    //     entity2->addComponent(component)
    //         .addComponent(component4)
    //         .addComponent(component3)
    //         .addComponent(component5)
    //         .addComponent(listener);

    //     e->addComponent(rect)
    //         .addComponent(pos)
    //         .addComponent(sprite);

    //     e2->addComponent(pos2)
    //         .addComponent(model);
    // }

    std::shared_ptr<IEntity> GameSystem::createCamera(Vector3 camPos, Vector3 camTarget)
    {
        std::shared_ptr<Entity> cam = std::make_shared<Entity>();
        std::shared_ptr<CameraComponent> camera = std::make_shared<CameraComponent>(camTarget, camPos);

        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos3 = std::make_shared<Position>(10, 0, 0);
        std::shared_ptr<String> text = std::make_shared<String>("The below sprite entity has a hitbox of 250,250");

        std::shared_ptr<Entity> e4 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos4 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 1.0f);

        cam->addComponent(camera);
        return cam;
    }

    std::unique_ptr<indie::IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));
        Vector3 camPos = {GAME_MAP_WIDTH * GAME_TILE_SIZE / 4 * 3, 200.0f, GAME_MAP_HEIGHT * GAME_TILE_SIZE + 50};
        Vector3 camTarget = {GAME_MAP_WIDTH * GAME_TILE_SIZE / 2, 0.0f, GAME_MAP_HEIGHT * GAME_TILE_SIZE / 2};

        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos3 = std::make_shared<Position>(10, 0, 0);
        std::shared_ptr<String> text = std::make_shared<String>("The below sprite entity has a hitbox of 250,250");

        std::shared_ptr<Entity> e4 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos4 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 1.0f);

        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 0, 0);
        std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png", 6);

        std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");

        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
        std::shared_ptr<Rect> component5 = std::make_shared<Rect>(0, 0, 250, 250);


        scene->addEntities({entity2, e, e4, e2, e3});
        scene->addEntities({createCamera(camPos,camTarget)});
        generateMap("assets/maps/map2.txt", *scene);
        return scene;
    }

    std::unique_ptr<indie::IScene> GameSystem::createMainMenu()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createMainMenu, this));
        std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        std::shared_ptr<Sprite> component = std::make_shared<Sprite>("assets/MainMenu/menu.png");
        std::shared_ptr<Position> component2 = std::make_shared<Position>(800 / 2 - 400, 600 / 2 - 300);

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
        std::shared_ptr<Entity> entity7 = createText("50", Position(370, 250), 80);

        createSceneEvent(entity2, SceneManager::SceneType::MAIN_MENU);
        createSoundEvent(entity3, "-");
        createSoundEvent(entity4, "+");

        scene->addEntities({entity2, entity3, entity4, entity5, entity6 ,entity7});
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
        std::shared_ptr<Entity> entity9 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(10, 450), 20);
        std::shared_ptr<Entity> entity10 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(500, 200), 20);
        std::shared_ptr<Entity> entity11 = createText("UP:\nLEFT:\nRIGHT:\nDOWN:", Position(500, 450), 20);


        std::shared_ptr<Player> player = std::make_shared<Player>("Z", "S", "Q", "D");
        std::shared_ptr<Entity> entity16 = std::make_shared<Entity>();

        entity16->addComponent(player);

        std::shared_ptr<Player> player2 = std::make_shared<Player>("I", "J", "K", "L");
        std::shared_ptr<Entity> entity17 = std::make_shared<Entity>();

        entity17->addComponent(player2);

        std::shared_ptr<Entity> entity12 = createText(player->getUp(), Position(100, 200), 20);
        std::shared_ptr<Entity> entity13 = createText(player->getLeft(), Position(100, 230), 20);
        std::shared_ptr<Entity> entity14 = createText(player->getRight(), Position(100, 260), 20);
        std::shared_ptr<Entity> entity15 = createText(player->getDown(), Position(100, 290), 20);
        std::shared_ptr<Entity> entity18 = createText(player2->getUp(), Position(600, 200), 20);
        std::shared_ptr<Entity> entity19 = createText(player2->getLeft(), Position(600, 230), 20);
        std::shared_ptr<Entity> entity20 = createText(player2->getRight(), Position(600, 260), 20);
        std::shared_ptr<Entity> entity21 = createText(player2->getDown(), Position(600, 290), 20);

        createSceneEvent(entity2, SceneManager::SceneType::MAIN_MENU);
        createBindingsEvent(entity12, 0, 0);
        createBindingsEvent(entity13, 0, 1);
        createBindingsEvent(entity14, 0, 2);
        createBindingsEvent(entity15, 0, 3);
        createBindingsEvent(entity18, 1, 0);
        createBindingsEvent(entity19, 1, 1);
        createBindingsEvent(entity20, 1, 2);
        createBindingsEvent(entity21, 1, 3);

        scene->addEntities({entity2, entity3, entity4, entity5, entity6, entity7});
        scene->addEntities({entity8, entity9, entity10, entity11});
        scene->addEntities({entity12, entity13, entity14, entity15, entity16, entity17, entity18, entity19, entity20, entity21});
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