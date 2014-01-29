#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H

namespace nbody{
	class Body{
		Vector3d _position; // use double > float; will store doubles and print floats
		Vector3d _velocity;
		Vector3d _acceleration;
		double _mass;
	public:
		Body(): _position{}, _velocity{}, _acceleration{}, _mass{} {}
		inline Vector3d position() const { return _position; }
		inline Vector3d& position() { return _position; }
		inline Vector3d velocity() const { return _velocity; }
		inline Vector3d& velocity() { return _velocity; }
		inline Vector3d acceleration() const { return _acceleration; }
		inline Vector3d& acceleration() { return _acceleration; }
		inline float mass() const { return _mass; }
		friend std::istream& operator>>( std::istream &is, Body &body );
		friend std::ostream& operator<<( std::ostream &os, const Body &body );
	};

} // namespace nbody

#endif //_NBODY_BODY_H