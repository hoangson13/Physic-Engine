#pragma once
#include "Object.h"
#include "Box.h"
class Box;
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
	bool IsInside(int,int) override;
	void Move(int, int) override;
	bool checkCirclewithBox(Box);
	bool checkCirclewithCircle(Circle);

	void setR(int);
	int getR();
private:
	int r;
};

