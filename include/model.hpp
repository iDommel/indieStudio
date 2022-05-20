/*
** EPITECH PROJECT, 2022
** indie
** File description:
** models
*/

#ifndef MODELH
    #define MODELH

    struct Model;
    struct Vector3;
    struct Color;

    #include <memory>

namespace indie {

    /**struct Model;
     * @brief Model 3D object
     */  
    class Model {
        public:
            /**
             * @brief Construct a new model object
             * @param filename path to the model file 
             */
            Model(const char *filename);
            /**
             * @brief Unload / destroy the model object
             */
            ~Model();
            /**
             * @brief Draw the model 
             * @param position vector 3d to draw the model
             * @param scale float of scaling (1.0f = default)
             * @param tint Color of the model (WHITE = default)
             */
            void draw(Vector3 position, float scale, Color tint);
        private:
            /**
             * @brief Pointer to the model struct of raylib
             */
            std::unique_ptr <::Model> ptr;
    };
}

#endif /* !MODELH */