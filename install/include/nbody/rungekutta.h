#ifndef _NBODY_INTEGRATOR_RUNGEKUTTA_H
#define _NBODY_INTEGRATOR_RUNGEKUTTA_H

#include <nbody/integrator.h>
#include <nbody/Body.h>

namespace nbody{

	class RungeKutta : public Integrator {

	public:
		RungeKutta() {}
		~RungeKutta() {}

		void updateBody( Body& body, float dt, float dampingFactor ); 
	};

} // namespace nbody

#endif // _NBODY_INTEGRATOR_RUNGEKUTTA_H
