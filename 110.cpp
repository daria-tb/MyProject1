#include <iostream>

// class ComplexNumber
//{
    /* ... */
//public:
//    ComplexNumber Add(const ComplexNumber& other) const { return *this; }
//    ComplexNumber Substract (const ComplexNumber& other) const { return *this; }
//    ComplexNumber Multiple (const ComplexNumber& other) const { return *this; }
//}; 


class Number
{
private:
    int a;

public:
    Number(int value) : a(value) { }

    //перезавантаження опеатору + через клас
    Number operator+(const Number& other) const 
    {
        return Number(this->a + other.a);
    }

    int GetNumber() const {return a;}
};

/* //через функцію
Number operator+(const Number& number1, const Number& number2)
{
    return Number(number1.GetNumber() + number2.GetNumber());
}
//оператори які перезавантажуються лише через методи (функції)
// =, ->, (), [], ->*, оператор type, new[], delete, delete[]
 */
int main()
{
    // Список операторів, які можна перевантажувати:
    // Перевантаження арифметичних операторів + , - , * , / , % , = , ++ , --
    // Перевантаження бітових операторів ^ , & , | , ~ , << , >>
    // Перевантаження логічних операторів < , > , <= , >= , == , != , ! , && , ||
    // Перевантаження комбінованих операторів += , -= , /= , %= , ^= , &= , |= , *= , <<= , >>=

    // Перевантаження оператора індексації []
    // Перевантаження оператора приведення типу
    // Перевантаження оператора виклику функції ()
    // Перевантаження операторів, пов’язаних з адресою *, &, ->, ->*
    // Перевантаження операторів виділення / видалення пам’яті new, new[], delete, delete[]
    // Перевантаження оператора коми

//--------------------

// Список операторів, які НЕ можна перевантажувати:

// .  (доступ до членів класу)
// .* (доступ до полів по вказівнику)
// ? :  (тернарний оператор)
// sizeof, typeid, XXX_cast
// ::  (доступ до області видимості)

// перезавантаженя оператора в класі або глобально через функцію ----------------------

    Number n1(3), n2(5);

    //Number result = n1.operator+(n2);
    Number result = n1 + n2;

    return 0;
}

