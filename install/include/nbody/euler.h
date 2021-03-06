#ifndef _NBODY_INTEGRATOR_EULER_H
#define _NBODY_INTEGRATOR_EULER_H

#include <nbody/integrator.h>
#include <nbody/Body.h>

namespace nbody{

	class Euler : public Integrator{
	public:
		Euler() {}
		~Euler() {}

		void updateBody( Body& body, float dt, float dampingFactor );
	};

} // namespace nbody

#endif // _NBODY_INTEGRATOR_EULER_H
