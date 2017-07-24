#pragma once
#include<iostream>
#include<list>
#include"Object.h"
class SceneManager
{
protected:
	SceneManager() {}
	~SceneManager() {}
	/*implicit methods exist for the copy constructor and operator= and we want to forbid calling them.*/
	SceneManager(const SceneManager &) {}
	SceneManager& operator =(const SceneManager &) {}

public:
	static SceneManager * GetInstance()
	{
		if (ms_pInstance == NULL)
			ms_pInstance = new SceneManager;
		return ms_pInstance;
	}
	static void DestroyInstance()
	{
		if (ms_pInstance)
		{
			delete ms_pInstance;
			ms_pInstance = NULL;
		}
	}
	///////Funtions
	void Update(float);
	void Render();
	void AddObject();
	void Init();
	std::list<Object*> GetObjectList();
private:
	std::list<Object*> objectlist;
protected:
	static SceneManager * ms_pInstance;
};

