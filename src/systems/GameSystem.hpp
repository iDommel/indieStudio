/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.hpp
*/

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "ISystem.hpp"
#include "CollideSystem.hpp"

#define GAME_MAP_WIDTH 15
#define GAME_MAP_HEIGHT 15
#define GAME_TILE_SIZE 12
#define GAME_NB_INDESTRUCTIBLE_WALL 0  //(GAME_MAP_WIDTH * GAME_MAP_HEIGHT) / 7
#define GAME_NB_DESTRUCTIBLE_WALL (GAME_MAP_WIDTH * GAME_MAP_HEIGHT) / 3

struct Vector3;

namespace indie
{

    class IEntity;
    class Scene;
    class Position;

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
        void createPlayer(Scene &scene, int keyRight, int keyLeft, int keyUp, int keyDown, int id, Position pos);
        void updatePlayers(SceneManager &scene, uint64_t dt);
        CollideSystem _collideSystem;
        std::shared_ptr<IEntity> createCamera(Vector3 camPos, Vector3 camTarget);
        /// @brief Create a map of the game (TODO: trasnform method to none static to avoid forwarding the scene)
        static void generateMap(const std::string &filename, IScene &scene);
    };

}

#endif /* GAME_SYSTEM_HPP */