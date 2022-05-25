/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

#include "IEntity.hpp"

namespace indie {
    class Entity : public IEntity
    {
    public:
        Entity(const std::string& name) : _name(name) {}

        const std::string &getName() const { return _name; }

    private:
        std::string _name;
    };
}

#endif // ENTITY_HPP