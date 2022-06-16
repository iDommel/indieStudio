/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.cpp
*/

#include "GameSystem.hpp"

#include <functional>
#include <iostream>

#include "CameraComponent.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "EventListener.hpp"
#include "Grid.hpp"
#include "HitboxComponent.hpp"
#include "AudioDevice.hpp"
#include "Model3D.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include "Rect.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "String.hpp"
#include "Velocity.hpp"
#include "ModelAnim.hpp"
#include "Window.hpp"
#include "raylib.h"

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
        _collideSystem.init(sceneManager);
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

    void GameSystem::update(indie::SceneManager &sceneManager, uint64_t dt)
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
            timeElasped += dt;
            if (timeElasped > 3000) {
                sceneManager.setCurrentScene(SceneManager::SceneType::MAIN_MENU);
            }
        }
        static int i = 0;

        i++;
        updatePlayers(sceneManager, dt);
        _collideSystem.update(sceneManager, dt);
        auto renderables = sceneManager.getCurrentScene()[IEntity::Tags::RENDERABLE_3D];
        for (auto &renderable : renderables) {
            if (renderable->hasComponent({IComponent::Type::ANIMATION})) {
                auto component = Component::castComponent<ModelAnim>((*renderable)[IComponent::Type::ANIMATION]);
                component->getCurrentFrame()++;
                if (component->getCurrentFrame() >= component->getNbFrames())
                    component->getCurrentFrame() = 0;
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
        _collideSystem.destroy();
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
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::POSITION , IComponent::Type::RECT});
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
                auto comp = entity->getFilteredComponents({ IComponent::Type::SPRITE, IComponent::Type::POSITION , IComponent::Type::RECT});
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
            [entity, button, id_player, this](SceneManager &sceneManager, Vector2 mousePosition) {
                auto comp = entity->getFilteredComponents({ IComponent::Type::POSITION });
                auto pos = Component::castComponent<Position>(comp[0]);

                if (mousePosition.x > pos->x && mousePosition.x < pos->x + 50 &&
                    mousePosition.y > pos->y && mousePosition.y < pos->y + 20) {
                    changeBindings(sceneManager, id_player, button);
                }
            },
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [](SceneManager &, Vector2 /*mousePosition*/) {},
            [entity, button, id_player](SceneManager &sceneManager, Vector2 /*mousePosition*/) {
                auto component = sceneManager.getScene(SceneManager::SceneType::GAME)[IEntity::Tags::PLAYER][id_player];
                auto comp = component->getFilteredComponents({ IComponent::Type::PLAYER});
                auto player = Component::castComponent<Player>(comp[0]);
                std::string get = "";
                char input = 0;

                if (player->changeUp == 1) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setUP(get);
                        player->changeUp = 2;
                    }
                } else if (player->changeLeft == 1) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setLEFT(get);
                        player->changeLeft = 2;
                    }
                } else if (player->changeRight == 1) {
                    input = Window::getKeyPressed();
                    if (input != 0) {
                        get.assign(1, input);
                        player->setRIGHT(get);
                        player->changeRight = 2;
                    }
                } else if (player->changeDown == 1) {
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

    void GameSystem::updatePlayers(SceneManager &sceneManager, uint64_t dt)
    {
        auto players = sceneManager.getCurrentScene()[IEntity::Tags::PLAYER];
        for (auto &player : players) {
            auto pos = Component::castComponent<Position>((*player)[IComponent::Type::POSITION]);
            auto lastPos = *pos;
            auto vel = Component::castComponent<Velocity>((*player)[IComponent::Type::VELOCITY]);
            auto playerComp = Component::castComponent<Player>((*player)[IComponent::Type::PLAYER]);
            auto hitbox = Component::castComponent<Hitbox>((*player)[IComponent::Type::HITBOX]);

            (*pos) = *pos + (*vel * (float)(dt / 1000.0f));
            (*hitbox) += *vel * (float)(dt / 1000.0f);
            if (!_collideSystem.getColliders(player).empty()) {
                (*pos) = lastPos;
                (*hitbox) -= *vel * (float)(dt / 1000.0f);
            }
        }
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

        std::shared_ptr<Entity> entity12 = createText("", Position(100, 200), 20);
        std::shared_ptr<Entity> entity13 = createText("", Position(100, 230), 20);
        std::shared_ptr<Entity> entity14 = createText("", Position(100, 260), 20);
        std::shared_ptr<Entity> entity15 = createText("", Position(100, 290), 20);
        std::shared_ptr<Entity> entity18 = createText("", Position(600, 200), 20);
        std::shared_ptr<Entity> entity19 = createText("", Position(600, 230), 20);
        std::shared_ptr<Entity> entity20 = createText("", Position(600, 260), 20);
        std::shared_ptr<Entity> entity21 = createText("", Position(600, 290), 20);

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
        scene->addEntities({entity12, entity13, entity14, entity15, entity18, entity19, entity20, entity21});
        return scene;
    }

    std::unique_ptr<IScene> GameSystem::createScene()
    {
        std::unique_ptr<Scene> scene = std::make_unique<Scene>(std::bind(&GameSystem::createScene, this));

        std::shared_ptr<Entity> modelEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(20, 0, 20);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("assets_test/guy.iqm", "assets_test/guytex.png");
        std::shared_ptr<ModelAnim> anim = std::make_shared<ModelAnim>("assets_test/guyanim.iqm");
        std::shared_ptr<Hitbox> hitbox = std::make_shared<Hitbox>(true);
        modelEntity->addComponent(pos2)
            .addComponent(model)
            .addComponent(anim)
            .addComponent(hitbox);

        createPlayer(*scene, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, 1, {10, 0, 10});
        createPlayer(*scene, KEY_D, KEY_A, KEY_W, KEY_S, 2, {0, 0, 0});
        scene->addEntities({modelEntity, createCamera({50.0f, 50.0f, 50.0f}, {0.0f, 10.0f, 0.0f})});
        return scene;
    }

    void GameSystem::createPlayer(Scene &scene, int keyRight, int keyLeft, int keyUp, int keyDown, int id, Position pos)
    {
        std::shared_ptr<Entity> playerEntity = std::make_shared<Entity>();
        std::shared_ptr<Position> playerPos = std::make_shared<Position>(pos);
        std::shared_ptr<Velocity> playerVel = std::make_shared<Velocity>(0, 0);
        std::shared_ptr<Hitbox> playerHitbox = std::make_shared<Hitbox>(true);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");
        std::shared_ptr<Player> player = std::make_shared<Player>(id, "Z", "S", "Q", "D");
        std::shared_ptr<EventListener> playerListener = std::make_shared<EventListener>();

        ButtonCallbacks moveRightCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveRight(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopRight(manager, playerEntity, 1);
            });
        ButtonCallbacks moveLeftCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveLeft(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopLeft(manager, playerEntity, 17);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveLeft(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopLeft(manager, playerEntity, 17);
            });
        ButtonCallbacks moveUpCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveUp(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopUp(manager, playerEntity, 1);
            });
        ButtonCallbacks moveDownCallbacks(
            [player, playerEntity](SceneManager &manager) {
                player->moveDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->moveDown(manager, playerEntity, 1);
            },
            [player, playerEntity](SceneManager &manager) {
                player->stopDown(manager, playerEntity, 1);
            });
        playerListener->addKeyboardEvent((KeyboardKey)keyUp, moveUpCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyLeft, moveLeftCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyRight, moveRightCallbacks);
        playerListener->addKeyboardEvent((KeyboardKey)keyDown, moveDownCallbacks);

        playerEntity->addComponent(player)
            .addComponent(playerPos)
            .addComponent(playerVel)
            .addComponent(playerListener)
            .addComponent(playerHitbox)
            .addComponent(model);
        scene.addEntity(playerEntity);
    }

    void GameSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        _collideSystem.loadEntity(entity);
    }

    void GameSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        _collideSystem.unloadEntity(entity);
    }

    void GameSystem::changeBindings(SceneManager &sceneManager, int id_player, int button)
    {
        auto entity = sceneManager.getScene(SceneManager::SceneType::GAME)[IEntity::Tags::PLAYER][id_player];
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
}