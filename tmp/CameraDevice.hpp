/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <memory>

struct Camera3D;
struct Vector3 {
    float x;
    float y;
    float z;
};

/// @brief raylib camera encapsulation class
class CameraDevice {
    public:
        /**
         * @brief Construct a new Camera object
         * @param target vector the cam point to
         * @param position vector where the cam is
         */
        CameraDevice(Vector3 target, Vector3 position);
        /**
         * @brief Construct a new Camera object with target and position snaped to another entity
         * @param target vector the cam point to, owned by another entity
         * @param position vector where the cam is, owned by another entity
         */
        CameraDevice(std::shared_ptr<Vector3> target, std::shared_ptr<Vector3> position);
        /**
         * @brief create a copy of the camera (COPY the ID)
         * @param camera the camera to copy
         */
        CameraDevice(const CameraDevice &camera);
        /**
         * @brief copy camera settings (DOESN'T copy the ID)
         * @param camera the camera to copy
         */
        CameraDevice &operator=(const CameraDevice &camera);
        ~CameraDevice();

        /**
         * @brief Shift position
         * @param shift Vector to add to position
         */
        void shiftPosition(Vector3 shift);
        /**
         * @brief Set position
         * @param pos New position
         */
        void setPosition(Vector3 pos);
        /**
         * @brief Get position
         * @return the position of the camera
         */
        const Vector3 &getPosition(void) const;
        /**
         * @brief set target coordinates to follow
         * @param target coordinates ptr
         */
        void setTarget(std::shared_ptr<Vector3> target);
        /**
         * @brief Get ID
         * @return integer descriptor of the camera
         */
        int getId(void) const;

        void update(void);
        void beginDraw(void);
        void endDraw(void);

    protected:
    private:
        /** @brief _nonSnaped position of the camera, used if _snapMode == false */
        Vector3 _position = {0, 10, 10};
        /** @brief _nonSnaped target of the camera, used if _snapMode == false */
        Vector3 _target = {0, 0, 0};
        /** @brief _snapMode, set at true if you want to use extern values as position and target to auto update them */
        bool _snapMode = false;
        /** @brief _snaped target of the camera (as a shared_ptr), used if _snapMode == true */
        std::shared_ptr<Vector3> _targetSnap = nullptr;
        /** @brief _snaped position of the camera (as a shared_ptr), used if _snapMode == true */
        std::shared_ptr<Vector3> _positionSnap = nullptr;
        /** @brief _up doesn't represent anything */ //TODO: change description
        Vector3 _up = {0, 1, 0};
        /** @brief _fovY represent field of view in Y */
        float _fovY = 45.0f;
        /** @brief _id, used to identify the camera */
        const int _id;

        std::shared_ptr<Camera3D> _camera = nullptr;
};
 
#endif /* !CAMERA_HPP_ */
