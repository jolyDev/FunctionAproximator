
#include "../include/Exp.h"

void interpretateData3D(std::vector<double> & xs, std::vector<double> & ys, std::vector<double> & f, std::string inputPath) {

	std::ifstream pointSet2D(inputPath);
	std::string line;

	/**/
	for (std::string line; std::getline(pointSet2D, line); ) {
		std::istringstream iss(line);

		std::string number;

		bool entry = true;
		
		for (char c : line) {
			if (c != ' ')
				if (c != ',')
					number += c;
				else if (entry){
					xs.push_back(std::atoi(number.c_str()));
					number = "";
					entry = false;
				}
				else {
					ys.push_back(std::atoi(number.c_str()));
					number = "";
				}
		}

		f.push_back(std::atoi(number.c_str()));

	}
	/**/

	/**/
	for (int i = 0; i < xs.size(); i++) {
		std::cout << "x: " << xs[i] << " | y: " << ys[i] << " | " << f[i] <<  std::endl;
	}

	//if (pointSet2D.is_open()) {
	//	for (std::string line = ""; std::getline(pointSet2D, line); )
	//		std::cout << line << std::endl;
	//}
	//else std::cout << "Unable to open file" << std::endl;

	pointSet2D.close();
}

std::vector<double> do3D_stuff() {

	std::string output_path = "./";
	std::string path = "../OpenGl/data/";
	std::string name = "pointSet3D.txt";

	std::ifstream pointSet3D(path + name);

	if (pointSet3D.is_open())
		for (std::string line = ""; std::getline(pointSet3D, line); )
			std::cout << line << std::endl;

	else std::cout << "Unable to open file" << std::endl;

	pointSet3D.close();

	std::vector<double> xs, ys, f;

	interpretateData3D(xs, ys, f, path + name);
	return Polinomal_Fit3D(xs, ys, f, output_path + name);
}


void simplifyMatrix(std::vector<std::vector<double>> & A) {
	for (int i = 0; i < A[0].size(); i++) {

		for (int j = i + 1; j < A.size() && A[i][i] != 0; j++) {

			double koef = A[j][i] / A[i][i]; //  A[i][i] is a leader

			// std::cout << koef << " << " << A[j][i] << " << " << A[i][i] << std::endl;


			for (int k = 0; k < A[0].size(); k++) {
				// std::cout << A[j][k] << " << ";
				A[j][k] -= koef * A[i][k];
				// std::cout << A[j][k] << " << " << A[i][k] << std::endl;
			}
		}

		//for (int i = 0; i < A.size(); i++)
		//	printVector(A[i]);
	}
}

bool isVectorEmpty(const std::vector<double> & matrix_row) {
	for (int i = 0; i < matrix_row.size(); i++)
		if (matrix_row[i] != 0)
			return false;
	return true;
}

std::vector<double> solveMatrixEquisionByGaus(std::vector<std::vector<double>> & A, std::vector<double> & f) {

	simplifyMatrix(A);

	for (int i = A.size() - 1; i > -1; i--)
		if (isVectorEmpty(A[i]))
			A.pop_back();

	std::vector<double> a(A[0].size());
	std::vector<bool> is_a_finded(A[0].size());

	for (int i = A.size() - 1; i > -1 ; i--) {
		for (int j = 0; j < A[0].size() - 1; j++) { // why we need  - 1
			if (A[i][j] != 0) {

				double other_Sum = 0;

				for (int k = 0; k < A[0].size(); k++)
					other_Sum += a[k] * A[i][k];


				a[j] = (A[i][A[0].size() - 1] - other_Sum + a[j]) / A[i][j];
			}
		}
		}

	std::cout << " - = -" << std::endl;
		printVector(a);
		std::cout << " - = -" << std::endl;

	return a;
}


std::vector<double> Polinomal_Fit3D(std::vector<double> & x, std::vector<double> & y, std::vector<double> & f, std::string path) {
	std::vector<std::vector<double>> A(x.size());


	/* Fill matrix */
	for (int i = 0; i < x.size(); i++)
		A[i].push_back(1);

	for (int i = 0; i < x.size(); i++)
		A[i].push_back(x[i]);

	for (int i = 0; i < x.size(); i++)
		A[i].push_back(y[i]);

	for (int i = 0; i < x.size(); i++)
		A[i].push_back(x[i] * x[i]);

	for (int i = 0; i < x.size(); i++)
		A[i].push_back(y[i] * y[i]);

	for (int i = 0; i < x.size(); i++)
		A[i].push_back(f[i]);
	
	/* see how matrix was filled */
	for (int i = 0; i < x.size(); i++)
		printVector(A[i]);

	/* Find answers by gaus */
	auto a = solveMatrixEquisionByGaus(A, f);


	/* print final result */
	for (int i = 0; i < A.size(); i++)
		printVector(A[i]);


	return a;
}
