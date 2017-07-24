#include "SceneManager.h"
#include "Circle.h"
#include "Box.h"
#include <fstream>
#include <string>

SceneManager * SceneManager::ms_pInstance = NULL;

void SceneManager::Update(float frameTime)
{
}

void SceneManager::Render()
{
}

void SceneManager::AddObject()
{
}

void SceneManager::Init()
{
	std::string line;
	std::ifstream myfile("SceneManager.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		if (line.find("#OBJECT_NUM") != std::string::npos) {
			std::size_t pos = line.find(" ");
			std::string str = line.substr(pos + 1);
			for (int i = 0; i < std::stoi(str); i++) {
				getline(myfile, line);
				if (line.find("#ID") != std::string::npos) {
					std::size_t pos = line.find(" ");
					std::string str = line.substr(pos + 1);
				}else {
					std::cout << "Wrong Format" << std::endl;
				}

				getline(myfile, line);
				if (line.find("TYPE:") != std::string::npos) {
					std::size_t pos = line.find(" ");
					std::string str = line.substr(pos + 1);
					if (str == "CIRCLE") {
						getline(myfile, line);
						if (line.find("POSITION:") != std::string::npos) {
							std::size_t pos = line.find(" ");
							std::string str = line.substr(pos + 1);

							int After = str.find(",");
							std::string x = str.substr(0, After);
							pos = str.find(",");
							std::string str1 = str.substr(pos + 1);

							After = str1.find(",");
							std::string y = str1.substr(1, After-1);
							pos = str1.find(",");
							std::string r = str1.substr(pos + 2);

							objectlist.push_back( new Circle(std::stoi(x, nullptr, 0), std::stoi(y, nullptr, 0), std::stoi(r, nullptr, 0)));

						}
						else {
							std::cout << "Wrong Format" << std::endl;
						}
					}
					else if (str == "BOX") {
						getline(myfile, line);
						if (line.find("POSITION:") != std::string::npos) {
							std::size_t pos = line.find(" ");
							std::string str = line.substr(pos + 1);

							int After = str.find(",");
							std::string x = str.substr(0, After);
							pos = str.find(",");
							std::string str1 = str.substr(pos + 1);

							After = str1.find(",");
							std::string y = str1.substr(1, After - 1);
							pos = str1.find(",");
							std::string str2 = str1.substr(pos + 1);

							After = str2.find(",");
							std::string h = str2.substr(1, After - 1);
							pos = str2.find(",");
							std::string w = str2.substr(pos + 2);

							objectlist.push_back(new Box(std::stoi(x, nullptr, 0), std::stoi(y, nullptr, 0), std::stoi(h, nullptr, 0), std::stoi(w, nullptr, 0)));
						}
						else {
							std::cout << "Wrong Format" << std::endl;
						}
					}else {
						std::cout << "Wrong Format" << std::endl;
					}
				}
				else {
					std::cout << "Wrong Format" << std::endl;
				}
			}
		}else {
			std::cout << "Wrong Format" << std::endl;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}

std::list<Object*> SceneManager::GetObjectList()
{
	return objectlist;
}
