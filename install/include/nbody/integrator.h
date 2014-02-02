#ifndef _NBODY_INTEGRATOR_H
#define _NBODY_INTEGRATOR_H

#include <nbody/Body.h>

namespace nbody{
	/**
	* Defines an abstract class that moves given particles through time steps.
	*/
	class Integrator{

	public:
		Integrator() {}
		virtual ~Integrator() {};
		virtual void updateBody( Body& body, float dt, float dampingFactor ) = 0;
	};
} // namespace nbody

#endif // _NBODY_INTEGRATOR_H
