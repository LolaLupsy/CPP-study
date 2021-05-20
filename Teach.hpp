#pragma once
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
#include "QuadraticEquation.hpp"
#include <string>

struct Teacher
{
private:
	SquareEquition ans;
public:

	string name;
	map<string, int> res;
	void checkWorksandPrint();
	//void PrintResults();
};