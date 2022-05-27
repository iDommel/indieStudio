/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** collide
*/

#include "collide.hpp"
#include <raylib.h>

    struct Sphere {
        Vector3 center;
        float radius;
    };

    struct Circle {
        Vector2 center;
        float radius;
    };
namespace indie {

    namespace collide {
        /// ------- 3D -------

        BoundingBox getBoundingBoxOf(const Model &model)
        {
            return GetModelBoundingBox(model);
        }

        BoundingBox getBoundingBoxOf(const Mesh &mesh)
        {
            return GetMeshBoundingBox(mesh);
        }

        bool check3DCollision(const BoundingBox &box1, const BoundingBox &box2)
        {
            return CheckCollisionBoxes(box1, box2);
        }

        bool check3DCollision(const BoundingBox &box, const Sphere &sphere)
        {
            return CheckCollisionBoxSphere(box, sphere.center, sphere.radius);
        }

        bool check3DCollision(const Sphere &sphere, const BoundingBox &box)
        {
            return CheckCollisionBoxSphere(box, sphere.center, sphere.radius);
        }

        bool check3DCollision(const Sphere &sphere, const Sphere &sphere2)
        {
            return CheckCollisionSpheres(sphere.center, sphere.radius, sphere2.center, sphere2.radius);
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

        bool check2DCollision(const Rectangle &rect, const Circle &circle)
        {
            return CheckCollisionCircleRec(circle.center, circle.radius, rect);
        }

        bool check2DCollision(const Circle &circle, const Rectangle &rect)
        {
            return CheckCollisionCircleRec(circle.center, circle.radius, rect);
        }

        bool check2DCollision(const Circle &circle1, const Circle &circle2)
        {
            return CheckCollisionCircles(circle1.center, circle1.radius, circle2.center, circle2.radius);
        }

        bool check2DCollision(const Vector2 &point, const Rectangle &rect)
        {
            return CheckCollisionPointRec(point, rect);
        }

        bool check2DCollision(const Rectangle &rect, const Vector2 &point)
        {
            return CheckCollisionPointRec(point, rect);
        }

        bool check2DCollision(const Vector2 &point, const Circle &circle)
        {
            return CheckCollisionPointCircle(point, circle.center, circle.radius);
        }

        bool check2DCollision(const Circle &circle, const Vector2 &point)
        {
            return CheckCollisionPointCircle(point, circle.center, circle.radius);
        }
    }
}
