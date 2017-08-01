#pragma once

struct position {
	int x;
	int y;
};

class Object
{
public:
	Object();
	Object(int, int);
	Object(const Object &);
	~Object();
	virtual void Update(float)=0;
	virtual void Render()=0;
	virtual bool IsInside(int, int) = 0;
	virtual void Move(int,int) = 0;
	void Fall(int,int);	
	void setPos(int,int);
	position getPos();
	position getMove();

protected:
	position P;
	position PreSelect;
	float xmove, ymove;
};