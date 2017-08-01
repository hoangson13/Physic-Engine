#include "Box.h"
#include"../src/render/videoDriver.h"
#include<iostream>
#include"SceneManager.h"
Box::Box(){}
Box::Box(int x, int y, int w, int h) : Object(x, y), w(w), h(h) {}
Box::Box(const Box &other):Box(other.P.x,other.P.y,other.w,other.h){}
Box::~Box(){}

void Box::Update(float)
{
	static int falltime = 0;
	if (SceneManager::GetInstance()->getSelectedObject() == this) {
		position mp = SceneManager::GetInstance()->getMousePosition();
		Move(mp.x,mp.y);
		falltime = 0;
	}
	else {
		falltime++;
		Fall(h, falltime);
	}

	for (auto i : SceneManager::GetInstance()->getObjectList()) {
		if (i == this) continue;
		if (dynamic_cast<Box*>(i) != nullptr) {
			Box* temp = dynamic_cast<Box*>(i);

			wchar_t text_buffer[20] = { 0 }; //temporary buffer
			swprintf(text_buffer, _countof(text_buffer), L"BxB\n"); // convert
			if (checkBoxwithBox(*temp)) OutputDebugString(text_buffer);
		}

		if (dynamic_cast<Circle*>(i) != nullptr) {
			Circle* temp = dynamic_cast<Circle*>(i);

			wchar_t text_buffer[20] = { 0 }; //temporary buffer
			swprintf(text_buffer, _countof(text_buffer), L"BxC\n"); // convert

			if (checkBoxwithCircle(*temp)) OutputDebugString(text_buffer);
		}
	}
}

void Box::Move(int mx, int my)
{
	if (P.x + xmove - w/2 > 0 && P.x + xmove + w/2 < SCREEN_W)P.x += xmove - w/4;
	else if (P.x + xmove - w/2 < 0) P.x = 0;
	else P.x = SCREEN_W - w;
	if (P.y + ymove - h/2 > 0 && P.y + ymove + h/2 < SCREEN_H)P.y += ymove - h/4;
	else if (P.y + ymove - h/2 < 0) P.y = 0;
	else P.y = SCREEN_H - h;

	xmove = (mx - P.x)/2;
	ymove = (my - P.y)/2;
}

bool Box::checkBoxwithBox(Box temp)
{
	position p = temp.getPos();
	if(p.x > P.x + w || p.x + temp.getW() < P.x) return false;
	if (p.y > P.y + h || p.y + temp.getH() < P.y) return false;
	return true;
}

bool Box::checkBoxwithCircle(Circle temp)
{
	position p = temp.getPos();
	if (p.x - temp.getR() > P.x + w || p.x + temp.getR() < P.x) return false;
	if (p.y - temp.getR() > P.y + h || p.y + temp.getR() < P.y) return false;
	return true;
}

void Box::Render()
{
	VideoDriver::GetInstance()->FillRect(P.x, P.y, w, h);
}

bool Box::IsInside(int mx, int my)
{
	return P.x < mx && mx < P.x + w && P.y < my && my < P.y + h;
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
