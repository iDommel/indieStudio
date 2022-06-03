/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** collideSystem
*/

#include "collideSystem.hpp"
#include "Model.hpp"
#include <raylib.h>

#include <iostream>

namespace indie {

    namespace collideSystem {
        /// ------- 3D -------

        BoundingBox getBBoxFromSizePos(Vector3 size, Vector3 pos)
        {
            Vector3 min = {pos.x, pos.y, pos.z};
            Vector3 max = {pos.x + size.x, pos.y + size.y, pos.z + size.z};
            BoundingBox box = {min, max};

            return box;
        }

        BoundingBox updateBBoxFromModel(BoundingBox box, Vector3 pos)
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

        bool check3DCollision(const BoundingBox &box1, const BoundingBox &box2)
        {
            return CheckCollisionBoxes(box1, box2);
        }

        bool check3DCollision(const BoundingBox &box1, Vector3 pos1, const BoundingBox &box2, Vector3 pos2)
        {
            return CheckCollisionBoxes(updateBBoxFromModel(box1, pos1), updateBBoxFromModel(box2, pos2));
        }

        bool check3DCollision(const BoundingBox &box, Vector3 center, float radius)
        {
            return CheckCollisionBoxSphere(box, center, radius);
        }

        bool check3DCollision(const BoundingBox &box, Vector3 pos, Vector3 center, float radius)
        {
            BoundingBox fstBox = {
                (Vector3) {
                    pos.x + box.min.x,
                    pos.y + box.min.y,
                    pos.z + box.min.z},
                (Vector3) {
                    pos.x + box.max.x,
                    pos.y + box.max.y,
                    pos.z + box.max.z}
                };
            return CheckCollisionBoxSphere(fstBox, center, radius);
        }

        bool check3DCollision(Vector3 center, float radius, const BoundingBox &box)
        {
            return CheckCollisionBoxSphere(box, center, radius);
        }
        
        bool check3DCollision(Vector3 center, float radius, const BoundingBox &box, Vector3 pos)
        {
            return check3DCollision(box, pos, center, radius);
        }

        bool check3DCollision(Vector3 center, float radius, Vector3 center2, float radius2)
        {
            return CheckCollisionSpheres(center, radius, center2, radius2);
        }

        /// ------- 2D -------

        Rectangle getRectangleOf(const Image &image, float threshold)
        {
            return GetImageAlphaBorder(image, threshold);
        }

        bool check2DCollision(const Rectangle &rect1, const Rectangle &rect2)
        {
            return CheckCollisionRecs(rect1, rect2);
        }

        bool check2DCollision(const Rectangle &rect, Vector2 center, float radius)
        {
            return CheckCollisionCircleRec(center, radius, rect);
        }

        bool check2DCollision(Vector2 center, float radius, const Rectangle &rect)
        {
            return CheckCollisionCircleRec(center, radius, rect);
        }

        bool check2DCollision(Vector2 center1, float radius1, Vector2 center2, float radius2)
        {
            return CheckCollisionCircles(center1, radius1, center2, radius2);
        }

        bool check2DCollision(const Vector2 &point, const Rectangle &rect)
        {
            return CheckCollisionPointRec(point, rect);
        }

        bool check2DCollision(const Rectangle &rect, const Vector2 &point)
        {
            return CheckCollisionPointRec(point, rect);
        }

        bool check2DCollision(const Vector2 &point, Vector2 center, float radius)
        {
            return CheckCollisionPointCircle(point, center, radius);
        }

        bool check2DCollision(Vector2 center, float radius, const Vector2 &point)
        {
            return CheckCollisionPointCircle(point, center, radius);
        }
    }
}
