/*
2019-10.23
计算几何模板

*/

#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
	double x, y;
	Point(double xx, double yy):x(xx), y(yy) {}
	
};


struct Segment
{
	Point p1, p2;
	Segment(Point pp1, Point pp2):p1(pp1),p2(pp2) {}
};


struct Circle
{
	Point c;
	double r;
	Circle(Point p, double radius):c(p),r(radius) {}
};

typedef Point Vector;       // Vector与Point重名,一个点也可以是向量
typedef Segment Line;
typedef vector<Point> Polygon;      // 一个多边形由多个点构成


