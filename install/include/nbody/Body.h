#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H
#include <nbody/Vector3.h>

#include <iosfwd>

namespace nbody {

	class Body {
		Vector3f _position;
		Vector3f _velocity;
		Vector3f _accel;
		float _mass;
	public:
		Body() : _position{}, _velocity{}, _accel{}, _mass{} {}
		inline Vector3f position() const { return _position; }
		inline Vector3f& position() { return _position; }
		inline Vector3f velocity() const { return _velocity; }
		inline Vector3f& velocity() { return _velocity; }
		inline Vector3f accel() const { return _accel; }
		inline Vector3f& accel() { return _accel; }
		inline float mass() const { return _mass; }
		friend std::istream& operator>>( std::istream &is, Body &body );
		friend std::ostream& operator<<( std::ostream &os, const Body &body );
	};
} // namespace nbody

#endif // _NBODY_BODY_H
