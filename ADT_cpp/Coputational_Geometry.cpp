/*
2019-10.23
计算几何模板
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point              // 点类
{
public:
	double x, y;
	Point(double xx = 0, double yy = 0):x(xx), y(yy) {}
	Point operator + (Point& p)  { return Point(x + p.x, y + p.y); }
	Point operator - (Point& p)	 { return Point(x - p.x, y - p.y); }
	Point operator * (double k)  { return Point(x * k, y * k); }
	Point operator / (double k)  { return Point(x / k, y / k);}
	double norm()  { return x * x + y * y; }
	double abs()  { return sqrt(norm()); }
	
};
/* 在类外这样定义!
Point Point::operator * (double k)
{
	return Point(x*k, y*k);
}
*/
struct Segment           // 线段类
{
	Point p1, p2;
	Segment(Point pp1, Point pp2):p1(pp1),p2(pp2) {}
};

struct Circle            // 圆类!
{
	Point c;
	double r;
	Circle(Point p, double radius):c(p),r(radius) {}
};

/*类型重定义*/
typedef Point Vector;       // Vector与Point重名,一个点也可以是向量
typedef Segment Line;
typedef vector<Point> Polygon;      // 一个多边形由多个点构成

// 计算


int main()
{
	Vector a(2,1), b(1,2), c, d;
	c = a*2;
	cout << c.x << " "<< c.y;
	return 0;
}