#include<iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

void isInCircle(Circle &c,Point &p) {
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance) {
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}

int main() {
	//创建圆的属性
	Circle c;
	c.setR(10);

	Point center;
	center.setX(10);
	center.setY(0);

	c.setCenter(center);
	//创建点的属性
	Point p;
	p.setX(10);
	p.setY(9);

	isInCircle(c, p);

	return 0;
}