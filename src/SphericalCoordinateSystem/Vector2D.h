//
// Created by Павел Ганин on 18.05.2018.
//

#ifndef CHAIN_OF_KNOTS_VECTOR2D_H
#define CHAIN_OF_KNOTS_VECTOR2D_H


#include <iostream>
using namespace std;
template<typename T>
class Vector2D
{
private:
    T X;
    T Y;

public:

    Vector2D();

    template<typename R>
    explicit Vector2D(const Vector2D<R>& other);

    Vector2D(const T& x, const T& y);

    Vector2D(const T coords[2]);

    const T& getX() const;
    void setX(const T& newX);

    const T& getY() const;
    void setY(const T& newY);

    void getv(T buffer[2]) const;
    void setv(const T coords[2]);

    void get(T& x, T& y) const;
    void set(const T& x, const T& y);

    // Interface for indexing

    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    //! Considering vectors as matrices with one row
    const T& operator() (size_t column) const;
    T& operator() (size_t column);

    // Standard operations

    //! This does absolutely nothing, but it should be included for consistency
    const Vector2D operator+ () const;

    const Vector2D operator+ (const Vector2D& other) const;
    Vector2D& operator+= (const Vector2D& other);

    //! The same as multiplying *this by -1
    const Vector2D operator- () const;

    const Vector2D operator- (const Vector2D& other) const;
    Vector2D& operator-= (const Vector2D& other);

    //! Multiplying *this by a scalar
    const Vector2D operator* (const T& scalar) const;
    Vector2D& operator*= (const T& scalar);

    //! Same as multiplication by 1/scalar, maybe more accurate but also slower
    const Vector2D operator/ (const T& scalar) const;
    Vector2D& operator/= (const T& scalar);

    //! Calculate the dot/inner/scalar product
    const T operator* (const Vector2D& other) const;

    //! Calculate the cross/outer/vector product
    const Vector2D operator% (const Vector2D& other) const;
    Vector2D& operator%= (const Vector2D& other);

    // Auxiliary methods

    //! Returns the squared length of *this
    const T getSqrLen() const;
    //! Returns the length of *this
    const T getLen() const;

    //! Returns a vector with the same orientation, but with a length of 1
    const Vector2D getUnit() const;

    //! Interpolates *this between another vector, by a ratio
    const Vector2D getInterpolation(const Vector2D& other, const T& ratio) const;

    //! Reflects *this according to a surface's normal
    const Vector2D getReflection(const Vector2D& surfaceNormal) const;

    //! Rotates *this about an origin, using Euler angles( X=pitch, Y=yaw)
    const Vector2D getRotationEuler(const Vector2D& angles,
                                    const Vector2D& origin = Vector2D(), bool degs = true, bool ccv = false) const;

    //! Rotates *this about an origin, using an arbitrary axis( axis should be a unit vector )
    const Vector2D getRotationArbAxis(const Vector2D& axis, const T& amount,
                                      const Vector2D& origin = Vector2D(), bool degs = true, bool ccv = false) const;
};

#endif //CHAIN_OF_KNOTS_VECTOR2D_H
