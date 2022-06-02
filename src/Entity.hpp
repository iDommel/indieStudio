/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <memory>
#include <map>

#include "IEntity.hpp"
#include "components/IComponent.hpp"

#include <iostream>

namespace indie {
    class Entity : public IEntity
    {
    public:

        ///@brief Map between Entity tags and combinaisons of Components tags
        static const std::map<Tags, std::vector<std::vector<IComponent::Type>>> entityTags;

        ///@brief Add component to entity and update entity's tags accordingly, mustn't be called after moving entity to scene
        void addComponent(std::shared_ptr<IComponent> component);
        /**
         * @brief Get entity's components
         * @return Returns a reference of the entity's components vector
         */
        std::vector<std::shared_ptr<IComponent>> &getComponents();
        /**
         * @brief Get entity's tags
         * @return Returns a reference of the entity's tags vector
         */
        const std::vector<Tags> &getTags() const { return _tags; };

        /**
         * @brief Search if entity has a tag
         * @param tag Tag to search for
         * @return Returns true if entity has the given tag, false otherwise
         */
        bool hasTag(Tags tag) const;

        /**
         * @brief Get components of given types
         * @param components Vector of components types to search for
         * @return Returns a vector of components of the given types in the same order
         */
        std::vector<std::shared_ptr<IComponent>> getComponents(std::vector<IComponent::Type> components);

        /**
         * @brief Get component of given type
         * @param type Type of component to search for
         * @return Returns a component of the given type
         */
        std::shared_ptr<IComponent> &getComponent(IComponent::Type type);

    private:
        std::vector<Tags> _tags;
        std::vector<std::shared_ptr<IComponent>> _components;
        std::vector<IComponent::Type> _componentsType;
    };
}

#endif // ENTITY_HPP