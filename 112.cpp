// Перезавантаження логічних операторів:
// Оператори порівняння: >, <, >=, <=, ==, !=
// Логічні оператори: &&, ||, !
#include <iostream>

class Number
{
private:
    int* value;

public:
    Number(int val) : value(new int(val)) {}
    Number(const Number& other) : value(new int(*other.value)) {}
    Number(Number&& other) noexcept : value(other.value) { other.value = nullptr; }
    ~Number() { delete value; }

    int GetValue() const { return *value; }

 /*    // Перезаван. операторів порівняння
    bool operator>(const Number& other) const { return *this->value > *other.value; }
    bool operator<(const Number& other) const { return *this->value < *other.value; }
    bool operator>=(const Number& other) const { return *this->value >= *other.value; }
    bool operator<=(const Number& other) const { return *this->value <= *other.value; }
    bool operator==(const Number& other) const { return *this->value == *other.value; }
    bool operator!=(const Number& other) const { return *this->value != *other.value; }

    // Перезав. логічних операторів
    bool operator&&(const Number& other) const { return (*value != 0) && (*other.value != 0); }
    bool operator||(const Number& other) const { return (*value != 0) || (*other.value != 0); }
    bool operator!() const { return *value == 0; } */

    // виведення значення
    void PrintValue() const { std::cout << *value << std::endl; }
};
bool operator>(const Number& num1, const Number& num2) { return num1.GetValue() > num2.GetValue(); }
bool operator<(const Number& num1, const Number& num2) { return num1.GetValue() < num2.GetValue(); }
bool operator>=(const Number& num1, const Number& num2) { return num1.GetValue() >= num2.GetValue(); }
bool operator<=(const Number& num1, const Number& num2) { return num1.GetValue() <= num2.GetValue(); }
bool operator==(const Number& num1, const Number& num2) { return num1.GetValue() == num2.GetValue(); }
bool operator!=(const Number& num1, const Number& num2) { return num1.GetValue() != num2.GetValue(); }

bool operator&&(const Number& num1, const Number& num2) { return num1.GetValue() != 0 && num2.GetValue() != 0; }
bool operator||(const Number& num1, const Number& num2) { return num1.GetValue() != 0 || num2.GetValue() != 0; }
bool operator!(const Number& num1) { return num1.GetValue() == 0; }

int main()
{
    Number num1(10), num2(0), num3(5);

    //опер. порівняння
    std::cout << "num1 > num3: " << (num1 > num3) << std::endl;  // 1 (true)
    std::cout << "num1 < num3: " << (num1 < num3) << std::endl;  // 0 (false)
    std::cout << "num1 >= num3: " << (num1 >= num3) << std::endl; // 1 (true)
    std::cout << "num1 <= num3: " << (num1 <= num3) << std::endl; // 0 (false)
    std::cout << "num1 == num3: " << (num1 == num3) << std::endl; // 0 (false)
    std::cout << "num1 != num3: " << (num1 != num3) << std::endl; // 1 (true)

    //лог. оператори
    std::cout << "\nLogical operators:" << std::endl;
    std::cout << "num1 && num2: " << (num1 && num2) << std::endl; // 0 (false)
    std::cout << "num1 || num2: " << (num1 || num2) << std::endl; // 1 (true)
    std::cout << "!num2: " << !num2 << std::endl; // 1 (true)
    std::cout << "!num3: " << !num3 << std::endl; // 0 (false)

    return 0;
}
