// [+] 7. Наслідування і деструктори - не потрвбно явно викликати деструктори в дочірньому класі, і під час виконання спочатку знищується деструктор дочірнього класу а потім батьківського  
// [+] 8. Наслідування і оператори 
// [+] 9. Наслідування і статичні методи - так як і звичайні поля
// [-] 10. Hаслідування і шаблони

// 7. Наслідування і деструктори 
//- не потрвбно явно викликати деструктори в дочірньому класі, і під час виконання спочатку знищується деструктор дочірнього класу а потім батьківського  

// 8. Наслідування і оператори - перевантажні оператори викликаються
#include <iostream>
#include <cstdlib>

class Array 
{
protected:
    int* arr;
    size_t size;

public:
    // Конструктор
    Array(size_t size) : size(size), arr(nullptr) 
    {
        if (size > 0) 
        {
            arr = new int[size];
            for (size_t i = 0; i < size; i++) 
            {
                arr[i] = 0;
            }
        }
    }

    // Конструктор копіювання
    Array(const Array& other) : size(other.size), arr(nullptr) 
    {
        if (other.size > 0) 
        {
            arr = new int[other.size];
            for (size_t i = 0; i < size; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
    }

    // Деструктор
    ~Array() 
    {
        delete[] arr;
    }

    // Оператор присвоєння
    Array& operator=(const Array& other) 
    {
        if (this != &other) 
        {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (size_t i = 0; i < size; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Оператор доступу до елемента
    int& operator[](size_t index) 
    {
        if (index >= size) 
        {
            std::cerr << "Індекс виходить за межі масиву!" << std::endl;
            std::exit(1);
        }
        return arr[index];
    }

    const int& operator[](size_t index) const 
    {
        if (index >= size) 
        {
            std::cerr << "Індекс виходить за межі масиву!" << std::endl;
            std::exit(1);
        }
        return arr[index];
    }

    // Метод для отримання розміру
    size_t Size() const 
    {
        return size;
    }
};

class MathArray : public Array 
{
public:
    MathArray(size_t size) : Array(size) 
    {
        std::cout << "Викликано конструктор MathArray з розміром " << size << std::endl;
    }

    // Конструктор копіювання
    MathArray(const MathArray& other) : Array(other) 
    {
        std::cout << "Викликано конструктор копіювання MathArray" << std::endl;
    }

    // Оператор присвоєння
    MathArray& operator=(const MathArray& other) 
    {
        if (this != &other) 
        {
            this->Array::operator=(other);
        }
        return *this;
    }

    // Метод для обчислення суми елементів
    int Sum() const 
    {
        int sum = 0;
        for (size_t i = 0; i < Size(); i++) 
        {
            sum += (*this)[i];
        }
        return sum;
    }
};

//------------------------------------

// Базовий клас A
class A
{
public:
    // Конструктор за замовчуванням
    A() { std::cout << "A::A() \n"; }

    // Конструктор з одним параметром
    A(int a) { std::cout << "A::A(int a) \n"; }

    // Конструктор з двома параметрами
    A(int a, int b) { std::cout << "A::A(int a, int b) \n"; }

    // Конструктор копіювання
    A(const A& other) { std::cout << "A::A(const A& other) \n"; }

    // Конструктор переміщення
    A(A&& other) noexcept { std::cout << "A::A(A&& other) \n"; }

    // Деструктор
    ~A() { std::cout << "A::~A() \n"; }

    // Оператор присвоєння копіюванням
    A& operator=(const A& other)
    {
        if (this != &other)
        {
            std::cout << "A::operator=(const A& other) \n";
            // Тут можна додати код для копіювання даних
        }
        return *this;
    }

    // Оператор присвоєння переміщенням
    A& operator=(A&& other) noexcept
    {
        if (this != &other)
        {
            std::cout << "A::operator=(A&& other) \n";
            // Тут можна додати код для переміщення даних
        }
        return *this;
    }
};

// Похідний клас B, який успадковує клас A
class B : public A
{
public:
    // Конструктор за замовчуванням
    B() : A() { std::cout << "B::B() \n"; }

    // Конструктор з одним параметром
    B(int a) : A(a) { std::cout << "B::B(int a) \n"; }

    // Конструктор з двома параметрами
    B(int a, int b) : A(a, b) { std::cout << "B::B(int a, int b) \n"; }

    // Конструктор копіювання
    B(const B& other) : A(other) { std::cout << "B::B(const B& other) \n"; }

    // Конструктор переміщення
    B(B&& other) noexcept : A(std::move(other)) { std::cout << "B::B(B&& other) \n"; }

    // Деструктор
    ~B() { std::cout << "B::~B() \n"; }

    // Оператор присвоєння копіюванням
    B& operator=(const B& other)
    {
        if (this != &other)
        {
            A::operator=(other); // Виклик оператора присвоєння базового класу
            std::cout << "B::operator=(const B& other) \n";
            // Тут можна додати код для копіювання даних, специфічних для B
        }
        return *this;
    }

    // Оператор присвоєння переміщенням
    B& operator=(B&& other) noexcept
    {
        if (this != &other)
        {
            A::operator=(std::move(other)); // Виклик оператора присвоєння переміщенням базового класу
            std::cout << "B::operator=(B&& other) \n";
            // Тут можна додати код для переміщення даних, специфічних для B
        }
        return *this;
    }
};

//-------------------------
//+, -, *, /, %), 
// (>, <, >=, <=, ==, !=), (&&, 11), 
//(&, ^, 1, >>, <<) // (
// +=, -=, *=, /=, %=) - без конст писати
//  (&=, ^=, =, >>=, <<=), 
//[] - рекурсія, 
// ->
// ++, --, !, ~, *, -, &,
//
// (),
// type()
class Number
{
private:
    int value1;

public:
    // Конструктор для ініціалізації value1
    Number(int value) : value1(value) {}
    // Перевантаження оператора додавання для класу Number
    Number operator+(const Number& other) const
    {
        return Number(this->value1 + other.value1);
    }

    bool operator==(const Number& other) const
    {
        return this->value1 == other.value1;
    }

    Number& operator++() 
    {
        value1++;
        return *this;
    }

    Number operator++(int) 
    {
        Number temp(*this);
        value1++;
        return temp;
    }
    // Метод для отримання значення value1
    int GetValue() const { return value1; }
};

class DoubleNumber : public Number
{
private:
    int value2;

public:
    // Конструктор для ініціалізації value1 та value2
    DoubleNumber(int value1, int value2) : Number(value1), value2(value2) {}
    // Перевантаження оператора додавання для класу DoubleNumber
    DoubleNumber operator+(const DoubleNumber& other) const
    {
        return DoubleNumber(this->GetValue() + other.GetValue(), this->value2 + other.value2);
    }

    bool operator==(const DoubleNumber& other) const
    {
        return this->Number::operator==(other) && this->value2 == other.value2;
    }

    DoubleNumber& operator++() 
    {
        this->Number::operator++(); // Вызов префиксного инкремента базового класса
        ++value2;
        return *this;
    }

    DoubleNumber operator++(int) 
    {
        DoubleNumber temp(*this); // Сохранение текущего состояния объекта
        this->Number::operator++(0); // Вызов постфиксного инкремента базового класса
        value2++;
        return temp; // Возврат сохраненного состояния
    }

    // Метод для отримання значення value2
    int GetSecondValue() const { return value2; }
};

//------------------------------

template <typename T>
class Array1 
{
private:
    size_t size;
    T* arr;

public:
    // Конструктор за замовчуванням
    Array1() : size(0), arr(nullptr) {}

    // Конструктор з параметром
    Array1(size_t size) : size(size), arr(size > 0 ? new T[size]() : nullptr) {}

    // Конструктор копіювання
    Array1(const Array1& other) : size(other.size), arr(other.size > 0 ? new T[other.size] : nullptr) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Оператор присвоєння
    Array1& operator=(const Array1& other) {
        if (this != &other) 
        {
            delete[] arr;
            size = other.size;
            arr = other.size > 0 ? new T[other.size] : nullptr;
            for (size_t i = 0; i < size; ++i) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Оператор індексації
    T& operator[](size_t index) 
    {
        if (index >= size) {
            throw std::out_of_range("Індекс виходить за межі масиву");
        }
        return arr[index];
    }

    const T& operator[](size_t index) const 
    {
        if (index >= size) {

            throw std::out_of_range("Індекс виходить за межі масиву");
        }
        return arr[index];
    }

    // Метод для отримання розміру масиву
    size_t Size() const 
    {
        return size;
    }

    // Деструктор
    ~Array1() {
        delete[] arr;
    }
};
template <typename Z>
class MathArray11 : public Array1<Z> 
{
public:
    MathArray11(size_t size) : Array1<Z>(size) 
    {
        std::cout << "Викликано конструктор MathArray11 з розміром " << size << std::endl;
    }

    // Конструктор копіювання
    MathArray11(const MathArray11& other) : Array1<Z>(other) 
    {
        std::cout << "Викликано конструктор копіювання MathArray11" << std::endl;
    }

    // Оператор присвоєння
    MathArray11& operator=(const MathArray11& other) 
    {
        if (this != &other) 
        {
            this->Array1<Z>::operator=(other);
        }
        return *this;
    }

    // Метод для обчислення суми елементів
    Z Sum() const 
    {
        Z sum = 0;
        for (size_t i = 0; i < this->Size(); i++) 
        {
            sum += (*this)[i];
        }
        return sum;
    }
};
 
int main() 
{
    MathArray arr1(5);
    for (size_t i = 0; i < arr1.Size(); i++) 
    {
        arr1[i] = i + 1;
    }

    MathArray arr2(5);
    arr2 = arr1; // Використання перевантаженого оператора присвоєння

    std::cout << "Елементи arr2 після присвоєння: ";
    for (size_t i = 0; i < arr2.Size(); i++) 
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
//------------------------
    std::cout << "Створення об'єкта b1 без параметрів:\n";
    B b1;

    std::cout << "\nСтворення об'єкта b2 з одним параметром:\n";
    B b2(1);

    std::cout << "\nСтворення об'єкта b3 з двома параметрами:\n";
    B b3(1, 2);

    std::cout << "\nСтворення об'єкта b4 шляхом копіювання b3:\n";
    B b4(b3);

    std::cout << "\nСтворення об'єкта b5 шляхом переміщення b3:\n";
    B b5(std::move(b3));

    std::cout << "\nПрисвоєння об'єкта b2 об'єкту b1:\n";
    b1 = b2;

    std::cout << "\nПрисвоєння об'єкта b5 об'єкту b1 шляхом переміщення:\n";
    b1 = std::move(b5);

//-----------------------------
    DoubleNumber a(4, 5);
    DoubleNumber b(10, 3);

    DoubleNumber result(a + b);
    bool result1(a == b);
    std::cout << std::boolalpha << result1 << std::endl;
//-----------------------------
// 9. Наслідування і статичні методи - так як і звичайні поля

/* 
#include <iostream>

class A
{
protected:
    int value;
    static int staticValue;

public:
    void Method() { std::cout << "Method!\n"; }
    static void StaticMethod() { std::cout << "Static Method!\n"; }
};

// Ініціалізація статичного члена класу A
int A::staticValue = 10;

class B : public A
{
public:
    void HelloValue()
    {
        staticValue = 0;
    }
};

int main()
{
    B object;

    // Виклик статичного методу через об'єкт
    object.StaticMethod();

    // Виклик статичного методу через ім'я класу
    B::StaticMethod();

    return 0;
}
*/

// 10. Hаслідування і шаблони
    Array1<double> arr(10);
    MathArray11<double> arr5(10);
    MathArray11<double> arr3(arr5);
    MathArray11<double> arr4(3);

    arr4 = arr3;

    for (size_t i = 0; i < arr.Size(); i++)
    {
        arr[i] = i / 123.0;
        std::cout << arr[i] << " ";
    }
    return 0;
} 
