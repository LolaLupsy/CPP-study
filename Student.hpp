#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "QuadraticEquation.hpp"

struct Student {
protected:
	SquareEquition ans;
public:
	int roots = 0;
	double x1 = 0, x2 = 0;
	string name;
	string surname;

	Student(string name, string surname) : name(name), surname(surname) {
	}

	virtual void SolveEquation(const double& a, const double& b, const double& c);
	void AnswersFile(ofstream& file, const double& a, const double& b, const double& c);

};

struct studGood : public Student {

	virtual void SolveEquation(const double& a, const double& b, const double& c);

	studGood(string name, string surname) : Student(name, surname) {}

};

struct studBad :  public Student {

	virtual void SolveEquation(const double& a, const double& b, const double& c);

	studBad(string name,string surname) : Student(name,surname) {}

};

struct studMedium : public Student{

	virtual void SolveEquation(const double& a, const double& b, const double& c);

	studMedium(string name, string surname) : Student(name, surname) {}

};