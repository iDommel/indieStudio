/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

// implement hpp

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3D::Vector3D(const Vector3D &vector) : x(vector.x), y(vector.y), z(vector.z)
{
}

Vector3D &Vector3D::operator=(const Vector3D &vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

Vector3D &Vector3D::operator+=(const Vector3D &vector)
{
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &vector)
{
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector3D &Vector3D::operator*=(const Vector3D &vector)
{
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
    return *this;
}

Vector3D &Vector3D::operator/=(const Vector3D &vector)
{
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &vector) const
{
    return Vector3D(x + vector.x, y + vector.y, z + vector.z);
}

Vector3D Vector3D::operator-(const Vector3D &vector) const
{
    return Vector3D(x - vector.x, y - vector.y, z - vector.z);
}

Vector3D Vector3D::operator*(const Vector3D &vector) const
{
    return Vector3D(x * vector.x, y * vector.y, z * vector.z);
}

Vector3D Vector3D::operator/(const Vector3D &vector) const
{
    return Vector3D(x / vector.x, y / vector.y, z / vector.z);
}

Vector3D &Vector3D::operator=(float value)
{
    x = value;
    y = value;
    z = value;
    return *this;
}

Vector3D &Vector3D::operator+=(float value)
{
    x += value;
    y += value;
    z += value;
    return *this;
}

Vector3D &Vector3D::operator-=(float value)
{
    x -= value;
    y -= value;
    z -= value;
    return *this;
}

Vector3D &Vector3D::operator*=(float value)
{
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

Vector3D &Vector3D::operator/=(float value)
{
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

Vector3D Vector3D::operator+(float value) const
{
    return Vector3D(x + value, y + value, z + value);
}

Vector3D Vector3D::operator-(float value) const
{
    return Vector3D(x - value, y - value, z - value);
}

Vector3D Vector3D::operator*(float value) const
{
    return Vector3D(x * value, y * value, z * value);
}

Vector3D Vector3D::operator/(float value) const
{
    return Vector3D(x / value, y / value, z / value);
}

Vector3D::~Vector3D()
{
}