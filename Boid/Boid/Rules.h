#ifndef _CENTOCELLRULES_H_
#define _CENTOCELLRULES_H_

#include "Boid.h"
#include "kdtree.h"

typedef struct LeaderFunctionParmas
{
	float followParam;
	Boid leaderBoid;
} LeaderFunctionParmas;



// steering implementation 
Vector3f steering(Boid * currentBoid, Vector3f *target)
{
	Vector3f desired = *target - currentBoid->position ;
	
	desired.normalize();
	desired *= currentBoid->maxVelocity;
	desired -= currentBoid->velocity;
	//max speed option
	desired.setMagnitude(currentBoid->maxForce);
	
	return desired;
}

// COHESION RULE IMPLEMENTATION
Vector3f cohesionRule( kdres *nearestBoidsSet, Boid *currentBoid, void *params )
{
	Vector3f steer = Vector3f();
	float pos[3];
	float cohesionParam = *((float*)params);
	int dimSet=kd_res_size(nearestBoidsSet)-1;
	if(dimSet>0)
	{
		while( !kd_res_end( nearestBoidsSet ) )
		{
			Boid *b = (Boid *)(kd_res_itemf( nearestBoidsSet, pos ));
			
			if(b != currentBoid)
				steer += b->position;

			kd_res_next( nearestBoidsSet );
		}

		steer /= float(dimSet);
		steer =  cohesionParam * steering(currentBoid, &steer);
	}
	return steer;
}

// ALIGNMENT RULE IMPLEMENTATION
Vector3f alignmentRule( kdres *nearestBoidsSet, Boid *currentBoid, void *params )
{
	Vector3f steer = Vector3f();
	float pos[3];
	float allignmentParam = *((float*)params);
	int dimSet=kd_res_size(nearestBoidsSet)-1;
	if(dimSet>0)
	{
		while( !kd_res_end( nearestBoidsSet ) )
		{
			Boid *b = (Boid *)(kd_res_itemf( nearestBoidsSet, pos ));

			if(b != currentBoid)
				steer += b->velocity;

			kd_res_next( nearestBoidsSet );
		}

		steer.normalize();
		steer *= currentBoid->maxVelocity;
		steer -= currentBoid->velocity;
		steer.setMagnitude(currentBoid->maxForce);
		steer *=  allignmentParam;
	}
	return steer;
}

// SEPARATION RULE IMPLEMENTATION
Vector3f separationRule( kdres *nearestBoidsSet, Boid *currentBoid, void *params )
{
	Vector3f steer = Vector3f();
	float pos[3];
	float separationnParam = *((float*)params);
	int dimSet=kd_res_size(nearestBoidsSet)-1;

	if(dimSet>0)
	{
		while( !kd_res_end( nearestBoidsSet ) )
		{
			Boid *b = (Boid *)(kd_res_itemf( nearestBoidsSet, pos ));

			if(b != currentBoid)
			{
				Vector3f tempVector = b->position - currentBoid->position;
				tempVector *= tempVector.length();
				steer -= tempVector;
			}

			kd_res_next( nearestBoidsSet );
		}
		steer.normalize();
		steer *= currentBoid->maxVelocity;
		steer -= currentBoid->velocity;
		steer.setMagnitude(currentBoid->maxForce);
		steer *=  separationnParam;
	}
	return steer;
}

// Follow
Vector3f followRule(kdres *nearestBoidsSet, Boid *currentBoid, void *params )
{
	Vector3f steer;
	LeaderFunctionParmas *lfp = (LeaderFunctionParmas*)params;
	float followParam  = lfp->followParam;
	Boid * leaderBoid = &lfp->leaderBoid;
	if(leaderBoid!=NULL)
	{
		steer = steering(currentBoid, &leaderBoid->position);
		steer *= followParam;
	}
	return steer;
}

// Wander
/*
void wanderRule(Kdres *nearestBoidsSet, Boid * currentBoid, Vector * steer)
{
	Vector circle,circleOffset;
	double wanderR,wanderD,change,value;


	wanderR=16;
	wanderD=60;
	change=0.25;

	// limiting random value in [-value/2][value/2] range
	value = change*rand();
	value /= (RAND_MAX+1);
	value -= change/2;
	currentBoid->wanderTheta+=value;

	copyVector(&currentBoid->currentVelocity,&circle);
	normalize(&circle);
	multiply(&circle,wanderD,&circle);
	addVector(&circle,&currentBoid->currentPosition,&circle);

	//always "wander" on the xy plane
	// to do, changing the "wander" plane 
	circleOffset.x=wanderR*cos(currentBoid->wanderTheta);
	circleOffset.y=wanderR*sin(currentBoid->wanderTheta);
	circleOffset.z=0;

	addVector(&circleOffset,&circle,&circle);
	steering(currentBoid,&circle,steer);
}
*/

#endif