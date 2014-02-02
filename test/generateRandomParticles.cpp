#include <nbody/Vector3.h>
#include <nbody/Body.h>
#include <cstdio>

void generateRandomParticles(){
	Body bodyArray[1024];
	for ( i = 0; i < 1024; ++i ){
		bodyArray[i].position() = (float)rand()/(float)(RAND_MAX) * 20 - 10;
		bodyArray[i].velocity() = (float)rand()/(float)(RAND_MAX) * 2 - 1;
		bodyArray[i].accel() = 0;
	}
}