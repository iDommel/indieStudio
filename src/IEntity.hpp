/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IEntity.hpp
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <vector>

#include "Components/Component.hpp"

namespace indie
{

    class IEntity
    {
    public:

        enum class Tags {
            RENDERABLE_3D,
            RENDERABLE_2D,
            COLLIDABLE,
            AUDIBLE
        };

        ///@brief Add component to entity and update entity's tags accordingly
        virtual void addComponent(std::shared_ptr<Component> component) = 0;
        /**
         * @brief Get entity's components
         * @return Returns a reference of the entity's components vector
         */
        virtual std::vector<std::shared_ptr<Component>> &getComponents() = 0;
        /**
         * @brief Get entity's tags
         * @return Returns a reference of the entity's tags vector
         */
        virtual const std::vector<Tags> &getTags() const = 0;

    };

}

#endif /* IENTITY_HPP */