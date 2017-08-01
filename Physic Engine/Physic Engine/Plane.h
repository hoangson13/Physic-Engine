#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane();
	Plane(int, int, int, int);
	Plane(const Plane &);
	virtual ~Plane();
	void Update(float) override;
	void Render() override;
	bool IsInside(int, int) override;
	void Move(int, int) override;
private:
	int ax;
	int ay;
	int bx;
	int by;
};

