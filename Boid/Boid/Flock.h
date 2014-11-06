#ifndef _CENTOCELLFLOCK_H_
#define _CENTOCELLFLOCK_H_

#include "kdtree.h"
#include "Boid.h"
#include <map>
#include <vector>

using namespace std;

// action define
typedef Vector3f(* Action)( vector<Boid>, Boid, const void * );

enum RULE
{
	COHESION = 0,						// BASIC rule, always on
	ALLIGNMENT,							// BASIC rule, always on
	SEPARATION,							// BASIC rule, always on
	FOLLOW,								// follow a boid (leader)
	FLEE,								// flee from a predator
	GRAVITY,							// gravity law implementation
	AVOIDOBJECT							// avoid object during simulation
};

class Flock {
public:
	
	kdtree * k3;

	// constructor methods
	Flock();								// default (null) constructor
	Flock(const Flock &f);					// copy constructor

	// to do: generalize the method by accepting a binary file
	Flock(const char*fileText);				// build a flock from a text file (get a list of boids)

	//! overloading operators not inlined
	Flock& operator=(const Flock& f);		// assignment operator
	
	//! update flock method
	vector<Boid> update();							// update flock

	//! set the rule. If RULE is true, then setRule sets the rule to false, otherwise sets the rule to true
	bool setRule(RULE);

	//! add a boid to the flock
	void addBoid(Boid);

	//! return the boids of the flock
	//vector<Boid> getBoids();

	//! destructor method
	virtual ~Flock();
private:
	vector<Boid> boids;					// set of boids
	map<RULE,bool> rules;
	map<RULE,Action> actions;
	void addActions(RULE r);

	// private method
	void baseConstructorOperations();
};
/*

*/



#endif