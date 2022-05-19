/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** CameraDevice
*/

#include "CameraDevice.hpp"
#include <raylib.h>

static int getId(void)
{
    static int idCounter = 0;

    return (idCounter++);
}

CameraDevice::CameraDevice(Vector3 target, Vector3 position)
: _target(target), _position(position), _id(getId())
{
    Camera3D camera = {0};
    SetCameraMode(camera, CAMERA_ORBITAL);
    _camera = std::make_shared<Camera3D>(camera);
    _camera->target = _target;
    _camera->position = _position;
    _camera->up = _up;
    _camera->fovy = _fovY;
    _camera->projection = CAMERA_PERSPECTIVE;
}

CameraDevice::CameraDevice(std::shared_ptr<Vector3> target, std::shared_ptr<Vector3> position)
: _targetSnap(target), _positionSnap(position), _snapMode(true), _id(getId())
{
    Camera3D camera = {0};

    SetCameraMode(camera, CAMERA_ORBITAL);
    _camera = std::make_shared<Camera3D>(camera);
    _camera->target = *_targetSnap;
    _camera->position = *_positionSnap;
    _camera->up = _up;
    _camera->fovy = _fovY;
    _camera->projection = CAMERA_PERSPECTIVE;
}

CameraDevice::CameraDevice(const CameraDevice &camera)
: _target(camera._target), _position(camera._position),
_targetSnap(camera._targetSnap), _positionSnap(camera._targetSnap), _id(camera._id)
{
    _camera = std::make_shared<Camera3D>(*camera._camera);
}

CameraDevice &CameraDevice::operator=(const CameraDevice &camera)
{
    _target = camera._target;
    _position = camera._position;
    _targetSnap = camera._targetSnap;
    _positionSnap = camera._positionSnap;
    _snapMode = camera._snapMode;
    _camera = std::make_shared<Camera3D>(*camera._camera);
    return *this;
}

CameraDevice::~CameraDevice()
{
}

void CameraDevice::shiftPosition(Vector3 shift)
{
    _position.x += shift.x;
    _position.y += shift.y;
    _position.z += shift.z;
}

void CameraDevice::setPosition(Vector3 pos)
{
    _position = pos;
}

const Vector3 &CameraDevice::getPosition(void) const
{
    return _position;
}

void CameraDevice::setTarget(std::shared_ptr<Vector3> target)
{
    _targetSnap = target;
}

int CameraDevice::getId(void) const
{
    return _id;
}

void CameraDevice::update(void)
{
    if (_snapMode) {
        _camera->target = *_targetSnap;
        _camera->position = *_positionSnap;
    } else {
        _camera->target = _target;
        _camera->position = _position;
    }
    UpdateCamera(_camera.get());
}

void CameraDevice::beginDraw(void)
{
    BeginMode3D(*(_camera.get()));
}

void CameraDevice::endDraw(void)
{
    EndMode3D();
}
