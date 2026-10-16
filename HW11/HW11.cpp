#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double safeSqrt(double x)
{
    if(x < 0)
    {
        throw domain_error("x не може бути від'ємним");
    }

    return sqrt(x);
}

int main()
{
    double x = -7;
    try
    {
        double result = safeSqrt(x);
        cout << "Результат обчислення: " << result << endl;
    }
    catch(const exception& ex)
    {
        cerr << "Ми зловили: " << ex.what() << endl;
        cerr << "Тип помилки: domain_error" << endl;
    }
    
}