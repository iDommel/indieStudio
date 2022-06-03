/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IEntity.hpp
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <vector>

#include "components/IComponent.hpp"

namespace indie
{

    class IEntity
    {
    public:
        enum class Tags {
            RENDERABLE_3D,
            RENDERABLE_2D,
            COLLIDABLE,
            AUDIBLE,
            CALLABLE
        };

        virtual ~IEntity() = default;

        ///@brief Add component to entity and update entity's tags accordingly
        virtual IEntity &addComponent(std::shared_ptr<IComponent> component) = 0;
        ///@brief Add component to entity and update entity's tags accordingly
        virtual IEntity &addComponents(std::vector<std::shared_ptr<IComponent>> components) = 0;

        /**
         * @brief Get entity's components
         * @return Returns a reference of the entity's components vector
         */
        virtual std::vector<std::shared_ptr<IComponent>> &getComponents() = 0;
        /**
         * @brief Get entity's tags
         * @return Returns a reference of the entity's tags vector
         */
        virtual const std::vector<Tags> &getTags() const = 0;

        /**
         * @brief Search if entity has a tag
         * @param tag Tag to search for
         * @return Returns true if entity has the given tag, false otherwise
         */
        virtual bool hasTag(Tags tag) const = 0;

        /**
         * @brief Get components of given types
         * @param components Vector of components types to search for
         * @return Returns a vector of components of the given types in the same order
         */
        virtual std::vector<std::shared_ptr<IComponent>> getComponents(std::vector<IComponent::Type> components) = 0;
    };

}

#endif /* IENTITY_HPP */