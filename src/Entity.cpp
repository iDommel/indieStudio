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

    const std::map<Entity::Tags, std::vector<std::vector<Component::Type>>> Entity::entityTags = {
        {
            Entity::Tags::RENDERABLE_2D,
            {
                {Component::Type::SPRITE, Component::Type::VECTOR},
                {Component::Type::TEXT, Component::Type::VECTOR}
            }
        },
        {
            Entity::Tags::RENDERABLE_3D,
            {
                {Component::Type::VECTOR, Component::Type::MODEL}
            }
        },
        {
            Entity::Tags::AUDIBLE,
            {
                {Component::Type::MUSIC},
                {Component::Type::SOUND}
            }
        },
        {
            Entity::Tags::COLLIDABLE,
            {
                {Component::Type::HITBOX}
            }
        },
        {
            Entity::Tags::CALLABLE,
            {
                {Component::Type::EVT_LISTENER}
            }
        }
    };

    void Entity::addComponent(std::shared_ptr<Component> component)
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

    std::vector<std::shared_ptr<Component>> &Entity::getComponents()
    {
        return _components;
    }

    bool Entity::hasTag(Tags tag) const
    {
        return (std::find(_tags.begin(), _tags.end(), tag) != _tags.end());
    }

}