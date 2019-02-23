
#include "../include/rotation.h"
#include "../include/graphic_paint.h"


float f(float x, float y) {
	return sqrt(x*x + y*y )* scale;
}

void display() {

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


float getNormilizinhFactor(float x, float y) {
	return sqrt(x * x + y * y);
}


vector findDirVector(vector vec1, vector vec2) {
	vector result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.x * vec2.z - vec1.z * vec2.x;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return result;
}

void drag(int x, int y) {


	float angle = 0.1;

	if (prev_y - y != 0)
		glRotatef(angle, -(prev_y - y), 0, 0);

	if (prev_x - x != 0) 
		glRotatef(angle, 0, -(prev_x - x), 0);

	 prev_x = x;
	 prev_y = y;

}


void drawCoordinatesSystemFunc() {


		glBegin(GL_LINE_STRIP);

			glVertex3f(-480, 0, 0);
			glVertex3f(480, 0, 0);

		glEnd();


		glBegin(GL_LINE_STRIP);

			glVertex3f(0, -480, 0);
			glVertex3f(0,  480, 0);

		glEnd();


		glBegin(GL_LINE_STRIP);

			glVertex3f(0, 0, -480);
			glVertex3f(0, 0,  480);

		glEnd();

}



void OnMouseClick(int button, int state, int x, int y) {
	std::cout << x << " | " << y << " ( " << state << " ) [ " << button << " ] " << std::endl;

	if (button == 3)
		scale+=0.02;
	if (button == 4)
		scale-=0.02;

	prev_x = x; prev_y = y;
}