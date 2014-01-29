#ifndef _NBODY_BODYSYSTEM_H
#define _NBODY_BODYSYSTEM_H

#include <nbody/body.h>

#include <iosfwd>
#include <string>

namespace nbody{
	//Container for the bodies in the simulation
	class BodySystem{
		size_t _N; // number of bodies in the simulation
		Body * _elements; // the bodies in the simulation

		const float _EPSILON = 1e-12;
		const float _MAXSIMTIME;
		float _simTime = 0.0;

		BodySystem() = delete;
		BodySystem( const BodySystem& sys) = delete;
		BodySystem& operator= (BodySystem sys) = delete;
	public:
		BodySystem( size_t N, size_t maxTime );
		BodySystem( std::istream& input );
		BodySystem( std::string filename );
		~BodySystem();

		
		void calculateAccel( size_t elem ); // Calculates the acceleration that the body at index 'elem' experiences instantaneously
		void updateSystem( float dt ); // updates the system by dt

		inline float getSimTime() const { return _simTime; }

	};

} // namespace nbody

#endif // _NBODY_BODYSYSTEM_H