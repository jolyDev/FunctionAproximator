#include "../include/GraphicsManager.h"
#include "../include/Aproximator.h"
#include "../include/poly.h"


GraphicsManager  * graphic = new GraphicsManager();

// i saw this method in stackoverflow so it`s not a crutch)
void callMouseTrigger(int arg1, int arg2, int arg3, int arg4);
void callDragTrigger(int arg1, int arg2);


void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void timer(int = 0) {
	graphic->display();
	glutTimerFunc(10, timer, 0);
}

void buildGraphicsStuff() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Perspective projective
	glFrustum(-100, 100, -100, 100, 100, 5000);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -800);

	glRotatef(-30, 1, 0, 0);

	timer();
	glutMainLoop();
}

void callMouseTrigger(int arg1, int arg2, int arg3, int arg4) {
	graphic->OnMouseClick(arg1, arg2, arg3, arg4);
}

void callDragTrigger(int arg1, int arg2) {
	graphic->drag(arg1, arg2);
}

void preInit(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);

	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	// Set the window size
	glutInitWindowSize(graphic->window_width, graphic->window_height);

	// Create the window with the title "Hello,GL"
	glutCreateWindow("Function Displayer");

	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	//void (*click)(int, int, int, int);
	//click = graphic->OnMouseClick;

	glutMouseFunc(callMouseTrigger); // adding callBackFunction
	glutMotionFunc(callDragTrigger);
}

int postInit() {


	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	return 0;

}

int main(int argc, char* argv[]) {

	preInit(argc, argv);

	buildGraphicsStuff();

	return postInit();

	
	// aproximatorTestMain();

	//poly p;
	//p.inter();
}