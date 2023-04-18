#include"Segment.h"

//��ʼ��
Segment::Segment(Point3D a, Point3D b) {
	this->A = a.clone();
	this->B = b.clone();
}

//�����߶γ���
void Segment::length() {
	A.distance(B);
}

//�����߶η���
void Segment::direction() {
	A.pointTo(B);
}


//�����߶������˵�
void Segment::swap() {
	Point3D temp;
	temp = A;
	A = B;
	B = temp;
}