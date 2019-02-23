#include "../include/Aproximator.h"
#include "../include/Exp.h"

#include<iostream>
#include<iomanip>
#include<cmath>


int Polinomal_Fit(std::vector<double>, std::vector<double>, std::string);
void storeData(double, double, std::vector<double>, std::vector<double>, std::vector<double>, std::string);
void interpretateData(std::vector<double> &, std::vector<double> & , std::string);

void printVector(std::vector<double> & X) {

	std::cout << std::endl;
	
	for (auto x : X)
		std::cout << x << "  ";

	std::cout << std::endl;
}

void swap(double & x, double & y) {
	double t = x;
	x = y;
	y = t;
}

void aproximatorTestMain() {
	do3D_stuff();
	/*
	std::string output_path = "./";
	std::string path = "../OpenGl/data/";
	std::string name = "pointSet2D.txt";

	std::ifstream pointSet2D(path + name);

	if (pointSet2D.is_open()) {
		for (std::string line = ""; std::getline(pointSet2D, line); )
			std::cout << line << std::endl;
	}
	else std::cout << "Unable to open file" << std::endl;

	pointSet2D.close();

	std::vector<double> xs, ys;

	interpretateData(xs, ys, path + name);
	Polinomal_Fit(xs, ys, output_path + name);*/
	
	// std::cin.get();
}


void interpretateData(std::vector<double> & xs, std::vector<double> & ys, std::string inputPath) {

	std::ifstream pointSet2D(inputPath);
	std::string line;

	/**/
	for (std::string line; std::getline(pointSet2D, line); ) {
		std::istringstream iss(line);

		std::string number;
		for (char c : line) {
			if (c != ' ')
				if (c != ',')
					number += c;
				else {
					xs.push_back(std::atoi(number.c_str()));
					number = "";
				}
		}

		ys.push_back(std::atoi(number.c_str()));

	}
	/**/

	for (int i = 0; i < xs.size(); i++) {
		std::cout << "x: " << xs[i] << " | y: " << ys[i] << std::endl;
	}

	//if (pointSet2D.is_open()) {
	//	for (std::string line = ""; std::getline(pointSet2D, line); )
	//		std::cout << line << std::endl;
	//}
	//else std::cout << "Unable to open file" << std::endl;

	pointSet2D.close();

}

//Polynomial Fit
int Polinomal_Fit(std::vector<double> x, std::vector<double> y, std::string outputPath) {

	using namespace std;

	int n = 3;
	int N = x.size();
	
	std::vector<double> X(2 * N + 1);                        //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
	
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0;j < N;j++) {
			X[i] = X[i] + pow(x[j], i);        //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)

			std::cout << X[i] << " | " << std::endl;
		}
		printVector(X);

	}
	std::vector<std::vector<double>> B;
	std::vector<double> a(n + 1);            //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients

	for (int i = 0;i <= n;i++) {
	
		std::vector<double> bb;
		
		for (int j = 0;j <= n;j++)
			bb.push_back(X[i + j]);            //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
		bb.push_back(0);

		printVector(bb);

		B.push_back(bb);
	}

	std::vector<double> Y(N);                    //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
	
	for (int i = 0;i < n + 1;i++) {
		std::cout << "------------------------------";
		for (int j = 0;j < N;j++) {
			Y[i] = Y[i] + pow(x[j], i)*y[j];        //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
			printVector(Y);
		}
	}
	for (int i = 0;i <= n;i++)
		B[i][n + 1] = Y[i];                //load the values of Y as the last column of B(Normal Matrix but augmented)
	
	n = n + 1;                //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations
	
	cout << "\nThe Normal(Augmented Matrix) is as follows:\n";
	
	for (int i = 0;i < n;i++)            //print the Normal-augmented matrix
	{
		for (int j = 0;j <= n;j++)
			cout << B[i][j] << setw(16);
		cout << "\n";
	}
	for (int i = 0;i < n;i++)                    //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
		for (int k = i + 1;k < n;k++)
			if (B[i][i] < B[k][i])
				for (int j = 0;j <= n;j++)
					swap(B[i][j], B[k][j]);

	cout << "\n After some operations:\n";

	for (int i = 0;i < n;i++)            //print the Normal-augmented matrix
	{
		for (int j = 0;j <= n;j++)
			cout << B[i][j] << setw(16);
		cout << "\n";
	}

	for (int i = 0;i < n - 1;i++)            //loop to perform the gauss elimination
		for (int k = i + 1;k < n;k++)
		{
			double t = B[k][i] / B[i][i];
			for (int j = 0;j <= n;j++) {
				B[k][j] = B[k][j] - t * B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
				printVector(B[k]);
			}
		}


	for (int i = n - 1;i >= 0;i--)                //back-substitution
	{                        //x is an array whose values correspond to the values of x,y,z..
		a[i] = B[i][n];                //make the variable to be calculated equal to the rhs of the last equation
		
		std::cout << "+=+";
		printVector(a);
		std::cout << "+=+";

		for (int j = 0;j < n;j++) {
			if (j != i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
				a[i] = a[i] - B[i][j] * a[j];
			std::cout << "-=-";
			printVector(a);
			std::cout << "-=-";
		}
		a[i] = a[i] / B[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
	}


	cout << "\nThe values of the coefficients are as follows:\n";
	for (int i = 0;i < n;i++)
		cout << "x^" << i << "=" << a[i] << endl;            // Print the values of x^0,x^1,x^2,x^3,....    
	cout << "\nHence the fitted Polynomial is given by:\ny=";
	for (int i = 0;i < n;i++)
		cout << " + (" << a[i] << ")" << "x^" << i;
	cout << "\n";
	return 0;
}//output attached as .jpg



void storeData(double a, double b, std::vector<double> ys, std::vector<double> xs, std::vector<double> y_fit, std::string) {

	using namespace std;

	cout << "S.no" << setw(5) << "x" << setw(19) << "y(observed)" << setw(19) << "y(fitted)" << endl;
	cout << "-----------------------------------------------------------------\n";

	for (int i = 0;i < ys.size();i++)
		cout << i + 1 << "." << setw(8) << xs[i] << setw(15) << ys[i] << setw(18) << y_fit[i] << endl;//print a table of x,y(obs.) and y(fit.)    
	cout << "\nThe linear fit line is of the form:\n\n" << a << "x + " << b << endl;        //print the best fit line
}