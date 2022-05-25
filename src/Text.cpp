/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Text
*/

#include <raylib.h>
#include "Text.hpp"

namespace indie {

Text::Text()
{
}

Text::~Text()
{
}

void Text::DrawText(const std::string &text, int posX, int posY, int fontSize, Color color)
{
    ::DrawText(text.c_str(), posX, posY, fontSize, color);
}

int Text::MeasureText(const std::string &text, int fontSize)
{
    return ::MeasureText(text.c_str(), fontSize);
}

}