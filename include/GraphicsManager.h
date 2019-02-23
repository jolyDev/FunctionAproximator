#pragma once

#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "./Exp.h"

class GraphicsManager
{
private:

	int paint_range = 480;

	int prev_x = 0;
	int prev_y = 0;

	double scale = 0.14;

	double a1 = 0;
	double a2 = 0;
	double a3 = 0;
	double a4 = 0;
	double a5 = 0;


public:
	static const int window_width = 800;
	static const int window_height = 600;

	GraphicsManager();

	void display();

	void drag(int, int);

	float f(float, float);

	void drawCoordinatesSystemFunc();

	void OnMouseClick(int, int, int, int);

	~GraphicsManager();
};

