#ifndef _NBODY_INTEGRATOR_EULER_H
#define _NBODY_INTEGRATOR_EULER_H

#include <nbody/integrator.h>
#include <nbody/body.h>

namespace nbody{

	class Euler : public Integrator{
		Euler(const Euler& integrator) = 0;
		Euler& operator= (Euler integrator) = 0;

	public:
		Euler() {}
		~Euler() {}

		void updateBody( Body& body, float dt, float dampingFactor );
	};

} // namespace nbody

#endif // _NBODY_INTEGRATOR_EULER_H