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
        static const std::map<Tags, std::vector<std::vector<Component::Tags>>> entityTags;

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

    private:
        std::vector<Tags> _tags;
        std::vector<std::shared_ptr<Component>> _components;
        std::vector<Component::Tags> _componentsTags;
    };
}

#endif // ENTITY_HPP