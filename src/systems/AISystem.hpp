/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AISystem.hpp
*/

#ifndef AISystem_HPP_
#define AISystem_HPP_

#include "ISystem.hpp"

namespace indie
{
    class AISystem : public ISystem
    {
    public:
        void init(SceneManager &manager) final;
        void update(SceneManager &manager, uint64_t deltaTime) final;
        void destroy() final;

        void loadEntity(std::shared_ptr<IEntity> entity) final;
        void unloadEntity(std::shared_ptr<IEntity> entity) final;

    private:
    };
}

#endif /* AISystem_HPP_ */