#include <nbody/rungekutta.h>
#include <nbody/Vector3.h>
#include <nbody/body.h>

namespace nbody{

	void updateBody( Body& body0, float dt, float dampingFactor ){
	  Vector3f r0, v0, a0, k1, k2, k3, k4;
	  /* Body BodyArray[5];
	  BodyArray[0] = body0;
	  float kv[4];
	  float kr[4];
		r0 = body0.position();
		v0 = body0.velocity();
		a0 = body0.accel();
		kv[0] = a0;
		kr[0] = v0;
		for ( int i = 1; i < 5; ++i){
		  BodyArray[i].velocity() = BodyArray[0].velocity() + kv[0]*dt;
		  
		  }*/
		k1 = (v + (a * dt))*dt;
		k2 = (v + 0.5f*k1 + (a * 1.5f * dt))*dt;
		k3 = (v + 0.5f*k2 + (a * 2.0f * dt))*dt;
		k4 = (v + 0.5f*k3 + (a * 2.5f * dt))*dt;

		v = v + (a * dt);
		v = v * dampingFactor;
		r = r + 1.0f/6.0f*( k1 + 2.0f*k2 + 2.0f*k3 + k4 );*/

		body.position() = r;
		body.velocity() = v;


	}
	
} // namespace nbody
