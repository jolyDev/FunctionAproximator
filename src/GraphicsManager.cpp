#include "../include/GraphicsManager.h"

GraphicsManager::GraphicsManager()
{
	std::vector<double> a = do3D_stuff();
	a1 = a[0];
	a2 = a[1];
	a3 = a[2];
	a4 = a[3];
	a5 = a[4];
}


void GraphicsManager::OnMouseClick(int button, int state, int x, int y) {
	std::cout << x << " | " << y << " ( " << state << " ) [ " << button << " ] " << std::endl;

	if (button == 3)
		scale += 0.02;
	if (button == 4)
		scale -= 0.02;

	prev_x = x; prev_y = y;
}

void GraphicsManager::drawCoordinatesSystemFunc() {

	glBegin(GL_LINE_STRIP);

	glVertex3f(-paint_range, 0, 0);
	glVertex3f(+paint_range, 0, 0);

	glEnd();


	glBegin(GL_LINE_STRIP);

	glVertex3f(0, -paint_range, 0);
	glVertex3f(0, +paint_range, 0);

	glEnd();


	glBegin(GL_LINE_STRIP);

	glVertex3f(0, 0, -paint_range);
	glVertex3f(0, 0, +paint_range);

	glEnd();
}
void  GraphicsManager::drag(int x, int y) {

	float angle = 0.1;

	if (prev_y - y != 0)
		glRotatef(angle, -(prev_y - y), 0, 0);

	if (prev_x - x != 0)
		glRotatef(angle, 0, -(prev_x - x), 0);

	prev_x = x;
	prev_y = y;
}

void GraphicsManager::display() {

	glClear(GL_COLOR_BUFFER_BIT);

	drawCoordinatesSystemFunc();


	for (float x = -480; x < 480; x += 10) {

		glBegin(GL_LINE_STRIP);

		for (float y = -480; y < 480; y += 10)
			glVertex3f(x, y, f(x, y));

		glEnd();
	}

	for (float y = -480; y < 480; y += 10) {

		glBegin(GL_LINE_STRIP);

		for (float x = -480; x < 480; x += 10)
			glVertex3f(x, y, f(x, y));

		glEnd();
	}

	glutSwapBuffers();
}

float GraphicsManager::f(float x, float y) {
	return (a1 + a2 * x + a3 * y + a4 * x * x + a5 * y * y) * scale;
}

GraphicsManager::~GraphicsManager()
{
}
