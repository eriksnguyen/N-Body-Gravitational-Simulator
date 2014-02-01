#include <nbody/euler.h>
#include <nbody/Vector3.h>
#include <nbody/body.h>

namespace nbody{

	void Euler::updateBody( Body& body, float dt, float dampingFactor ) {
		Vector3f r, v, a;

		r = body.position();
		v = body.velocity();
		a = body.accel();

		v = v + ( a * dt );
      	v = v * dampingFactor;
		r = r + v * dt;

      	body.position() = r;
      	body.velocity() = v;
	}

} // namespace nbody