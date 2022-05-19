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

    class model {
        private:
            Model *models;
        public:
            model(const char *filename);
            ~model();
            void draw(Vector3 position, float scale, Color tint);
    };

#endif /* !MODELH */
