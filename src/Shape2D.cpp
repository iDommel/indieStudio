#include "Shape2D.hpp"
#include "raylib.h"

indie::Shape2D::Shape2D()
{}

indie::Shape2D::~Shape2D()
{}


void indie::Shape2D::drawCircle(int centerX, int centerY, float radius, Color color) {
	DrawCircle(centerX, centerY, radius, color);
}

void indie::Shape2D::drawRectangle(int posX, int posY, int width, int height, Color color) {
	DrawRectangle(posX, posY, width, height, color);
}