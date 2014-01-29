#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H

<<<<<<< HEAD
#include <nbody/Vector3.h>

#include <iosfwd>

namespace nbody {

  class Body {
    Vector3f _position;
    Vector3f _velocity;
    Vector3f _force;
    float _mass;
  public:
    Body() : _position{}, _velocity{}, _force{}, _mass{} {}
    inline Vector3f position() const { return _position; }
    inline Vector3f& position() { return _position; }
    inline Vector3f velocity() const { return _velocity; }
    inline Vector3f& velocity() { return _velocity; }
    inline Vector3f force() const { return _force; }
    inline Vector3f& force() { return _force; }
    inline float mass() const { return _mass; }
    friend std::istream& operator>>( std::istream &is, Body &body );
    friend std::ostream& operator<<( std::ostream &os, const Body &body );
  };
=======
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
>>>>>>> 67dc12d259a2fd62eaf87b3d79ced0f3b9a965f4

} // namespace nbody

#endif // _NBODY_BODY_H
