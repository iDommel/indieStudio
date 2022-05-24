#include "raylib.h"
#include "shape3d.hpp"

shape3D::shape3D()
{

}

shape3D::~shape3D()
{

}

void shape3D::DrawSphere(Vector3 centerPos, float radius, Color color)
{
    ::DrawSphere(centerPos, radius, color);
}

void shape3D::DrawCube(Vector3 position, Vector3 size, Color color)
{
    DrawCubeV(position, size, color);
}

void shape3D::DrawGrid(int slices, float spacing)
{
    ::DrawGrid(slices, spacing);
}