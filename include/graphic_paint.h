#pragma once

#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

static const int window_width = 800;
static const int window_height = 600;

static double scale = 0.14;

struct vector {
	float x;
	float y;
	float z;
};

static vector base = { 0, 0, 1000 };

static int prev_x = 0;
static int prev_y = 0;

//static vector base = { 0, tan(60 * 3.14 / 180) * 1000, 1000 };

// base.y = tan(60 * 3.14 / 180) * 100;
// base.z = sin(60 * 3.14 / 180) * 100;

float f(float x, float y);

void display();