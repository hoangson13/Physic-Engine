#include"SceneManager.h"
#include<Windows.h>
int main() {

	SceneManager::GetInstance()->Init();
	std::list<Object*> list = SceneManager::GetInstance()->GetObjectList();

	for (auto i:list) {
		i->Render();
	}

	SceneManager::DestroyInstance();
	system("pause");
	return 0;
}