#pragma once
#include"Student.hpp"
using namespace std;
void Student::SolveEquation(const double& a, const double& b, const double& c) {
	x1 = 0;
	x2 = 0;
	roots = 1;
}

void Student::AnswersFile(ofstream& file, const double& a, const double& b, const double& c) {
	file << a << " " << b << " " << c << " ";
	file << roots << " " << x1 << " " << x2 << " " <<name <<" " << surname << endl;
}
void studGood::SolveEquation(const double& a, const double& b, const double& c) {
	ans.Equation(a, b, c, x1, x2, roots);
}


void studBad::SolveEquation(const double& a, const double& b, const double& c) {
	x1 = 0;
	roots = 1;
}

void studMedium::SolveEquation(const double& a, const double& b, const double& c) {
	if (rand() % 2 == 0) {
		ans.Equation(a, b, c, x1, x2, roots);
	}
	else {
		Student::SolveEquation(a, b, c);
	}
}
