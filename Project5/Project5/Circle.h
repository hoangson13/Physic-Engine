#pragma once
#include "Object.h"
class Circle :
	public Object
{
public:
	Circle();
	Circle(int, int, int);
	Circle(const Circle &);
	virtual ~Circle();

	void Update(float) override;
	void Render() override;

	void setR(int);
	int getR();
private:
	int r;
};

