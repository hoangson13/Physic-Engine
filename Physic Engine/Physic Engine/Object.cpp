#include "Object.h"
#include"SceneManager.h"
#include<math.h>
#include "../src/render/define.h"

Object::Object(){
}

Object::Object(int x, int y){
	P.x = x;
	P.y = y;
	xmove = 0;
	ymove = 0;
}

Object::Object(const Object &other){
	P.x = other.P.x;
	P.y = other.P.y;
	xmove = 0;
	ymove = 0;
}
Object::~Object(){}

void Object::Fall(int del, int timefall)
{
	if (P.y + del < SCREEN_H) {
		P.y += 0.1*timefall*timefall;
	}
	else{
		P.y = SCREEN_H - del;
	}
}

void Object::setPos(int x, int y)
{
	P.x = x;
	P.y = y;
}

position Object::getPos()
{
	return P;
}

position Object::getMove()
{
	position temp;
	temp.x = xmove;
	temp.y = ymove;
	return temp;
}
