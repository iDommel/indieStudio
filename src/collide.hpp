/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Collide
*/

#ifndef COLLIDE_HPP_
#define COLLIDE_HPP_

struct BoundingBox;
struct Model;
struct Mesh;
struct Vector2;
struct Rectangle;
struct Image;

    struct Sphere;
    struct Circle;
namespace indie {
    namespace collide {
        /// ------- 3D -------

        /// @brief Retrieve bounding box of a model
        BoundingBox getBoundingBoxOf(const Model &model);
        /// @brief Retrieve bounding box of a mesh
        BoundingBox getBoundingBoxOf(const Mesh &mesh);

        /// @brief Check if two boxes are colliding
        bool check3DCollision(const BoundingBox &box1, const BoundingBox &box2);

        /// @brief Check if a box is colliding with a sphere
        bool check3DCollision(const BoundingBox &box, const Sphere &sphere);
        /// @brief Check if a sphere is colliding with a box
        bool check3DCollision(const Sphere &sphere, const BoundingBox &box);

        /// @brief Check if two sphere are colliding
        bool check3DCollision(const Sphere &sphere, const Sphere &sphere2);

        /// ------- 2D -------

        /**
         * @brief Retrieve rectangle of an image
         * @param image Image to retrieve rectangle from
         * @param threshold //TODO: explain
         * @return Rectangle bounding the image
         */
        Rectangle getRectangleOf(const Image &image, float threshold);

        /// @brief Check if two rectangles are colliding
        bool check2DCollision(const Rectangle &rect1, const Rectangle &rect2);

        /// @brief Check if a rectangle is colliding with a circle
        bool check2DCollision(const Rectangle &rect, const Circle &circle);
        /// @brief Check if a circle is colliding with a rectangle
        bool check2DCollision(const Circle &circle, const Rectangle &rect);

        /// @brief Check if two circles are colliding
        bool check2DCollision(const Circle &circle1, const Circle &circle2);

        /// @brief Check if a point is inside a rectangle
        bool check2DCollision(const Vector2 &point, const Rectangle &rect);
        /// @brief Check if a rectangle is on a point
        bool check2DCollision(const Rectangle &rect, const Vector2 &point);

        /// @brief Check if a point is inside a circle
        bool check2DCollision(const Vector2 &point, const Circle &circle);
        /// @brief Check if a circle is on a point
        bool check2DCollision(const Circle &circle, const Vector2 &point);
    }
}

#endif /* !COLLIDE_HPP_ */
