/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** System.hpp
*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>

namespace indie {

    class SceneManager;
    class IEntity;

    class ISystem
    {
    public:
        virtual void init(SceneManager &manager) = 0;
        virtual void update(SceneManager &manager, uint64_t deltaTime) = 0;
        virtual void destroy() = 0;

        /**
         * @brief Load entity's dependency(ies) in cache if needed
         */
        virtual void loadEntity(std::shared_ptr<IEntity> entity) = 0;
    };

}

#endif /* SYSTEM_HPP */