#include "Box.h"
#include<iostream>
Box::Box(){}
Box::Box(int x, int y, int w, int h): Object(x,y),w(w),h(h){}
Box::Box(const Box &other):Box(other.x,other.y,other.w,other.h){}
Box::~Box(){}

void Box::Update(float)
{
}

void Box::Render()
{
	std::cout << "~~Box~~" << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "h: " << h << std::endl;
	std::cout << "w: " << w << std::endl;
}

////Getters & Setters
void Box::setW(int w)
{
	this->w = w;
}
int Box::getW()
{
	return w;
}
void Box::setH(int h)
{
	this->h = h;
}
int Box::getH()
{
	return h;
}
