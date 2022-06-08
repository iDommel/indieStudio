/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.hpp
*/

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "ISystem.hpp"
#include "SceneManager.hpp"
#include "Scene.hpp"
#include "Position.hpp"
#include "Entity.hpp"

namespace indie
{

    class IEntity;

    class GameSystem : public ISystem
    {
    public:
        enum class EventType {
            NONE = -1,
            GAME,
            MAIN_MENU,
            PAUSE,
            SOUND,
            MINUS,
            PLUS
        };
        void init(SceneManager &manager) final;
        void update(SceneManager &manager, uint64_t deltaTime) final;
        void destroy() final;

        /**
         * @brief The callback to be called when an entity is added to a scene
         * @param entity The Entity that was added
         */
        void loadEntity(std::shared_ptr<IEntity> entity) final;
        /**
         * @brief The callback to be called when an entity is removed from a scene
         * @param entity The Entity that was removed
         */
        void unloadEntity(std::shared_ptr<IEntity> entity) final;

        void printStuff(SceneManager &);

    private:
        std::unique_ptr<IScene> createScene();
        std::unique_ptr<IScene> createMainMenu();
        std::unique_ptr<IScene> createSoundMenu();
        void createEventListener(std::shared_ptr<Entity> &scene, EventType event);
        std::shared_ptr<Entity> createButton(std::string path, Position position, int heigh, int width);
    };

}

#endif /* GAME_SYSTEM_HPP */