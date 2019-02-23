#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

struct point {
	int x;
	int y;
};

class MathCalculationManager
{

	std::vector<point> points;

	void print(int, int);

public:
	MathCalculationManager(std::string);

	void printPoints();

	~MathCalculationManager();
};

