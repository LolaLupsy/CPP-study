#include <iostream>
using namespace std;

struct SquareEquition
{
private:
    
    double a, b, c;

public:
    
    SquareEquition(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    
    bool Solve(double& x1, double& x2)
    {
        if (a == 0) return false;

        // вычислить дискриминант
        double d = b * b - 4 * a * c;

        if (d < 0)
        {
            x1 = x2 = 0;
            return false;
        }

        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);

        return true;
    }

    void PrintSolve()
    {
        double x1, x2;

        cout << "The equation: ";

        if (a != 0)
            cout << a << "*x^2";

        if (b != 0)
        {
            if (b > 0)
                cout << "+";
            cout << b << "*x";
        }

        if (c != 0)
        {
            if (c > 0)
                cout << "+";
            cout << c;
        }

        cout << " = 0" << endl;

        if (Solve(x1, x2))
        {
            cout << "has the following roots: " << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else
        {
            cout << "has no roots. ";
        }
    }
};

int main()
{
    int a, b, c;
    cout << "Enter coefficients a,b,c:"<<endl;
    cin >> a >> b >> c;
    SquareEquition e(a,b,c); // вызов конструктора
    e.PrintSolve(); // вызов метода структуры
    return 0;
}