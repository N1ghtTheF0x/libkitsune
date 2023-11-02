#ifndef __N1GHTTHEF0X_LIBKITSUNE_MATH_VECTOR_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MATH_VECTOR_HPP

#include "../Math.hpp"
#include "../Numbers.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Math
        {
            template<typename Type>
            class IVector2
            {
            protected:
                using Vector = IVector2<Type>;
                Type _x;
                Type _y;
            public:
                IVector2(const Type x,const Type y): _x(x), _y(y) {}
                Type x() const {return _x;}
                Type y() const {return _y;}
                Vector &setX(Type x) {_x = x;return *this;}
                Vector &setY(Type y) {_y = y;return *this;}
                Vector &add(const Vector &other)
                {
                    _x += other._x;
                    _y += other._y;
                    return *this;
                }
                Vector operator+(const Vector &other)
                {
                    return add(other);
                }
                Vector &subtract(const Vector &other)
                {
                    _x -= other._x;
                    _y -= other._y;
                    return *this;
                }
                Vector operator-(const Vector &other)
                {
                    return subtract(other);
                }
                float length() const
                {
                    return squareRoot(_x*_x+_y*_y);
                }
                Vector &scalar(const Type other)
                {
                    _x *= other;
                    _y *= other;
                    return *this;
                }
                Vector operator*(const Type &other)
                {
                    return scalar(other);
                }
                Type dot(const Vector &other) const
                {
                    return _x * other._x + _y * other._y;
                }
            };
            typedef IVector2<float> Vector2;
            typedef IVector2<s32> Vector2I;

            template<typename Type>
            class IVector3 : public IVector2<Type>
            {
            protected:
                using Vector = IVector3<Type>;
                Type _z;
            public:
                IVector3(const Type x,const Type y,const Type z): IVector2(x,y), _z(z) {}
                Type z() const {return _z;}
                Vector &setZ(Type z) {_z = z;return *this;}
                Vector &add(const Vector &other)
                {
                    _x += other._x;
                    _y += other._y;
                    _z += other._z;
                    return *this;
                }
                Vector operator+(const Vector &other)
                {
                    return add(other);
                }
                Vector &subtract(const Vector &other)
                {
                    _x -= other._x;
                    _y -= other._y;
                    _z -= other._z;
                    return *this;
                }
                Vector operator-(const Vector &other)
                {
                    return subtract(other);
                }
                float length() const
                {
                    return squareRoot(_x*_x+_y*_y+_z*_z);
                }
                Vector &scalar(const Type other)
                {
                    _x *= other;
                    _y *= other;
                    _z *= other;
                    return *this;
                }
                Vector operator*(const Type &other)
                {
                    return scalar(other);
                }
                Type dot(const Vector &other) const
                {
                    return _x * other._x + _y * other._y + _z * other._z;
                }
                Vector cross(const Vector &other) const
                {
                    return Vector(_y*other._z - _z*other._y,_z*other._x - _x*other._z,_x*other._y - _y*other._x);
                }
                Vector operator*(const Vector &other) const
                {
                    return cross(other);
                }
            };
            typedef IVector3<float> Vector3;
            typedef IVector3<s32> Vector3I;
        }
    }
}

#endif