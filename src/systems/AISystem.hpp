/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AISystem.hpp
*/

#ifndef AISystem_HPP_
#define AISystem_HPP_

#include <array>

#include "ISystem.hpp"
#include "CollideSystem.hpp"

namespace indie
{
    class Position;
    class AIPlayer;

    class AISystem : public ISystem
    {
    public:

        enum class DIRECTION
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        AISystem(CollideSystem &collideSystem);

        void init(SceneManager &manager) final;
        void update(SceneManager &manager, uint64_t deltaTime) final;
        void destroy() final;

        void loadEntity(std::shared_ptr<IEntity> entity) final;
        void unloadEntity(std::shared_ptr<IEntity> entity) final;

    private:
        void loadMap(AIPlayer &ai, int map[5][5], Position &pos, std::shared_ptr<IEntity> me);
        void loadExplosionInMap(int map[5][5], std::shared_ptr<IEntity> &explosion, int px, int pz);
        void moveAI(int map[5][5], AIPlayer &ai, std::shared_ptr<IEntity> entity, SceneManager &sceneManager);
        void changeDir(int map[5][5], AIPlayer &ai, std::shared_ptr<IEntity> entity);
        void poseBomb(AIPlayer &ai, SceneManager &sceneManager, int map[5][5]);
        bool escape(AIPlayer &ai, int map[5][5], std::shared_ptr<IEntity> entity);

        void displayMap(int map[5][5]);

        CollideSystem &_collideSystem;
    };
}

#endif /* AISystem_HPP_ */