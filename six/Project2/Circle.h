#pragma once
#include<iostream>
#include "Point.h"
using namespace std;

class Circle
{
private:
	int m_R;
	//在类中可以让另一个类作为本类中的成员
	Point m_Center;
public:
	void setR(int r);

	int getR();

	void setCenter(Point center);

	Point getCenter();

};
