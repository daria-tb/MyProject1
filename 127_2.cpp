// [+] 5. Модифікатор доступу protected
// [-] 6. Наслідування і конструктори

// 5. Модифікатор доступу protected
//використовується для визначення рівня доступу до змінних та методів класу
// -члени класу з модифікатором protected доступні всередині самого класу.
// -успадковані класи можуть використовувати protected-члени без обмежень.
// -але об'єкти зовнішніх класів не можуть звертатися до protected-членів безпосередньо.

//якщо писати взагалі без модифікатору то автоматично все буде private
/*  ПРИКЛАД
class Vehicle //батьківський клас
{
private:
    Point position;
    double height;
    double length;
    double width;

protected:
    double weight;

public:
    void Move(Point direction); // Виправлено Nove → Move
    void Rotate(Point direction);
    void Scale(float factor);
};

class Car : public Vehicle //дочірній клас, успадкування від Vehicle
{
private:
    int doors;
    int tankCapacity;
    char model[30];
    char mark[30];
    bool isStarted;

public:
    void FillUp(int points)
    {
        weight += points;
    }
    void Start();
}; 
*/

// 6. Наслідування і конструктори
#include <iostream>
#include <cstdlib>

class Array 
{
private:
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
                arr[i] = other.arr[i]; // Копіювання елементів
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

// Клас MathArray, успадковує Array
class MathArray : public Array 
{
public:
    MathArray(size_t size) : Array(size) 
    {
        std::cout << "Викликано конструктор MathArray з розміром " << size << std::endl;
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

//------------------------------

class A {
public:
    A() { std::cout << "A::A()\n"; }
    A(int a) { std::cout << "A::A(int a)\n"; }
    A(int a, int b) { std::cout << "A::A(int a, int b)\n"; }
};

class B : public A {
public:
    B() { std::cout << "B::B()\n"; }
    B(int a) { std::cout << "B::B(int a)\n"; }
    B(int a, int b) { std::cout << "B::B(int a, int b)\n"; }
};

// Головна функція
int main() 
{
    MathArray myArray(10);

    for (size_t i = 0; i < myArray.Size(); i++) 
    {
        myArray[i] = i + 1;
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    int sum = myArray.Sum();
    std::cout << "Сума: " << sum << std::endl;
//------------------------
    std::cout << "Створення об'єкта b1 без параметрів:\n";
    B b1;

    std::cout << "\nСтворення об'єкта b2 з одним параметром:\n";
    B b2(1);

    std::cout << "\nСтворення об'єкта b3 з двома параметрами:\n";
    B b3(1, 2);

    return 0;
}
