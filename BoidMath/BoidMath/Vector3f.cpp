#include "Vector3f.h"

Vector3f::Vector3f():x(0),y(0),z(0){}
Vector3f::Vector3f(float x0, float y0, float z0):x(x0),y(y0),z(z0){}
Vector3f::Vector3f(const Vector3f& v) { x = v.x; y = v.y; z = v.z; }
Vector3f& Vector3f::operator=(const Vector3f& v)
{
    if (this == &v) return *this; // handle self assignment
     {
        x = v.x;
        y = v.y;
        z = v.z;
     }
    return *this;
}

Vector3f::~Vector3f() {}