
#include "Boid.h"
#include "Flock.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// Boid b=Boid();
	// Boid * b2 = new Boid(Vector3f(1,1,1),Vector3f(2,2,2),Vector3f(3,3,3),1,2,3,1);
	// cout<<"Boid b.position="<<b.position.x<<" "<<b.position.y<<" "<<b.position.z<<"\n";
	// cout<<"Boid b2->position="<<b2->position.x<<" "<<b2->position.y<<" "<<b2->position.z<<"\n";
	
	
	float pos[3];
	/*
	Flock f = Flock();
	vector<Boid*> v;
	Boid b =Boid();
	b.mass=100;
	v.push_back(&b);
	Boid b2 =Boid();
	b2.mass=1000;
	v.push_back(&b2);
	cout<<"b.mass "<<v[0]->mass<<"b2.mass "<<v[1]->mass<<"\n";
	v[0]->mass =0.1;
	cout<<"b.mass "<<v[0]->mass<<"b2.mass "<<v[1]->mass<<"\n";

	kdres *bset = kd_nearest_range3f(f.k3, 1, 1, 1, 3);
	
	while( !kd_res_end( bset ) )
	{
		Boid *thisBoid = (Boid *)(kd_res_itemf( bset,pos));
		cout<< "x:"<<thisBoid->position.x<<"y:"<<thisBoid->position.y<<"z:"<<thisBoid->position.z<<"\n";
		cout<< "pos.x:"<<pos[0]<<"pos.y:"<<pos[1]<<"pos.z:"<<pos[2]<<"\n";
		kd_res_next( bset );
	}
	*/
	Flock f = Flock("D:\\Boids New Era\\resources\\boids.txt");
	kdres *bset = kd_nearest_range3f(f.k3, 1, 1, 1, 10);
	while( !kd_res_end( bset ) )
	{
		Boid *thisBoid = (Boid *)(kd_res_itemf( bset,pos));
		cout<< "x:"<<thisBoid->position.x<<"y:"<<thisBoid->position.y<<"z:"<<thisBoid->position.z<<"\n";
		cout<< "pos.x:"<<pos[0]<<"pos.y:"<<pos[1]<<"pos.z:"<<pos[2]<<"\n";
		kd_res_next( bset );
	}

	
	getchar();
	kd_res_free(bset);
	return 0;
}
