#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H

namespace nbody{
	class Body{
		Vector3f _position; 
		Vector3f _velocity;
		Vector3f _acceleration;
		double _mass;
	public:
		Body(): _position{}, _velocity{}, _acceleration{}, _mass{} {}
		inline Vector3f position() const { return _position; }
		inline Vector3f& position() { return _position; }
		inline Vector3f velocity() const { return _velocity; }
		inline Vector3f& velocity() { return _velocity; }
		inline Vector3f acceleration() const { return _acceleration; }
		inline Vector3f& acceleration() { return _acceleration; }
		inline float mass() const { return _mass; }
		friend std::istream& operator>>( std::istream &is, Body &body );
		friend std::ostream& operator<<( std::ostream &os, const Body &body );
	};

} // namespace nbody

#endif //_NBODY_BODY_H