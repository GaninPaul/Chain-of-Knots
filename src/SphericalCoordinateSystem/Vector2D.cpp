//
// Created by Павел Ганин on 18.05.2018.
//

#include "Vector2D.h"

#include <cmath>

template<typename T>
inline Vector2D<T>::Vector2D()
        : X(0), Y(0)
{}

template<typename T>
template<typename R>
inline Vector2D<T>::Vector2D(const Vector2D<R>& other)
        : X(other.X), Y(other.Y)
{}

template<typename T>
inline Vector2D<T>::Vector2D(const T& x, const T& y)
        : X(x), Y(y)
{}

template<typename T>
inline Vector2D<T>::Vector2D(const T coords[2])
        : X(coords[0]), Y(coords[1])
{}

template<typename T>
inline const T& Vector2D<T>::getX() const
{
    return X;
}

template<typename T>
inline void Vector2D<T>::setX(const T& newX)
{
    X = newX;
}

template<typename T>
inline const T& Vector2D<T>::getY() const
{
    return Y;
}

template<typename T>
inline void Vector2D<T>::setY(const T& newY)
{
    Y = newY;
}



template<typename T>
inline void Vector2D<T>::getv(T buffer[2]) const
{
    buffer[0] = X;
    buffer[1] = Y;

}

template<typename T>
inline void Vector2D<T>::setv(const T coords[3])
{
    X = coords[0];
    Y = coords[1];
}

template<typename T>
inline void Vector2D<T>::get(T& x, T& y) const
{
    x = X;
    y = Y;
}

template<typename T>
inline void Vector2D<T>::set(const T& x, const T& y)
{
    X = x;
    Y = y;
}

template<typename T>
inline const T& Vector2D<T>::operator[] (size_t index) const
{
    switch (index)
    {
        case 0:
            return X;
        case 1:
            return Y;
    }

    return T();
}

template<typename T>
inline T& Vector2D<T>::operator[] (size_t index)
{
    switch (index)
    {
        case 0:
            return X;
        case 1:
            return Y;
    }

    return T();
}

template<typename T>
inline const T& Vector2D<T>::operator() (size_t column) const
{
    switch (column)
    {
        case 1:
            return X;
        case 2:
            return Y;
    }

    return T();
}

template<typename T>
inline T& Vector2D<T>::operator() (size_t column)
{
    switch (column)
    {
        case 1:
            return X;
        case 2:
            return Y;
    }

    return T();
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator+ () const
{
    return *this;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator+ (const Vector2D& other) const
{
    return Vector2D(X + other.X, Y + other.Y);
}

template<typename T>
inline Vector2D<T>& Vector2D<T>::operator+= (const Vector2D& other)
{
    return *this = *this + other;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator- () const
{
    return Vector2D(-X, -Y);
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator- (const Vector2D& other) const
{
    return Vector2D(X - other.X, Y - other.Y);
}

template<typename T>
inline Vector2D<T>& Vector2D<T>::operator-= (const Vector2D& other)
{
    return *this = *this - other;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator* (const T& scalar) const
{
    return Vector2D(X*scalar, Y*scalar);
}

template<typename T>
inline Vector2D<T>& Vector2D<T>::operator*= (const T& scalar)
{
    return *this = *this * scalar;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::operator/ (const T& scalar) const
{
    return Vector2D(X/scalar, Y/scalar);
}

template<typename T>
inline Vector2D<T>& Vector2D<T>::operator/= (const T& scalar)
{
    return *this = *this / scalar;
}

template<typename T>
inline const T Vector2D<T>::operator* (const Vector2D& other) const
{
    return X*other.X + Y*other.Y ;
}
/*
template<typename T>
inline const Vector2D<T> Vector2D<T>::operator% (const Vector2D& other) const
{
    return Vector2D(Y*other.Z - Z*other.Y,
                    Z*other.X - X*other.Z,
                    X*other.Y - Y*other.X);
}

template<typename T>
inline Vector2D<T>& Vector2D<T>::operator%= (const Vector2D& other)
{
    return *this = *this % other;
}
*/
template<typename T>
inline const T Vector2D<T>::getSqrLen() const
{
    return X*X + Y*Y;
}

template<typename T>
inline const T Vector2D<T>::getLen() const
{
    return std::sqrt(getSqrLen());
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::getUnit() const
{
    if (getSqrLen() != 0)
        return *this / getLen();

    return *this;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::getInterpolation(const Vector2D& other, const T& ratio) const
{
    return *this + (other - *this)*ratio;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::getReflection(const Vector2D& surfaceNormal) const
{
    return *this - surfaceNormal*((*this * surfaceNormal)*2);
}


template<typename T>
inline const Vector2D<T> Vector2D<T>::
getRotationEuler(const Vector2D& angles, const Vector2D& origin, bool degs, bool ccw) const

{
    T sin_phi, sin_theta, sin_psi;
    T cos_phi, cos_theta, cos_psi;

    if (degs)
    {
        const T degToRad = T(M_PI)/360;

        sin_phi = std::sin(angles.getX()*degToRad);
        sin_theta = std::sin(angles.getY()*degToRad);

        cos_phi = std::cos(angles.getX()*degToRad);
        cos_theta = std::cos(angles.getY()*degToRad);
    }
    else
    {
        sin_phi = std::sin(angles.getX());
        sin_theta = std::sin(angles.getY());

        cos_phi = std::cos(angles.getX());
        cos_theta = std::cos(angles.getY());
    }

    if (!ccw)
    {
        sin_phi = -sin_phi;
        sin_theta = -sin_theta;
        sin_psi = -sin_psi;
    }

    Vector2D temp = *this - origin;
    Vector2D result = temp;

    result.setY( temp.getY()*cos_phi + temp.getY()*sin_phi);
    temp = result;

    result.setX(temp.getX()*cos_theta - temp.getY()*sin_theta);

    temp = result;

    result.setX( temp.getX()*cos_psi + temp.getY()*sin_psi);
    result.setY(-temp.getX()*sin_psi + temp.getY()*cos_psi);

    return result + origin;
}

template<typename T>
inline const Vector2D<T> Vector2D<T>::
getRotationArbAxis(const Vector2D& axis, const T& amount, const Vector2D& origin, bool degs, bool ccw) const
//todo vector2d   
{
    T cos_theta, sin_theta;

    if (degs)
    {
        const T degToRad = T(M_PI)/360;

        cos_theta = std::cos(amount*degToRad);
        sin_theta = std::sin(amount*degToRad);
    }
    else
    {
        cos_theta = std::cos(amount);
        sin_theta = std::sin(amount);
    }

    if (!ccw)
        sin_theta = -sin_theta;

    return *this*cos_theta + (axis % *this)*sin_theta + axis*((axis * *this)*(1 - cos_theta));
}