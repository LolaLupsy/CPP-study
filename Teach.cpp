#include "Teach.hpp"
#include <map>
using namespace std;

void Teacher::checkWorksandPrint() {
	ifstream answers("answers.txt");
	double a, b, c, x1, x2, Arr[2];
	int roots, rootsSt;
	string name, surname;

	while (answers >> a >> b >> c >> rootsSt >> Arr[0] >> Arr[1] >> name >> surname) {
		ans.Equation(a, b, c, x1, x2, roots);
		if (res.count(name + surname) == 0) {
			res.emplace(name + " " + surname, 0);
		}
		if (x1 == Arr[0] && x2 == Arr[1] && roots == rootsSt) {
			res.at(name + " " + surname)++;
		}
	}
	cout << " Name of student\n";
	for (auto result : res) {
		cout << result.first << " - " << result.second<< endl;
	}
	answers.close();
}
