#include "Flock.h"
#include "Rules.h"
#include <iostream>
#include <fstream>
#include <string>

vector<string> split(const char *str, char c = ' ')
{
	vector<string> result;
	do
	{
		const char *begin = str;

		while(*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}

void Flock::baseConstructorOperations()
{
	k3 = kd_create(3);
	//leaderBoid = NULL;
	for (int i = 0; i < 3; i++)
		rules[(RULE)i]=true;
}

Flock::Flock()
{
	/*
	k3 = kd_create(3);
	//leaderBoid = NULL;
	for (int i = 0; i < 3; i++)
		rules[(RULE)i]=true;	
	*/
	baseConstructorOperations();
	//boids = NULL;
	int index=0;
	for(int i=0;i<10;i++)
	{
		// only for test
		Vector3f v = Vector3f(float(i), float(i+1), float(i+2));
		Boid *b = new Boid(v,2*v,3*v,1,1,1,1);
		addBoid(*b);
		kd_insert3f(k3,float(i),float(i+1),float(i+2),b);
	}
}

// to do
Flock::Flock(const Flock& f) 
{
	rules = f.rules;
	actions = f.actions;
	boids = f.boids;
}

Flock::Flock(const char* fileText)
{
	baseConstructorOperations();
	long int nBoids = 0;
	string line;
	ifstream  boidsFile(fileText);
	
	if (boidsFile.is_open())
	{
		while( getline(boidsFile,line) )
		{
			vector<string> values = split(line.c_str(),'\t');
			if(!values[0].compare("#"))
				continue;
			
			Vector3f pos = Vector3f(stof(values[0]),stof(values[1]),stof(values[2]));
			Vector3f vel = Vector3f(stof(values[3]),stof(values[4]),stof(values[5]));
			Vector3f acc = Vector3f(stof(values[6]),stof(values[7]),stof(values[8]));
			float m = stof(values[9]);
			float v = stof(values[10]);
			float a = stof(values[11]);
			float f = stof(values[12]);
			Boid *b = new Boid(pos, vel, acc, m, v, a, f);
			addBoid(*b);
			kd_insert3f(k3, pos.x, pos.y, pos.z, b);

			nBoids++;
		}
		boidsFile.close();
	}
	cout <<"Loaded "<<nBoids<<" boids from file"<<"\n";
}

void Flock::addBoid(Boid b){this->boids.push_back(b);}

bool Flock::setRule(RULE r)
{
	rules[r] = !rules[r];
	return rules[r];
}

//vector<Boid> Flock::getBoids() {return boids;}

vector<Boid> Flock::update()
{
	// to do
	// saving new value in the _"vector3f" variable of the boid object

	// switch 
	for (vector<Boid>::iterator bi = boids.begin() ; bi != boids.end(); ++bi)
		bi->update();		

	return boids;
}

Flock::~Flock()
{
	kd_free(k3);
	
}







/*
void Flock::addActions(RULE r)
{
	switch (r)
	{
	case COHESION:
		actions[r] = ;
		break;
	case ALLIGNMENT:
		actions[r] = ;
		break;
	case SEPARATION:
		actions[r] = ;
		break;
	case FOLLOW:
		actions[r] = ;
		break;
	case FLEE:
		actions[r] = ;
		break;
	case GRAVITY:
		actions[r] = ;
		break;
	case AVOIDOBJECT:
		actions[r] = ;
		break;
	default:
		break;
	} 
}
*/
