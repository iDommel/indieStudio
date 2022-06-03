#ifndef SHAPE3DH
#define SHAPE3DH

struct Vector2;
struct Color;

namespace indie
{
    /**struct Shape2D;
     * @brief Shape2D object
     */
    class Shape2D
    {
    public:
        /**
         * @brief Construct a new Shape2D object
         */
        Shape2D();
        /**
         * @brief Destroy Shape2D object
         */
        ~Shape2D();

        /**
         * @brief Draw circle
         * @param centerX position X of the center of the circle
         * @param centerY position Y of the center of the circle
         * @param radius radius of the circle
         * @param color Color of the circle
         */
        void drawCircle(int centerX, int centerY, float radius, Color color);
        /**
         * @brief Draw rectangle
         * @param posX position X of the center of the rectangle
         * @param posY position X of the center of the rectangle
         * @param width width of the rectangle
         * @param height height of the rectangle
         * @param color Color of the rectangle
         */
        void drawRectangle(int posX, int posY, int width, int height, Color color);
    };
}

#endif /* !MODELH */