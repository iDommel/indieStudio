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

    const std::map<Entity::Tags, std::vector<std::vector<Component::Tags>>> Entity::entityTags = {
        {
            Entity::Tags::RENDERABLE_2D,
            {
                {Component::Tags::SPRITE, Component::Tags::VECTOR},
                {Component::Tags::TEXT, Component::Tags::VECTOR}
            }
        },
        {
            Entity::Tags::RENDERABLE_3D,
            {
                {Component::Tags::VECTOR, Component::Tags::MODEL}
            }
        },
        {
            Entity::Tags::AUDIBLE,
            {
                {Component::Tags::MUSIC},
                {Component::Tags::SOUND}
            }
        },
        {
            Entity::Tags::COLLIDABLE,
            {
                {Component::Tags::HITBOX}
            }
        }
    };

    void Entity::addComponent(std::shared_ptr<Component> component)
    {
        bool notFound = false;

        _componentsTags.push_back(component->getTag());
        _components.push_back(std::move(component));
        for (auto &tag : entityTags) {
            if (std::find(_tags.begin(), _tags.end(), tag.first) != _tags.end())
                continue;
            for (auto &vec : tag.second) {
                notFound = false;
                for (auto &ctag : vec) {
                    if (std::find(_componentsTags.begin(), _componentsTags.end(), ctag) == _componentsTags.end()) {
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

}