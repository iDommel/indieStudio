/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <memory>

class Camera {
    public:
        /**
         * @brief Construct a new Camera object
         */
        Camera(vector3D target, vector3D position);
        /**
         * @brief Construct a new Camera object with target and position snaped to another entity
         */
        Camera(std::shared_ptr<vector3D> target, std::shared_ptr<vector3D> position);
        /**
         * @brief Copy constructor
         */
        Camera(const Camera &camera);
        /**
         * @brief Assignement operator
         */
        Camera &operator=(const Camera &camera);
        ~Camera();

        /**
         * @brief Shift position
         * @param shift Vector to add to position
         */
        void shiftPosition(vector3D shift);
        /**
         * @brief Set position
         * @param pos New position
         */
        void setPosition(vector3D pos);
        /**
         * @brief Get position
         * @return the position of the camera
         */
        const vector3D &getPosition(void) const;
        /**
         * @brief set target coordinates to follow
         * @param target coordinates ptr
         */
        void setTarget(std::shared_ptr<vector3D> target);
        /**
         * @brief Get ID
         * @return integer descriptor of the camera
         */
        int getId(void) const;
    protected:
    private:
        /** @brief _nonSnaped position of the camera, used if _snapMode == false */
        vector3D _position = {0, 10, 10};
        /** @brief _nonSnaped target of the camera, used if _snapMode == false */
        vector3D _target = {0, 0, 0};
        /** @brief _snapMode, set at true if you want to use extern values as position and target to auto update them */
        bool _snapMode = false;
        /** @brief _snaped target of the camera (as a shared_ptr), used if _snapMode == true */
        std::shared_ptr<vector3D> _targetSnap = nullptr;
        /** @brief _snaped position of the camera (as a shared_ptr), used if _snapMode == true */
        std::shared_ptr<vector3D> _positionSnap = nullptr;
        /** @brief _up doesn't represent anything */ //TODO: change description
        vector3D _up = {0, 1, 0};
        /** @brief _fovY represent field of view in Y */
        float _fovY = 45.0f;
        /** @brief _id, used to identify the camera */
        const int _id;
};

/** @brief Encapsualtion of vector3 from raylib */
struct vector3D {
    float x;
    float y;
    float z;
};

#endif /* !CAMERA_HPP_ */
