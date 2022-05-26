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
#include "Components/Component.hpp"

namespace indie {
    class Entity : public IEntity
    {
    public:

        ///@brief Map between Entity tags and combinaisons of Components tags
        static const std::map<Tags, std::vector<std::vector<Component::Type>>> entityTags;

        ///@brief Add component to entity and update entity's tags accordingly
        void addComponent(std::shared_ptr<Component> component);
        /**
         * @brief Get entity's components
         * @return Returns a reference of the entity's components vector
         */
        std::vector<std::shared_ptr<Component>> &getComponents();
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

    private:
        std::vector<Tags> _tags;
        std::vector<std::shared_ptr<Component>> _components;
        std::vector<Component::Type> _componentsType;
    };
}

#endif // ENTITY_HPP