#ifndef _CENTOCELLBOID_H_
#define _CENTOCELLBOID_H_

#include "../../BoidMath/BoidMath/Vector3f.h"

// Boid
class Boid {
public:
	
	Vector3f position;
	Vector3f velocity;
	Vector3f acceleration;
	
	//long int id;
	float mass;
	float maxVelocity;
	float maxAcceleration;
	float maxForce;

	// constructor methods
	Boid();										// default (null) constructor
	Boid(Vector3f position, Vector3f velocity, Vector3f acceleration, float mass, float maxVelocity, float maxAcceleration, float maxForce);	
	Boid(const Boid &b);						// copy constructor


	//! "==" EQUAL
	bool operator ==(const Boid b) { return this->acceleration==b.acceleration && this->position==b.position && this->velocity==b.velocity && this->mass==b.mass && this->maxAcceleration==b.maxAcceleration && this->maxVelocity==b.maxVelocity && this->maxForce==b.maxForce;}
	//! "!=" NOT EQUAL
	bool operator !=(const Boid b) {return !(this==&b);}

	//! overloading operators not inlined
	Boid& operator=(const Boid& b);		// assignment operator
	

	void update();
	//! destructor method
    virtual ~Boid();
private:

	Vector3f _position;			// position 1 step before
	Vector3f _velocity;			// velocity 1 step before
	Vector3f _acceleration;		// acceleration 1 step before
	};
#endif