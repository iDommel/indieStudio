/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** collideSystem
*/

#include "CollideSystem.hpp"
#include "Model.hpp"
#include <raylib.h>

#include <iostream>

namespace indie {
    CollideSystem::CollideSystem()
    {
    }

    CollideSystem::~CollideSystem()
    {
    }
    /// ------- 3D -------

    BoundingBox CollideSystem::makeBBoxFromSizePos(Vector3 size, Vector3 pos)
    {
        Vector3 min = {pos.x, pos.y, pos.z};
        Vector3 max = {pos.x + size.x, pos.y + size.y, pos.z + size.z};
        BoundingBox box = {min, max};

        return box;
    }

    BoundingBox CollideSystem::makeUpdatedBBox(const BoundingBox &box, Vector3 pos)
    {
        BoundingBox updatedBox = {
            (Vector3) {
                pos.x + box.min.x,
                pos.y + box.min.y,
                pos.z + box.min.z},
            (Vector3) {
                pos.x + box.max.x,
                pos.y + box.max.y,
                pos.z + box.max.z}
            };

        return updatedBox;
    }

    bool CollideSystem::check3DCollision(const BoundingBox &box1, const BoundingBox &box2)
    {
        return CheckCollisionBoxes(box1, box2);
    }

    bool CollideSystem::check3DCollision(const BoundingBox &box, Vector3 center, float radius)
    {
        return CheckCollisionBoxSphere(box, center, radius);
    }

    bool CollideSystem::check3DCollision(Vector3 center, float radius, const BoundingBox &box)
    {
        return CheckCollisionBoxSphere(box, center, radius);
    }

    bool CollideSystem::check3DCollision(Vector3 center, float radius, Vector3 center2, float radius2)
    {
        return CheckCollisionSpheres(center, radius, center2, radius2);
    }

    /// ------- 2D -------

    Rectangle CollideSystem::getRectangleOf(const Image &image, float threshold)
    {
        return GetImageAlphaBorder(image, threshold);
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect1, const Rectangle &rect2)
    {
        return CheckCollisionRecs(rect1, rect2);
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect, Vector2 center, float radius)
    {
        return CheckCollisionCircleRec(center, radius, rect);
    }

    bool CollideSystem::check2DCollision(Vector2 center, float radius, const Rectangle &rect)
    {
        return CheckCollisionCircleRec(center, radius, rect);
    }

    bool CollideSystem::check2DCollision(Vector2 center1, float radius1, Vector2 center2, float radius2)
    {
        return CheckCollisionCircles(center1, radius1, center2, radius2);
    }

    bool CollideSystem::check2DCollision(const Vector2 &point, const Rectangle &rect)
    {
        return CheckCollisionPointRec(point, rect);
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect, const Vector2 &point)
    {
        return CheckCollisionPointRec(point, rect);
    }

    bool CollideSystem::check2DCollision(const Vector2 &point, Vector2 center, float radius)
    {
        return CheckCollisionPointCircle(point, center, radius);
    }

    bool CollideSystem::check2DCollision(Vector2 center, float radius, const Vector2 &point)
    {
        return CheckCollisionPointCircle(point, center, radius);
    }
}
