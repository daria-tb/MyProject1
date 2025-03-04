#include <iostream>
#include <cstdlib>  // Для std::rand и std::srand
#include <ctime>    // Для std::time

// Синтаксис створення об'єкту шаблона класу:
// Ім'я_Класу Тип_Параметру_Шаблону> Ім'я_Об'єкту;
template <typename T>
class Array {
private:
    T* arr;  
    size_t size;

public:
    // Конструктор с параметрами по умолчанию
    Array(size_t size = 10, T ivalue = 0)
        : size(size), arr(size > 0 ? new T[size] : nullptr) 
        {
        if (arr != nullptr) {
            for (size_t i = 0; i < size; ++i) {
                arr[i] = ivalue;
            }
        }
    }

    // Конструктор копирования
    Array(const Array& other)
        : size(other.size), arr(other.size > 0 ? new int[other.size] : nullptr) {
        if (arr != nullptr) {
            for (size_t i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
    }

    // Конструктор перемещения
    Array(Array && other) noexcept
        : size(other.size), arr(other.arr) {
        other.size = 0;
        other.arr = nullptr;
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Оператор присваивания копированием
    Array& operator=(const Array& other) 
    {
        if (this == &other) 
        {
            return *this;
        }

        delete[] arr;

        size = other.size;
        arr = other.size > 0 ? new T[other.size] : nullptr;
        if (arr != nullptr) {
            for (size_t i = 0; i < size; ++i) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Оператор присваивания перемещением
    Array& operator=(Array&& other) noexcept 
    {
        if (this == &other) 
         {
            return *this;
        }

        delete[] arr;

        size = other.size;
        arr = other.arr;
        other.size = 0;
        other.arr = nullptr;
        return *this;
    }

    // Получить размер массива
    size_t Size() const {
        return size;
    }

    // Показать содержимое массива
    void Show() const {
        if (arr == nullptr) {
            std::cout << "Array is empty.\n";
        } else {
            for (size_t i = 0; i < size; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Заполнить массив случайными числами от 0 до 99
    void FillRandom() {
        if (arr != nullptr) {
            for (size_t i = 0; i < size; ++i) {
                arr[i] = std::rand() % 100;
            }
        }
    }
};
//-------------------
// Оголошення шаблонного класу Pair - декілька параметрів шаблону класу 
template <typename T1, typename T2>
class Pair 
{
private:
    T1 object1;
    T2 object2;

public:
    // Конструктор
    Pair(const T1& obj1, const T2& obj2)
        : object1(obj1), object2(obj2) {}

    // Геттери
    T1& GetObject1() { return object1; }
    T2& GetObject2() { return object2; }
};
//параметр шаблону без типк  ---------------------------------------
template <typename K, size_t size>
class Arr
{
private:
    K arr[size];
public:
    Arr()
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = std::rand() % 100;
        }

    }
    void Show() const
    {
        for (size_t i = 0; i < size; i++)
        { 
            std::cout << arr[i] << " "; 
        }
    }
};
/* ось таке створюється:
template <typename K, size_t size>
class Arr
{
private:
    double arr[8];
}; */

// спеціалізація шаблону методу -----------
template <typename L>
class Array1 
{
private:
    L* arr;
    size_t size;

public:
    Array1(size_t size);
    ~Array1();
    void Show() const;
};

// Конструктор
template <typename L>
Array1<L>::Array1(size_t size) 
    : size(size), arr(new L[size]) 
{
    for (size_t i = 0; i < size; i++) 
    {
        arr[i] = std::rand() % 100;
    }
}

// Деструктор
template <typename L>
Array1<L>::~Array1() 
{
    delete[] arr;
}

// Метод Show() для загальних типів
template <typename L>
void Array1<L>::Show() const 
{
    for (size_t i = 0; i < size; i++) 
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

// Спеціалізація методу Show() для типу char
template <>
void Array1<char>::Show() const 
{
    for (size_t i = 0; i < size; i++) 
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}
//-----------------

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Инициализация генератора случайных чисел

    Array<int> arr1(5);
    arr1.FillRandom();
    arr1.Show();
 
      
 
    Array<int> arr3(20);
    arr3.FillRandom();
    arr3.Show();
//-------------------------
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Pair<int, double> myObject{ 10, 2.3 };

    std::cout << "int value = " << myObject.GetObject1() << std::endl;
    std::cout << "double value = " << myObject.GetObject2() << std::endl;
    // параметр шаблону без типу ------------------------- 
    Arr<double, 9> object; 
    object.Show();
    std::cout << std::endl; 
// спеціалізація шаблону методу -----------
    Array1<int> object1{10};
    object1.Show();

    Array1<double> object2{10};
    object2.Show();

    Array1<char> object3{10};
    object3.Show();
// спеціалізація шаблону класу -----------
    return 0;
}

/* //методи шаблону класу (писати проп=тотипи методів і писати їх в іншому файлі)
наприклад: 
template <typename T>
Array<int>::Array(size_t size) {... }

тоді і 

 */