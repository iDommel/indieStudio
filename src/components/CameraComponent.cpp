/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** CameraComponent.cpp
*/

#include "CameraComponent.hpp"

#include "raylib.h"

namespace indie
{
    CameraComponent::CameraComponent(Vector3 target, Vector3 position)
        : Component(Type::CAMERA), _camera(target, position)
    {
    }

    Camera &CameraComponent::getCamera() { return _camera; }
}