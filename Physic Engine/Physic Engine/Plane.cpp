#include "Plane.h"
#include"../src/render/videoDriver.h"

Plane::Plane(){}
Plane::Plane(int ax,int ay,int bx,int by):ax(ax),ay(ay),bx(bx),by(by){}
Plane::Plane(const Plane &other):Plane(other.ax,other.ay,other.bx,other.by){}
Plane::~Plane(){}
void Plane::Update(float)
{
}
void Plane::Render()
{
	VideoDriver::GetInstance()->DrawRect(ax, ay, bx, by);
}
bool Plane::IsInside(int, int)
{
	return false;
}

void Plane::Move(int, int)
{
}
