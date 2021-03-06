//
// Created by Павел Ганин on 18.05.2018.
//

#ifndef CHAIN_OF_KNOTS_VECTOR3D_H
#define CHAIN_OF_KNOTS_VECTOR3D_H

#include <iostream>
using namespace std;
template<typename T>
class Vector3D
{
private:
    T X;
    T Y;
    T Z;

public:

    Vector3D();

    template<typename R>
    explicit Vector3D(const Vector3D<R>& other);

    Vector3D(const T& x, const T& y, const T& z);

    Vector3D(const T coords[3]);

    const T& getX() const;
    void setX(const T& newX);

    const T& getY() const;
    void setY(const T& newY);

    const T& getZ() const;
    void setZ(const T& newZ);

    void getv(T buffer[3]) const;
    void setv(const T coords[3]);

    void get(T& x, T& y, T& z) const;
    void set(const T& x, const T& y, const T& z);

    // Interface for indexing

    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    //! Considering vectors as matrices with one row
    const T& operator() (size_t column) const;
    T& operator() (size_t column);

    // Standard operations

    //! This does absolutely nothing, but it should be included for consistency
    const Vector3D operator+ () const;

    const Vector3D operator+ (const Vector3D& other) const;
    Vector3D& operator+= (const Vector3D& other);

    //! The same as multiplying *this by -1
    const Vector3D operator- () const;

    const Vector3D operator- (const Vector3D& other) const;
    Vector3D& operator-= (const Vector3D& other);

    //! Multiplying *this by a scalar
    const Vector3D operator* (const T& scalar) const;
    Vector3D& operator*= (const T& scalar);

    //! Same as multiplication by 1/scalar, maybe more accurate but also slower
    const Vector3D operator/ (const T& scalar) const;
    Vector3D& operator/= (const T& scalar);

    //! Calculate the dot/inner/scalar product
    const T operator* (const Vector3D& other) const;

    //! Calculate the cross/outer/vector product
    const Vector3D operator% (const Vector3D& other) const;
    Vector3D& operator%= (const Vector3D& other);

    // Auxiliary methods

    //! Returns the squared length of *this
    const T getSqrLen() const;
    //! Returns the length of *this
    const T getLen() const;

    //! Returns a vector with the same orientation, but with a length of 1
    const Vector3D getUnit() const;

    //! Interpolates *this between another vector, by a ratio
    const Vector3D getInterpolation(const Vector3D& other, const T& ratio) const;

    //! Reflects *this according to a surface's normal
    const Vector3D getReflection(const Vector3D& surfaceNormal) const;

    //! Rotates *this about an origin, using Euler angles( X=pitch, Y=yaw, Z=roll)
    const Vector3D getRotationEuler(const Vector3D& angles,
                                    const Vector3D& origin = Vector3D(), bool degs = true, bool ccv = false) const;

    //! Rotates *this about an origin, using an arbitrary axis( axis should be a unit vector )
    const Vector3D getRotationArbAxis(const Vector3D& axis, const T& amount,
                                      const Vector3D& origin = Vector3D(), bool degs = true, bool ccv = false) const;
};


#endif //CHAIN_OF_KNOTS_VECTOR3D_H
