#include"Ray.h"

//��ʼ��
Ray::Ray(Point3D p, Vector3D v) {
	this->p = p.clone();
	this->v = v.clone().normalized();
}