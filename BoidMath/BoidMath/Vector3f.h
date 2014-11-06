#ifndef _CENTOCELLVECTOR_H_
#define _CENTOCELLVECTOR_H_

#include <math.h>
// 3 dimension vector (float)
class Vector3f {
public:

	float x,y,z;								// vector coordinates
	
	// constructor methods
	Vector3f();									// default (null) constructor
	Vector3f(float x, float y, float z);		// default 3 coordinates constructor
	Vector3f(const Vector3f &v);				// copy constructor
	
	//! overloading operators not inlined
	Vector3f& operator=(const Vector3f& v);		// assignment operator


	//! destructor method
    virtual ~Vector3f();

    // *********************************    
	//!* overloading operators inlined *
	// *********************************
	
	//! "==" EQUAL
    bool operator ==(const Vector3f v) { return this->x==v.x && this->y==v.y && this->z==v.z;}

    //! "!=" NOT EQUAL
    bool operator !=(const Vector3f v) {return !(this==&v);}

    //! "+=" ADD
    Vector3f& operator +=(const Vector3f& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    //! "+" ADD
    Vector3f operator +(const Vector3f& a) {return Vector3f(*this) += a;}

    //! "-=" SUB
    Vector3f& operator -=(const Vector3f& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    //! "-" SUB
    Vector3f operator -(const Vector3f& a) {return Vector3f(*this) -= a;}

	// "-" negation (unary operation)
	Vector3f operator -(void) {return Vector3f(-x, -y, -z);}

    //! "*=" SCALING (float)
    Vector3f& operator *=(float d)
    {
        Vector3f temp = Vector3f(*this);
        x = temp.x * d;
        y = temp.y * d;
        z = temp.z * d;
        return *this;
    }

    //! "/=" SCALING (float)
    Vector3f& operator /=(float d)
    {
        Vector3f temp = Vector3f(*this);
        x = temp.x / d;
        y = temp.y / d;
        z = temp.z / d;
        return *this;
    }

    //! "*=" DOT PRODUCT
    float operator *=(const Vector3f& v) const { return x * v.x + y * v.y + z * v.z; }
    
    //! "*" DOT PRODUCT
    float operator *(const Vector3f& v) const{return Vector3f(*this) *= v;}
	
	// ***************************    
	//!* 		methods          *
	// ***************************    

	//! gets the length of this vector squared
	float length_squared() const { return (float)(*this * *this);}

	//! gets the length of this vector (length or magnitude)
	float length() const { return (float)sqrt(*this * *this); }

	//! normalizes this vector
	void normalize() { *this /= length();}

	//! projects this vector onto v
	void project(const Vector3f &v) {*this *= (*this * v)/(v * v);}

	//! returns this vector projected onto v
	Vector3f projected(const Vector3f &v)
	{
		Vector3f temp = Vector3f(*this);
		temp.project(v);
		return temp;
	}

	//! set magnitude value
	void setMagnitude(float magnitude)
	{
		this->normalize();
		*this *= magnitude;
	}
};

// ****************************************    
//!* overloading operators (commutatives) *
// ****************************************

inline Vector3f operator*(float d, Vector3f v){return v *= d;}
inline Vector3f operator*(Vector3f v, float d){return v *= d;}
inline Vector3f operator/(float d, Vector3f v){return v /= d;}
inline Vector3f operator/(Vector3f v, float d){return v /= d;}

//! computes the angle between 2 arbitrary vectors
inline float angle(const Vector3f &v1, const Vector3f &v2) { return acosf( (v1 * v2) / (v1.length() * v2.length()) ); }
//! computes the angle between 2 normalized arbitrary vectors
inline float angle_normalized(const Vector3f &v1, const Vector3f &v2) { return acosf(v1 * v2);}

#endif