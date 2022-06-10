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

#define GAME_MAP_WIDTH 15
#define GAME_MAP_HEIGHT 15
#define GAME_TILE_SIZE 12

struct Vector3;

namespace indie
{

    class IEntity;

    class GameSystem : public ISystem
    {
    public:
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
        std::shared_ptr<IEntity> createCamera(Vector3 camPos, Vector3 camTarget);
        static void generateMap(const std::string &filename, IScene &scene);

    };

}

#endif /* GAME_SYSTEM_HPP */