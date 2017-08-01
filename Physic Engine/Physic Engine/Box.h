#pragma once
#include "Object.h"
#include "Circle.h"
class Circle;
class Box :
	public Object
{
public:
	Box();
	Box(int,int,int,int);
	Box(const Box &);
	virtual ~Box();

	void Update(float) override;
	void Render() override;
	bool IsInside(int, int) override;
	void Move(int, int) override;
	bool checkBoxwithBox(Box);
	bool checkBoxwithCircle(Circle);
	void setW(int);
	int getW();
	void setH(int);
	int getH();
private:
	int w;
	int h;
};

