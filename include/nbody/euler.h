#ifndef _NBODY_INTEGRATOR_EULER_H
#define _NBODY_INTEGRATOR_EULER_H

#include <nbody/body.h>
#include <nbody/integrator.h>

namespace nbody{

	class Euler : public Integrator{
		Euler(const Euler& integrator) = 0;
		Euler& operator= (Euler integrator) = 0;

	public:
		Euler() {}
		~Euler() {}
		updateBody( Body& body, float dt );

	};

} // namespace nbody

#endif // _NBODY_INTEGRATOR_EULER_H