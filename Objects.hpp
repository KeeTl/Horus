#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <array>
// #include <cmath>
#include <iostream>

namespace objects {        
    template <typename T = float>
    class Point {
        public:
            T x, y;
            Point(T x, T y): x(x), y(y) {}
            std::array<T, 2> getCoordinates() const {
                return {this->x, this->y};
            }
    };

    template <typename T = float>
    class Point3D {
        public:
            T x, y, z;
            Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
            std::array<T, 3> getCoordinates() const {
                return {this->x, this->y, this->z};
            }
    };

    template <typename T = float>
    class Vector : public Point<T>{
        public:
            Vector(T x, T y) : Point(x, y) {}
            
            Vector operator+(Vector& vect) {
                return Vector(this->x + vect.x, this->y + vect.y);
            }

            Vector operator*(float& scal) {
                return Vector(scal * this-> x, scal * this-> y);
            }

            float operator*(Vector& vect) {
                return this->x * vect.x + this->y * vect.y;
            }
    };

    template <typename T = float>
    class Vector3D : public Point3D<T> {
        public:
            Vector3D(T x, T y, T z) : Point3D(x, y, z) {}

            Vector3D operator+(Vector3D& vect) {
                    return Vector3D(this->x + vect.x, this->y + vect.y, this->z + vect.z);
                }
            
            Vector3D<T> operator*(float& scal) const {
                return Vector3D<T>(scal * this-> x, scal * this-> y, scal * this-> z);
            }

            float operator*(Vector3D& vect) const {
                return this->x * vect.x + this->y * vect.y + this->z * vect.z;
            }

    };

    template <typename T>
    inline float abs(const Vector<T>& vector) {
        return sqrt(pow((vector.x), 2) + pow((vector.y),2));
    }

    template <typename T>
    inline float abs(const Vector3D<T>& vector) {
        return sqrt( vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    }

    template <typename T, typename U>
    float getAngle(const Vector<T>& vectorA, const Vector<U>& vectorB) {
        return acos( (vectorA * vectorB) /abs(( vectorA ) * abs( vectorB )) );
    }

    template <typename T, typename U>
    float getAngle(const Vector3D<T>& vectorA, const Vector3D<U>& vectorB) {
        return acos(( vectorA * vectorB )/ abs(( vectorA )  *abs( vectorB )) );
    }

}

namespace obj = objects;

#endif // OBJECTS_HPP