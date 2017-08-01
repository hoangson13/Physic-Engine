#include "Circle.h"
#include<iostream>
#include"../src/render/videoDriver.h"
#include"SceneManager.h"

Circle::Circle() {}
Circle::Circle(int x, int y, int r) : Object(x, y), r(r) {}
Circle::Circle(const Circle &other) : Circle(other.P.x, other.P.y, other.r) {}
Circle::~Circle() {}

void Circle::Update(float)
{
	static int falltime = 0;
	if (SceneManager::GetInstance()->getSelectedObject() == this) {
		position mp = SceneManager::GetInstance()->getMousePosition();
		Move(mp.x,mp.y);
		falltime = 0;
	}
	else {
		falltime++;
		Fall(r, falltime);
	}

	for (auto i : SceneManager::GetInstance()->getObjectList()) {
		if (i == this) continue;
		if (dynamic_cast<Box*>(i) != nullptr) {
			Box* temp = dynamic_cast<Box*>(i);

			wchar_t text_buffer[20] = { 0 }; //temporary buffer
			swprintf(text_buffer, _countof(text_buffer), L"CxB\n"); // convert

			if (checkCirclewithBox(*temp)) OutputDebugString(text_buffer);
		}

		if (dynamic_cast<Circle*>(i) != nullptr) {
			Circle* temp = dynamic_cast<Circle*>(i);

			wchar_t text_buffer[20] = { 0 }; //temporary buffer
			swprintf(text_buffer, _countof(text_buffer), L"CxC\n"); // convert

			if (checkCirclewithCircle(*temp)) OutputDebugString(text_buffer);
		}
	}
}

void Circle::Move(int mx, int my)
{
	if (P.x + xmove - r > 0 && P.x + xmove + r < SCREEN_W) P.x += xmove;
	else if (P.x + xmove - r < 0) P.x = r;
	else P.x = SCREEN_W - r;
	if (P.y + ymove - r> 0 && P.y + ymove + r < SCREEN_H) P.y += ymove;
	else if (P.y + ymove - r < 0) P.y = r;
	else P.y = SCREEN_H - r;

	xmove = (mx - P.x)/2;
	ymove = (my - P.y)/2;
}

bool Circle::checkCirclewithBox(Box temp) 
{
	position p = temp.getPos();
	if (p.x > P.x + r || p.x + temp.getW() < P.x - r) return false;
	if (p.y > P.y + r || p.y + temp.getH() < P.y - r) return false;
	return true;
}

bool Circle::checkCirclewithCircle(Circle temp)
{
	position p = temp.getPos();
	float dis = sqrt((P.x - p.x)*(P.x - p.x) + (P.y - p.y)*(P.y - p.y));
	return dis < r + temp.getR();
}

void Circle::Render()
{
	VideoDriver::GetInstance()->FillCircle(P.x, P.y, r);
}

bool Circle::IsInside(int mx, int my)
{
	return sqrt((mx - P.x)*(mx - P.x) + (my - P.y)*(my - P.y)) < r;
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
