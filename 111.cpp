#include <iostream>
// Перезавантаження арифметичних операторів:
// + (унарний)
// - (унарний)
// ++ (унарний)
// -- (унарний)
// = (бінарний)
// + (бінарний)
// - (бінарний)
// * (бінарний)
// / (бінарний)
// % (бінарний)

class Number
{
private:
    int* value;

public:
    Number(int val) : value(new int(val)) {}
    Number(const Number& other) : value(new int(*other.value)) {}
    Number(Number&& other) noexcept : value(other.value) { other.value = nullptr; }
    ~Number() { delete value; }

    int GetValue() const { return value ? *value : 0; }

    // Унарні оператори (ЧЕРЕЗ методи)
    Number operator+() const { return Number(GetValue()); }
    Number operator-() const { return Number(-GetValue()); }
    Number& operator++() { if(value) ++(*value); return *this; }
    Number operator++(int) { Number temp(*this); if(value) ++(*value); return temp; }
    Number& operator--() { if(value) --(*value); return *this; }
    Number operator--(int) { Number temp(*this); if(value) --(*value); return temp; }

    // Бінарні оператори (методи)
    Number operator+(const Number& other) const { return Number(GetValue() + other.GetValue()); }
    Number operator-(const Number& other) const { return Number(GetValue() - other.GetValue()); }
    Number operator*(const Number& other) const { return Number(GetValue() * other.GetValue()); }
    Number operator/(const Number& other) const { return other.GetValue() != 0 ? Number(GetValue() / other.GetValue()) : Number(0); }
    Number operator%(const Number& other) const { return other.GetValue() != 0 ? Number(GetValue() % other.GetValue()) : Number(0); }

    Number& operator=(const Number& other) //присвоєння
    {
        if (this != &other) { *value = *other.value; }
        return *this;
    }
    Number& operator=(Number&& other) noexcept //переміщення
    {
        if (this != &other) { delete value; value = other.value; other.value = nullptr; }
        return *this;
    }
    Number& operator=(int number) { if(value) *value = number; return *this; } //присвоєння int value
    // перезавант. оператора вивед.
    friend std::ostream& operator<<(std::ostream& os, const Number& num)
    {
        os << num.GetValue();
        return os;
    }
    // через функції
    /* friend Number operator+(const Number& number) { return Number(number.GetValue()); }
    friend Number operator-(const Number& number) { return Number(-number.GetValue()); }
    friend Number& operator++(Number& number) { if(number.value) ++(*number.value); return number; }
    friend Number operator++(Number& number, int) { Number temp(number); if(number.value) ++(*number.value); return temp; }
    friend Number& operator--(Number& number) { if(number.value) --(*number.value); return number; }
    friend Number operator--(Number& number, int) { Number temp(number); if(number.value) --(*number.value); return temp; }

    friend Number operator+(const Number& number1, const Number& number2) { return Number(number1.GetValue() + number2.GetValue()); }
    friend Number operator-(const Number& number1, const Number& number2) { return Number(number1.GetValue() - number2.GetValue()); }
    friend Number operator*(const Number& number1, const Number& number2) { return Number(number1.GetValue() * number2.GetValue()); }
    friend Number operator/(const Number& number1, const Number& number2) { return number2.GetValue() != 0 ? Number(number1.GetValue() / number2.GetValue()) : Number(0); }
    friend Number operator%(const Number& number1, const Number& number2) { return number2.GetValue() != 0 ? Number(number1.GetValue() % number2.GetValue()) : Number(0); }
 */
};

int main()
{
    Number num1(1000), num2(22), num7(5000), num6(8);

    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num2 = " << num2.GetValue() << std::endl;

    // Унарні оператори
    std::cout << "\nUnary operator +:\n";
    Number num3 = +num1;
    std::cout << "num3 = " << num3.GetValue() << std::endl;

    std::cout << "\nUnary operator -:\n";
    Number num4 = -num1;
    std::cout << "num4 = " << num4.GetValue() << std::endl;

    std::cout << "\nPrefix increment:\n";
    ++num1;
    std::cout << "num1 after increment = " << num1.GetValue() << std::endl;

    std::cout << "\nPostfix increment:\n";
    num1++;
    std::cout << "num1 after postfix increment = " << num1.GetValue() << std::endl;

    std::cout << "\nPrefix decrement:\n";
    --num1;
    std::cout << "num1 after decrement = " << num1.GetValue() << std::endl;

    std::cout << "\nPostfix decrement:\n";
    num1--;
    std::cout << "num1 after postfix decrement = " << num1.GetValue() << std::endl;

    // Присвоєння
    std::cout << "\nБінарний оператор = (переміщення):\n";
    Number num5 = num1;
    num1 = num2;
    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num5 = " << num5.GetValue() << std::endl;

    std::cout << "\nБінарний оператор = (integer value):\n";
    num7 = num6 = 5000;
    std::cout << "num7 = " << num7.GetValue() << std::endl;
    std::cout << "num6 = " << num6.GetValue() << std::endl;

    // Бінарні оператори
    std::cout << "\nThe binary operator +, -, *, /, %:\n";
    std::cout << "num1 = " << num1.GetValue() << std::endl;
    std::cout << "num2 = " << num2.GetValue() << std::endl;

    std::cout << "num1 + num2 = " << num1 + num2 << std::endl;
    std::cout << "num1 - num2 = " << num1 - num2 << std::endl;
    std::cout << "num1 * num2 = " << num1 * num2 << std::endl;
    std::cout << "num1 / num2 = " << num1 / num2 << std::endl;
    std::cout << "num1 % num2 = " << num1 % num2 << std::endl;

    return 0;
}
