#include <iostream>

using namespace std;

class Complex {
private:
    double real;  // дійсна частина
    double imag;  // уявна частина
public:
    // Конструктор
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    // Арифметичні оператори
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex (real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const
    {
        return Complex ((real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag), 
                        (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag));
    }

    // Унарний мінус: -(3+2i) = -3-2i
    Complex operator-() const
    {
        return Complex(-real, -imag);
    }

    // Порівняння
    bool operator==(const Complex& other) const
    {
        return ((real == other.real)&&(imag == other.imag));
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

    // Складене присвоєння
    Complex& operator+=(const Complex& other)
    {
        real += other.real; 
        imag += other.imag;
        return *this;
    }

    Complex& operator-=(const Complex& other)
    {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex conj() const  // спряжене: a-bi
    {
        return Complex(real, -imag); 
    }

    // Введення і виведення — дружні функції
    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c)
{
	if(c.imag >= 0)
            cout << c.real << " + " << c.imag << "i";
        else
            cout << c.real << " - " << -c.imag << "i";

	return os;
}

int main()
{
    Complex C1(1, 2);
    Complex C2(3, 4);

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

    cout << "Результат додавання: " << C1 + C2 << endl;
    cout << "Результат віднімання: " << C1 - C2 << endl;
    cout << "Результат множення: " << C1 * C2 << endl;
    cout << "Результат ділення: " << C1 / C2 << endl << endl;

    cout << "Унарний мінус(перше число): " << -C1 << endl;
    cout << "Унарний мінус(друге число): " << -C2 << endl << endl;

    cout << "Рівність C1 == C2: " << boolalpha << (C1 == C2) << endl;
    cout << "Нерівність C1 != C2: " << boolalpha << (C1 != C2) << endl << endl;

    cout << "---------------------------------------------------------- " << endl;

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

    cout << "Додавання з присвоєнням (перше число): " << (C1 += C2) << endl << endl;

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

    cout << "Додавання з присвоєнням (друге число): " << (C2 += C1) << endl << endl;

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

    cout << "Віднімання з присвоєнням (перше число): " << (C1 -= C2) << endl << endl;

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

    cout << "Віднімання з присвоєнням (друге число): " << (C2 -= C1) << endl << endl;

    cout << "Перше число: " << C1 << endl;
    cout << "Друге число: " << C2 << endl << endl;

cout << "---------------------------------------------------------- " << endl;

    cout << "Спряжене (перше число): " << C1.conj() << endl;
    cout << "Спряжене (друге число): " << C2.conj() << endl << endl;

    return 0;
}