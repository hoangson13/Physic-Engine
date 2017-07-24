#pragma once
#include "Object.h"
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

	void setW(int);
	int getW();
	void setH(int);
	int getH();
private:
	int w;
	int h;
};

