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
#include "Scene.hpp"
#include "String.hpp"
#include "Bonus.hpp"
#include "Model3D.hpp"
#include "Grid.hpp"
#include "CameraComponent.hpp"
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
        static int i = 0;
        static int j = 0;

        i++;
        if (i % 3 == 0) {
            auto components = sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][1]->getFilteredComponents({ IComponent::Type::RECT });
            auto r = Component::castComponent<Rect>(components[0]);
            r->left = r->width * j;
            if (++j > 5)
                j = 0;
        }
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
        //sceneManager.getCurrentScene().removeEntity(sceneManager.getCurrentScene()[IEntity::Tags::SPRITE_2D][2]);
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
        std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
        std::shared_ptr<Position> component = std::make_shared<Position>(10, 10);
        std::shared_ptr<Sprite> component4 = std::make_shared<Sprite>("test_pictures/raylib_logo.png");
        std::shared_ptr<Rect> component5 = std::make_shared<Rect>(0, 0, 250, 250);
        std::shared_ptr<Component> component3 = std::make_shared<Component>();

        std::shared_ptr<Entity> e = std::make_shared<Entity>();
        std::shared_ptr<Rect> rect  = std::make_shared<Rect>(0, 0, 0, 0);
        std::shared_ptr<Position> pos = std::make_shared<Position>(500, 500);
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("test_pictures/scarfy.png", 6);

        std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos2 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Model3D> model = std::make_shared<Model3D>("test_models/turret.obj", "test_models/turret_diffuse.png");

        std::shared_ptr<Entity> cam = std::make_shared<Entity>();
        Vector3 camPos = {50.0f, 50.0f, 50.0f};
        Vector3 camTarget = {0.0f, 10.0f, 0.0f};
        std::shared_ptr<CameraComponent> camera = std::make_shared<CameraComponent>(camTarget, camPos);

        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos3 = std::make_shared<Position>(10, 0, 0);
        std::shared_ptr<String> text = std::make_shared<String>("The below sprite entity has a hitbox of 250,250");

        std::shared_ptr<Entity> e4 = std::make_shared<Entity>();
        std::shared_ptr<Position> pos4 = std::make_shared<Position>(0, 0, 0);
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 1.0f);

        std::shared_ptr<EventListener> listener = std::make_shared<EventListener>();
        listener->addKeyboardEvent(KEY_SPACE, spaceCallbacks);

        entity2->addComponent(component)
            .addComponent(component4)
            .addComponent(component3)
            .addComponent(component5);

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