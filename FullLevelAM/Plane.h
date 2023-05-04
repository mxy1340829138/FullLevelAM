//
// Created by MBP on 2023/4/18.
//

#ifndef FULLLEVELAM_PLANE_H
#define FULLLEVELAM_PLANE_H
#include <vector>
#include "Line.h"
namespace nsp {

	class Plane {

	public:
		Plane(Point3D p = Point3D(), Vector3D n = Vector3D()) : P(p), N(n) {}

		std::string toString();

		//Obtain the parameters of the standard straight line equation Ax+By+Cz+D=0
		std::vector<double> toFormula();

		std::string toString();

		//Returns the z-plane of a 3D point
		Plane zPlane(double z);

		//Returns the line segment obtained by intersecting two planes
		Line intersect(Plane pl);

		//The point through which the plane passes
		Point3D P;
		//Plane normal vector
		Vector3D N;

		bool operator==(Plane plane);

		bool operator!=(Plane plane);

	private:

	};
}
#endif //GCODE_PLANE_H
