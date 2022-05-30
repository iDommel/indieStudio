/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GameSystem.hpp
*/

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "ISystem.hpp"
#include "../SceneManager.hpp"

namespace indie {

    class IEntity;

    class GameSystem : public ISystem
    {
    public:

        void init(SceneManager &manager) final override;
        void update(SceneManager &manager, uint64_t deltaTime) final override;
        void destroy() final override;

        /**
         * @brief Load entity dependency(ies) in cache if needed
         */
        void loadEntity(std::shared_ptr<IEntity> entity) final override;

    private:
        static std::unique_ptr<IScene> createScene();
    };

}

#endif /* GAME_SYSTEM_HPP */