/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>

struct Color;

namespace indie {
class Text {
    public:
        Text();
        ~Text();

        /**
         * @brief Draw text (using default font)
         * @param text Text to draw
         * @param posX Hoizontal position of the text
         * @param posY Vertical position of the text
         * @param color Color of the text
         */
        void DrawText(const std::string &text, int posX, int posY, int fontSize, Color color);

        /**
         * @brief Measure string width for default font
         * @param text Text to measure
         * @param fontSize Size of the font
         * @return Width of the text
         */
        int MeasureText(const std::string &text, int fontSize);

    protected:
    private:
};
}
#endif /* !TEXT_HPP_ */
