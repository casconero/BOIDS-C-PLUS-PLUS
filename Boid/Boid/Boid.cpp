#include "Boid.h"

Boid::Boid(){
	//this.id = 1;			// TO DO: change the id creation
	mass = 1;
	maxVelocity = 1;
	maxAcceleration = 1;
	maxForce = 1;

	position = Vector3f();
	velocity = Vector3f();
	acceleration = Vector3f();

	_position = _velocity = _acceleration = Vector3f();
}

Boid::Boid(Vector3f position, Vector3f velocity, Vector3f acceleration, float mass, float maxVelocity, float maxAcceleration, float maxForce)
{
	//this.id = 1;			// TO DO: change the id creation
	this->mass = mass;
	this->maxVelocity = maxVelocity;
	this->maxAcceleration = maxAcceleration;
	this->maxForce = maxForce;

	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;

	_position = _velocity = _acceleration = Vector3f();
}


Boid::Boid(const Boid& b) 
{
 		//id = b.id;

		mass = b.mass;
		maxVelocity = b.maxVelocity;
		maxAcceleration = b.maxAcceleration;  
		maxForce = b.maxForce;

		position = b.position;
		velocity = b.velocity;
		acceleration = b.acceleration;

		_position = _position;
		_velocity = _velocity;
		_acceleration = _acceleration;
}


Boid& Boid::operator=(const Boid& b)
{
    if (this == &b) return *this; // handle self assignment
	{
		//id = b.id;

		mass = b.mass;
		maxVelocity = b.maxVelocity;
		maxAcceleration = b.maxAcceleration;  

		position = b.position;
		velocity = b.velocity;
		acceleration = b.acceleration;

		_position = _position;
		_velocity = _velocity;
		_acceleration = _acceleration;
	}
    return *this;
}

void Boid::update()
{
	Vector3f temp = _position;
	_position = this->position;
	this->position = temp;
	
	temp = _velocity;
	_velocity = this->velocity;
	this->velocity = temp;

	temp = _acceleration;
	_acceleration = this->acceleration;
	this->acceleration = temp;

}
Boid::~Boid() {}