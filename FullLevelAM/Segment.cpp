#include"Segment.h"

//��ʼ��
Segment::Segment(Point3D a, Point3D b) {
	this->A = a.clone();
	this->B = b.clone();
}

//�����߶γ���
double Segment::length() {
	return A.distance(B);
}

//�����߶η���
Vector3D Segment::direction() {
	return A.pointTo(B);
}


//�����߶������˵�
void Segment::swap() {
	Point3D temp;
	temp = A;
	A = B;
	B = temp;
}