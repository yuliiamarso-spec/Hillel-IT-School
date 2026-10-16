#include <iostream>
#include <cmath>


using namespace std;

class Shape
{
public:

    Shape()
    {
        cout << "Виклик конструктора Shape" << endl;
    }

    virtual ~Shape()
    {
        cout << "Виклик деструктора Shape" << endl;
    }

    virtual void draw() = 0;
    virtual double area() = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape()  
    {
        radius = r;
        cout << "Виклик конструктора Circle" << endl;
    }

    ~Circle()
    {
        cout << "Виклик деструктора Circle" << endl;
    }

    void draw() override
    {
        cout << "Коло" ;
    }

    double area() override
    {
        double square = M_PI * radius * radius;

        return square;
    }
};

class Rectangle : public Shape 
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape()
    {
        length = l;
        width = w;
        cout << "Виклик конструктора Rectangle" << endl;
    }

    ~Rectangle()
    {
        cout << "Виклик деструктора Rectangle" << endl;
    }

    void draw() override
    {
        cout << "Прямокутник";
    }

    double area() override
    {
        double square = length * width;

        return square;
    }
}; 

class Triangle : public Shape
{
private:
    double sideA;
    double sideB;

public:
    Triangle(double A, double B) : Shape() 
    {
        sideA = A;
        sideB = B;
        cout << "Виклик конструктора Triangle" << endl;
    }
    ~Triangle()
    {
        cout << "Виклик деструктора Triangle" << endl;
    }

    void draw() override
    {
        cout << "Трикутник";
    }
    double area() override
    {
        double square = (sideA * sideB) / 2; 

        return square;
    }
};

int main()
{
    Shape* shapes[3];
    shapes[0] = new Circle (3.5); 
    shapes[1] = new Rectangle (3.5, 4.5); 
    shapes[2] = new Triangle (3.5, 4.5); 

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw();
        cout << ": площа = " << shapes[i]->area() << endl;
    }

    cout << endl;
    
    delete shapes [0];
    delete shapes [1];
    delete shapes [2];

    return 0;
}