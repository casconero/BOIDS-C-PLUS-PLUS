#include "Vector3f.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Vector3f * v1 = new Vector3f(1,2,3);
	cout<<"v1: "<<v1->x<<" " <<v1->y<<" " <<v1->z<<"\n" ;
	Vector3f * v2 = new Vector3f(*v1);
	cout<<"v2: "<<v2->x<<" " <<v2->y<<" " <<v2->z<<"\n" ;

	Vector3f v3=Vector3f(2,2,2);
	cout<<"v3: "<<v3.x<<" " <<v3.y<<" " <<v3.z<<"\n" ;
	Vector3f v4=v3 + *v2;
	cout<<"v4: "<<v4.x<<" " <<v4.y<<" " <<v4.z<<"\n" ;
	v4=4*v4;
	cout<<"v4: "<<v4.x<<" " <<v4.y<<" " <<v4.z<<"\n" ;
	Vector3f v5= v4*2;
	cout<<"v5: "<<v5.x<<" " <<v5.y<<" " <<v5.z<<"\n" ;
	getchar();
	return 0;
}
