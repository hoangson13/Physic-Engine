#include "Circle.h"
#include<iostream>

Circle::Circle() {}
Circle::Circle(int x, int y, int r) : Object(x, y), r(r) {}
Circle::Circle(const Circle &other) : Circle(other.x, other.y, other.r) {}
Circle::~Circle() {}

void Circle::Update(float)
{
}

void Circle::Render()
{
	std::cout << "~~Circle~~"<< std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "r: " << r << std::endl;
}

////Getters & Setters
void Circle::setR(int r)
{
	this->r = r;
}
int Circle::getR()
{
	return r;
}
