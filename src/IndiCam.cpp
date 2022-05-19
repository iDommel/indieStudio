/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** IndiCam
*/

#include "IndiCam.hpp"

#include "raylib.h"
#include <memory>

/* #ifndef DEBUG
    #define DEBUG
    #include <iostream>
#endif */

static int getNewId(void)
{
    static int idCounter = 0;

    return (idCounter++);
}

IndiCam::IndiCam(Vector3 target, Vector3 position)
{
    _camera = std::make_shared <Camera3D>();
    SetCameraMode(*(_camera.get()), CAMERA_FREE);
    _camera->target = target;
    _camera->position = position;
    _camera->up = {0, 1, 0};
    _camera->fovy = 45.0f;
    _camera->projection = CAMERA_PERSPECTIVE;
    _id = getNewId();
    #ifdef DEBUG
        std::cerr << "\tIndiCam::IndiCam(Vector3 target, Vector3 position) called" << std::endl;
    #endif
}

IndiCam::IndiCam(std::shared_ptr<Vector3> target, std::shared_ptr<Vector3> position)
: _targetSnap(target), _positionSnap(position), _snapMode(true)
{
    _camera = std::make_shared <Camera3D>();
    SetCameraMode(*(_camera.get()), CAMERA_FREE);
    _camera->target = *(_targetSnap.get());
    _camera->position = *(_positionSnap.get());
    _camera->up = {0, 1, 0};
    _camera->fovy = 45.0f;
    _camera->projection = CAMERA_PERSPECTIVE;
    _id = getNewId();
    #ifdef DEBUG
        std::cerr << "\tIndiCam::IndiCam(std::shared_ptr<Vector3> target, std::shared_ptr<Vector3> position) called" << std::endl;
    #endif
}

void IndiCam::setSnapMode(bool snapMode)
{
    _snapMode = snapMode;
}

void IndiCam::setPosition(Vector3 pos)
{
    _camera->position = pos;
}

void IndiCam::setSnapedPosition(std::shared_ptr<Vector3> pos)
{
    _positionSnap = pos;
    _camera->position = *(_positionSnap.get());
}

void IndiCam::setTarget(Vector3 target)
{
    _camera->target = target;
}

void IndiCam::setSnapedTarget(std::shared_ptr<Vector3> target)
{
    _targetSnap = target;
    _camera->target = *(_targetSnap.get());
}

void IndiCam::shiftPosition(Vector3 shift)
{
    _camera->position.x += shift.x;
    _camera->position.y += shift.y;
    _camera->position.z += shift.z;
}

int IndiCam::getId(void) const
{
    return _id;
}

void IndiCam::update(void)
{
    if (_snapMode) {
        _camera->target = *_targetSnap;
        _camera->position = *_positionSnap;
    }
    UpdateCamera(_camera.get());
    #ifdef DEBUG
        std::cerr << "\tIndiCam::update(void) called" << std::endl;
    #endif
}

void IndiCam::beginDraw(void)
{
    BeginMode3D(*(_camera.get()));
    #ifdef DEBUG
        std::cerr << "\tIndiCam::beginDraw(void) called" << std::endl;
    #endif
}

void IndiCam::endDraw(void)
{
    EndMode3D();
    #ifdef DEBUG
        std::cerr << "\tIndiCam::endDraw(void) called" << std::endl;
    #endif
}

IndiCam::~IndiCam()
{
}
