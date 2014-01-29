#include <nbody/euler.h>
#include <nbody/Vector3.h>
#include <nbody/body.h>

namespace nbody{

	void Euler::updateBody( Body& body, float dt, float dampingFactor ) {
		Vector3 r, v, a;

		r = body.position();
		v = body.velocity();
		a = body.accel();

      	r = r + v * dt;//Update position before updating velocity
		v = v + ( a * dt );
      	v = v * dampingFactor;

      	body.position() = r;
      	body.velocity() = v;
	}

} // namespace nbody