#include "Object.h"

Object::Object(){}
Object::Object(int x, int y):x(x),y(y){}
Object::Object(const Object &other):x(other.x),y(other.y){}
Object::~Object(){}

void Object::setX(int x)
{
	this->x = x;
}

int Object::getX()
{
	return x;
}

void Object::setY(int x)
{
	this->x = x;
}

int Object::getY()
{
	return y;
}
