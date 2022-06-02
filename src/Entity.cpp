/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

#include <algorithm>
#include <iostream>

namespace indie
{

    const std::map<Entity::Tags, std::vector<std::vector<IComponent::Type>>> Entity::entityTags = {
        {Entity::Tags::RENDERABLE_2D,
         {{IComponent::Type::SPRITE, IComponent::Type::VECTOR},
          {IComponent::Type::TEXT, IComponent::Type::VECTOR}}},
        {Entity::Tags::RENDERABLE_3D,
         {{IComponent::Type::VECTOR, IComponent::Type::MODEL}}},
        {Entity::Tags::AUDIBLE,
         {{IComponent::Type::MUSIC},
          {IComponent::Type::SOUND}}},
        {Entity::Tags::COLLIDABLE,
         {{IComponent::Type::HITBOX}}},
        {Entity::Tags::CALLABLE,
         {{IComponent::Type::EVT_LISTENER}}}};

    void Entity::addComponent(std::shared_ptr<IComponent> component)
    {
        bool notFound = false;

        IComponent::Type type = component->getType();
        _componentsType.push_back(type);
        _components[type] = component;
        // _components.insert(std::make_pair(component->getType(), std::move(component)));
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

    bool Entity::hasTag(Tags tag) const
    {
        return (std::find(_tags.begin(), _tags.end(), tag) != _tags.end());
    }

    std::map<IComponent::Type, std::shared_ptr<IComponent>> &Entity::getComponents()
    {
        return _components;
    }

    std::vector<std::shared_ptr<IComponent>> Entity::getFilteredComponents(std::vector<IComponent::Type> components)
    {
        std::vector<std::shared_ptr<IComponent>> res;

        for (auto &c : components) {
            if (_components.find(c) == _components.end())
                throw std::invalid_argument("Entity: Component type not found");
            res.push_back(_components[c]);
        }
        return res;
    }

    std::shared_ptr<IComponent> Entity::operator[](IComponent::Type type)
    {
        if (_components.find(type) == _components.end())
            return nullptr;
        return _components.at(type);
    }
}