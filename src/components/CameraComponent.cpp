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
    CameraComponent::CameraComponent(Vector3 target, Vector3 position) : _camera(target, position)
    {
        _type = Type::CAMERA;
    }

    Camera &CameraComponent::getCamera() { return _camera; }
}