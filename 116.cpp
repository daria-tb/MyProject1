/*
Синтаксис перезавантаження оператора приведення типу: 
operator Тип() const
{
код
}
Код
*/
#include <iostream>
#include <cmath>

class Cartesian;

class Polar 
{
private:
    double radius;
    double angle;

public:
    Polar(double radius = 0, double angle = 0) : radius(radius), angle(angle) {}

    const double& Radius() const { return radius; }
    double& Radius() { return radius; }

    const double& Angle() const { return angle; }
    double& Angle() { return angle; }

    operator Cartesian() const;
};

class Cartesian 
{
private:
    double x;
    double y;

public:
    Cartesian(double x = 0, double y = 0) : x(x), y(y) {}

    const double& X() const { return x; }
    double& X() { return x; }

    const double& Y() const { return y; }
    double& Y() { return y; }

    operator Polar() const;
};

//оператор приведення з Polar у Cartesian
Polar::operator Cartesian() const 
{
    static const double PI = 3.14159;
    return Cartesian(radius * std::cos(angle * PI / 180.0), radius * std::sin(angle * PI / 180.0));
}

//оператор приведення з Cartesian у Polar
Cartesian::operator Polar() const 
{
    static const double PI = 3.14159;
    return Polar(std::sqrt(x * x + y * y), std::atan2(y, x) * 180.0 / PI);
}

int main() 
{
    Cartesian pointA(2, 3);
    Polar pointB(10, 250);

    std::cout << "A: [X = " << pointA.X() << ", Y = " << pointA.Y() << "]\n";
    std::cout << "B: [Radius = " << pointB.Radius() << ", Angle = " << pointB.Angle() << "]\n\n";

    std::cout << "After A = B:\n";
    pointA = pointB; //aвтоматично викликається operator Cartesian()
    std::cout << "A: [X = " << pointA.X() << ", Y = " << pointA.Y() << "]\n";

    std::cout << "After B = A:\n";
    pointB = pointA; //aвтоматично викликається operator Polar()
    std::cout << "B: [Radius = " << pointB.Radius() << ", Angle = " << pointB.Angle() << "]\n\n";

    return 0;
}
