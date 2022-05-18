/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

/** @brief Encapsualtion of vector3 from raylib (including every operator override)*/
class Vector3D {
    public:
        Vector3D(float x, float y, float z);
        Vector3D(const Vector3D &vector);

        Vector3D &operator=(const Vector3D &vector);
        Vector3D &operator+=(const Vector3D &vector);
        Vector3D &operator-=(const Vector3D &vector);
        Vector3D &operator*=(const Vector3D &vector);
        Vector3D &operator/=(const Vector3D &vector);
        Vector3D operator+(const Vector3D &vector) const;
        Vector3D operator-(const Vector3D &vector) const;
        Vector3D operator*(const Vector3D &vector) const;
        Vector3D operator/(const Vector3D &vector) const;

        Vector3D &operator=(float value);
        Vector3D &operator+=(float value);
        Vector3D &operator-=(float value);
        Vector3D &operator*=(float value);
        Vector3D &operator/=(float value);
        Vector3D operator+(float value) const;
        Vector3D operator-(float value) const;
        Vector3D operator*(float value) const;
        Vector3D operator/(float value) const;


        ~Vector3D();

    protected:
    private:
        float x;
        float y;
        float z;
};

#endif /* !VECTOR3D_HPP_ */
