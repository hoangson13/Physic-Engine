#pragma once
class Object
{
public:
	Object();
	Object(int, int);
	Object(const Object &);
	~Object();
	virtual void Update(float)=0;
	virtual void Render()=0;

	void setX(int);
	int getX();

	void setY(int);
	int getY();

protected:
	int x;
	int y;
};

