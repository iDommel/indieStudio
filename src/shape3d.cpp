#include "raylib.h"
#include "shape3d.hpp"

indie::Shape3D::Shape3D()
{

}

indie::Shape3D::~Shape3D()
{

}

void indie::Shape3D::drawSphere(Vector3 centerPos, float radius, Color color)
{
    ::DrawSphere(centerPos, radius, color);
}

void indie::Shape3D::drawCube(Vector3 position, Vector3 size, Color color)
{
    DrawCubeV(position, size, color);
}

void indie::Shape3D::drawGrid(int slices, float spacing)
{
    ::DrawGrid(slices, spacing);
}