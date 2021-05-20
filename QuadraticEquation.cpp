#include "QuadraticEquation.hpp"

//find the roots
void SquareEquition::Equation(double a, double b, double c, double& x1, double& x2, int& roots) {

    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        x1 = x2 = 0;
        roots = 0;
    }
    else if (d > 0) {
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        roots = 2;
    }
    else if (d==0) {
        x1 = (-b ) / (2 * a);
        x1 = x2;
        roots = 1;
    }
   
}
