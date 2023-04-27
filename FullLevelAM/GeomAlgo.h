//
// Created by MBP on 2023/4/18.
//

#ifndef FULLLEVELAM_GEOMALGO_H
#define FULLLEVELAM_GEOMALGO_H

#include "Point3D.h"
#include "Line.h"
#include "Segment.h"
#include "Plane.h"
#include "Ray.h"
#include "Polyline.h"
#include<tuple>

namespace nsp {

	bool nearZero(double x);

	double distance(Point3D obj1, Line obj2);

	double distance(Point3D obj1, Ray obj2);

	double distance(Point3D obj1, Segment obj2);

	double distance(Point3D obj1, Plane obj2);

	double distance(Line obj1, Line obj2);

	double distance(Line obj1, Plane obj2);

	double distance(Ray obj1, Plane obj2);

	double distance(Segment obj1, Plane obj2);

	//ֱ����ֱ���ཻ�����ؽ��㡣��Ϊ�Ƕ෵��ֵ�����Բ���tuple<>�Ľṹ���أ����ô˺���ʱ����ע�ⷵ��ֵ�ĸ�ʽ
	//bool���������ж��Ƿ��н��㣬�����ص�tuple��boolΪfalseʱ��˵���޽��㣬Ϊtrueʱ�����ص�p��Ϊ����
	std::tuple<Point3D, double, double, bool> intersectLineLine(Line, Line);

	//�����߶κ�ƽ��Ľ��㲢����
	std::tuple<Point3D, bool>  intersectSegmentPlane(Segment seg, Plane plane);

	//ʵ���󽻼���
	std::tuple<Point3D, bool>  intersect(Line, Line);
	std::tuple<Point3D, bool>  intersect(Segment, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Plane);
	std::tuple<Point3D, bool>  intersect(Segment, Plane);


	bool pointOnRay(Point3D p, Ray ray);

	int pointInPolygon(Point3D p, Polyline polygon);


}


#endif //FULLLEVELAM_GEOMALGO_H
