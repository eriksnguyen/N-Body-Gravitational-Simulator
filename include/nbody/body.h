#ifndef _NBODY_BODY_H
#define _NBODY_BODY_H

namespace nbody{
	class Body{
		Vector3d _position;
		Vector3d _velocity;
		Vector3d _acceleration;
		double _mass;
	public:
		Body{
			
		}
	};

} // namespace nbody

#endif //_NBODY_BODY_H