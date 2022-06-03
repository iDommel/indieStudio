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
struct Vector3;
struct Rectangle;
struct Image;

namespace indie {
    /// @brief CollideSystem class provide collision detection functions for 2D and 3D shapes. (does not handle collision between 3D and 2D)
    class CollideSystem {
        public:
            CollideSystem();
            ~CollideSystem();
            /// ------- 3D -------

            /**
             * @brief Make a bounding box from a size and a position
             * @param size size of the bounding box (vector3){width, height, depth}
             * @param position position of the bounding box corner used as origin
             * @return newly created BoundingBox (offseted)
            **/
            BoundingBox makeBBoxFromSizePos(Vector3 size, Vector3 pos);

            /**
             * @brief Update a bounding box from a model with his position
             * @param box bounding box to update
             * @param pos position of the model
             * @return updated BoundingBox
            **/
            BoundingBox makeUpdatedBBox(const BoundingBox &box, Vector3 pos);

            /**
             * @brief Check collision between two offseted bounding boxes
             * @param box1 First bounding box
             * @param box2 Second bounding box 
             * @return True if collision, false otherwise
            **/
            bool check3DCollision(const BoundingBox &box1, const BoundingBox &box2);

            /**
             * @brief Check collision between a bounding box and a sphere
             * @param box Bounding box
             * @param center Sphere center
             * @param radius Sphere radius
             * @return True if collision, false otherwise
            **/
            bool check3DCollision(const BoundingBox &box, Vector3 center, float radius);
            /**
             * @brief Check collision between a sphere and a bounding box
             * @param center Sphere center
             * @param radius Sphere radius
             * @param box Bounding box
             * @return True if collision, false otherwise
            **/
            bool check3DCollision(Vector3 center, float radius, const BoundingBox &box);

            /**
             * @brief Check collision between two spheres
             * @param center1 First sphere center
             * @param radius1 First sphere radius
             * @param center2 Second sphere center
             * @param radius2 Second sphere radius
             * @return True if collision, false otherwise
            **/
            bool check3DCollision(Vector3 center1, float radius1, Vector3 center2, float radius2);

            /// ------- 2D -------

            /**
             * @brief Retrieve rectangle of an image
             * @param image Image to retrieve rectangle from
             * @param threshold //TODO: explain
             * @return Rectangle bounding the image
            **/
            Rectangle getRectangleOf(const Image &image, float threshold);

            /**
             * @brief Check if two rectangles are colliding
             * @param rect1 First rectangle
             * @param rect2 Second rectangle
             * @return True if collision, false otherwise
            **/
            bool check2DCollision(const Rectangle &rect1, const Rectangle &rect2);

            /**
             * @brief Check if a rectangle is colliding with a circle
             * @param rect Rectangle
             * @param center Circle center
             * @param radius Circle radius
             * @return True if collision, false otherwise
            **/
            bool check2DCollision(const Rectangle &rect, Vector2 center, float radius);
            /**
             * @brief Check if a circle is colliding with a rectangle
             * @param center Circle center
             * @param radius Circle radius
             * @param rect Rectangle
             * @return True if collision, false otherwise
             */
            bool check2DCollision(Vector2 center, float radius, const Rectangle &rect);

            /**
             * @brief Check if two circles are colliding
             * @param center1 First circle center
             * @param radius1 First circle radius
             * @param center2 Second circle center
             * @param radius2 Second circle radius
             * @return True if collision, false otherwise
            **/
            bool check2DCollision(Vector2 center1, float radius1, Vector2 center2, float radius2);

            /** 
             * @brief Check if a point is inside a rectangle
             * @param point Point
             * @param rect Rectangle
            **/
            bool check2DCollision(const Vector2 &point, const Rectangle &rect);
            /**
             * @brief Check if a rectangle is on a point
             * @param rect Rectangle
             * @param point Point
            **/
            bool check2DCollision(const Rectangle &rect, const Vector2 &point);

            /**
             * @brief Check if a point is inside a circle
             * @param point Point
             * @param center Circle center
             * @param radius Circle radius
             * @return True if collision, false otherwise
            **/
            bool check2DCollision(const Vector2 &point, Vector2 center, float radius);
            /**
             * @brief Check if a circle is on a point
             * @param center Circle center
             * @param radius Circle radius
             * @param point Point
             * @return True if collision, false otherwise
            **/
            bool check2DCollision(Vector2 center, float radius, const Vector2 &point);
        private:
    };
}

#endif /* !COLLIDE_HPP_ */
