/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Entity.cpp
*/

#include <iostream>
#include <algorithm>

#include "Entity.hpp"

namespace indie {

    const std::map<Entity::Tags, std::vector<std::vector<IComponent::Type>>> Entity::entityTags = {
        {
            Entity::Tags::RENDERABLE_2D,
            {
                {IComponent::Type::SPRITE, IComponent::Type::VECTOR},
                {IComponent::Type::TEXT, IComponent::Type::VECTOR}
            }
        },
        {
            Entity::Tags::RENDERABLE_3D,
            {
                {IComponent::Type::VECTOR, IComponent::Type::MODEL}
            }
        },
        {
            Entity::Tags::AUDIBLE,
            {
                {IComponent::Type::MUSIC},
                {IComponent::Type::SOUND}
            }
        },
        {
            Entity::Tags::COLLIDABLE,
            {
                {IComponent::Type::HITBOX}
            }
        },
        {
            Entity::Tags::CALLABLE,
            {
                {IComponent::Type::EVT_LISTENER}
            }
        }
    };

    void Entity::addComponent(std::shared_ptr<IComponent> component)
    {
        bool notFound = false;

        _componentsType.push_back(component->getType());
        _components.push_back(std::move(component));
        for (auto &tag : entityTags) {
            if (this->hasTag(tag.first))
                continue;
            for (auto &vec : tag.second) {
                notFound = false;
                for (auto &ctag : vec) {
                    if (std::find(_componentsType.begin(), _componentsType.end(), ctag) == _componentsType.end()) {
                        notFound = true;
                        break;
                    }
                }
                if (notFound)
                    continue;
                _tags.push_back(tag.first);
                break;
            }
        }
    }

    std::vector<std::shared_ptr<IComponent>> &Entity::getComponents()
    {
        return _components;
    }

    bool Entity::hasTag(Tags tag) const
    {
        return (std::find(_tags.begin(), _tags.end(), tag) != _tags.end());
    }

    std::vector<std::shared_ptr<IComponent>> Entity::getComponents(std::vector<IComponent::Type> components)
    {
        std::vector<std::shared_ptr<IComponent>> res;

        for (auto &c : components) {
            for (auto &component : _components) {
                if (component->getType() == c) {
                    res.push_back(component);
                    break;
                }
            }
            throw std::invalid_argument("Entity: Component type not found");
        }
        return res;
    }

}