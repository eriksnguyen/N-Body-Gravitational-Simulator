#ifndef _NBODY_SYSTEM_H
#define _NBODY_SYSTEM_H

#include <nbody/Vector3.h>
#include <nbody/Body.h>
#include <nbody/integrator>
#include <nbody/euler>

#include <iosfwd>
#include <string>

namespace nbody {

	class System {
		size_t _nBodies;
		Body* _body;
		Integrator* integrationScheme;
		float _softFactor = 1e-9f; //TODO: Change this to put into the calculations of distance
		float _dampingFactor = 1.0f;

		System() = delete;
		System( const System &sys ) = delete;
		System& operator=( const System &sys ) = delete;
		
	public:
		System( size_t N ) : _nBodies{N}, _body{ new Body[N] }, integrationScheme{new Euler()} { initRandomState(); }
		System( std::istream &input ) : _nBodies{}, _body{nullptr}, integrationScheme{new Euler()}  { readState( input ); }
		System( std::string filename ) : _nBodies{}, _body{nullptr}, integrationScheme{new Euler()}  { readState( filename ); }
		~System() { delete [] _body; delete integrationScheme}

		void interactBodies( size_t i, size_t j, float softFactor, Vector3f &acc ) const;
		void computeGravitation();
		void integrateSystem( float dt );
		void readState( std::istream &input );
		void readState( std::string filename );
		void writeState( std::ostream &output ) const;
		void writeState( std::string filename ) const;
		void initRandomState();
		void update( float dt );
		void setSoftening( float soft ) { _softFactor = soft; }
		void setDamping( float damp ) { _dampingFactor = damp; }
	};

} // namespace nbody

#endif // _NBODY_SYSTEM_H
