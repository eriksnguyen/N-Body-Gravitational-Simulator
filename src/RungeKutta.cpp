#include <nbody/rungekutta.h>
#include <nbody/Vector3.h>
#include <nbody/body.h>

namespace nbody{

	void updateBody( Body& body, float dt, float dampingFactor ){
		Vector3 r, v, a, k1, k2 k3, k4;

		r = body.position();
		v = body.velocity();
		a = body.accel();
		k1 = (v + (a * dt))*dt;
		k2 = (v + 0.5*k1 + (a * 1.5 * dt))*dt;
		k3 = (v + 0.5*k2 + (a * 2 * dt))*dt;
		k4 = (v + 0.5*k3 + (a * 2.5 * dt))*dt;

		v = v + (a * dt);
		v = v * dampingFactor;
		r = r + 1.0f/6.0f*( k1 + 2*k2 + 2*k3 + k4 );

		body.position() = r;
		body.velocity() = v;


	}
	
} // namespace nbody