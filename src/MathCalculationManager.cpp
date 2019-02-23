#include "../include/MathCalculationManager.h"
#include "../include/GraphicsManager.h"


MathCalculationManager::MathCalculationManager(std::string path)
{
	int a, b;
	int x = 0;
	int y = 0;

	std::ifstream data(path.c_str());

	for (std::string line; std::getline(data, line); ) {
		std::istringstream iss(line);

		std::cout << line << std::endl;

		std::string number;
		for (char c : line) {
			if (c != ' ')
				if (c != ',')
					number += c;
				else {
					x = std::atoi(number.c_str());
					number = "";
				}
		}

		y = std::atoi(number.c_str());

		points.push_back({ x , y });

	}
	std::cout << "Function call ended" << std::endl;
	data.close();
}


void MathCalculationManager::printPoints() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (point p : points) {
		print(p.x, p.y);
		std::cout << p.x << " | " << p.y << std::endl;
	}

	//for (float x = -480; x < 480; x += 10) {

	//	glBegin(GL_LINE_STRIP);

	//	for (float y = -480; y < 480; y += 10)
	//		glVertex3f(x, y, 0);

	//	glEnd();
	//}

	glBegin(GL_LINE_STRIP);

	glVertex3f(-480, 0, 0);
	glVertex3f(+480, 0, 0);

	glEnd();	
	
	glBegin(GL_LINE_STRIP);

	glVertex3f(0, -480, 0);
	glVertex3f(0, +480, 0);

	glEnd();

	glutSwapBuffers();
	
}
void MathCalculationManager::print(int x, int y) {
	float radius = 1000;
	int triangleAmount = 100;
	
	int k = 10;
	int h = 10;

	glBegin(GL_TRIANGLE_FAN);

	float scale = 1000;

	glVertex3f(x / scale, y / scale , 0);
	glVertex3f(( x + 20 ) / scale, y / scale, 0);
	glVertex3f(x / scale, (y + 20) / scale, 0);


	glEnd();


}

MathCalculationManager::~MathCalculationManager()
{
}
