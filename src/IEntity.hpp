/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IEntity.hpp
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <vector>

namespace indie
{
    class IEntity
    {
    public:

        // virtual std::vector<AComponent> &getComponents() = 0;
        // virtual void addComponent(std::shared_ptr<AComponent> component) = 0;


        virtual const std::string &getName() const = 0;

    };

}

#endif /* IENTITY_HPP */