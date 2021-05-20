#include "Student.hpp"
#include "Teach.hpp"
using namespace std;

int main(void) {
	ifstream ex("ex.txt");
	ofstream answers("answers.txt");
	double a, b, c;
	
	studGood A("Student", "1"),B("Student", "2");
	studMedium D("Student", "3"), C("Student", "4");
	studBad E("Student", "5"), F("Student", "6");
while (ex >> a >> b >> c) {
		A.SolveEquation(a, b, c);
		B.SolveEquation(a, b, c);
		C.SolveEquation(a, b, c);
		D.SolveEquation(a, b, c);
		E.SolveEquation(a, b, c);
		F.SolveEquation(a, b, c);
		A.AnswersFile(answers, a, b, c);
		B.AnswersFile(answers, a, b, c);
		C.AnswersFile(answers, a, b, c);
		D.AnswersFile(answers, a, b, c);
		E.AnswersFile(answers, a, b, c);
		F.AnswersFile(answers, a, b, c);

	}
	answers.close();
	Teacher t;
	t.checkWorksandPrint();
	ex.close();
	return 0;
}