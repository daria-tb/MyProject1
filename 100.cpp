//конструктор переносу
#include <iostream>
#include <cstring>
#include <string>
/* Конструктор перенесення — це спеціальний конструктор у C++, 
який дозволяє ефективно передавати тимчасові (r-value) об'єкти без зайвого копіювання.

При звичайному копіюванні створюється повна копія об'єкта, 
що може бути повільним, якщо об'єкт має динамічно виділену пам’ять. 
Конструктор перенесення дозволяє просто "забрати" ресурси вихідного об'єкта, 
замість того щоб копіювати їх. 
std::move() — це функція з бібліотеки <utility>, 
яка перетворює L-value в R-value, щоб викликати конструктор перенесення 
або оператор присвоєння переміщенням.*/
class String 
{
private:
    char* str;
    size_t length;

public:
    String() : str(nullptr), length(0) {}

    //конструктор копіювання
    String(const String& other) : str(new char[other.length + 1]), length(other.length) 
    {
        std::strcpy(str, other.str);
        std::cout << "Copy constructor called\n";
    }

    //конструктор від `const char*`
    String(const char* inputStr) : str(nullptr), length(0) 
    {
        if (inputStr) 
        {
            length = std::strlen(inputStr);
            str = new char[length + 1];
            std::strcpy(str, inputStr);
        }
        std::cout << "Constructor from C-string called\n";
    }

    //конструктор від масиву символів
    String(const char arr[], size_t size) : str(nullptr), length(size) 
    {
        if (arr) 
        {
            str = new char[length + 1];
            std::memcpy(str, arr, length);
            str[length] = '\0';
        }
        std::cout << "Constructor from char array called\n";
    }

    //конструктор переміщення (R-value reference, з `std::move`)
    String(String&& other) noexcept : str(other.str), length(other.length) 
    {
        other.str = nullptr;
        other.length = 0;
        std::cout << "Move constructor (R-value reference) called\n";
    }

    //оператор копіювального присвоєння
    String& operator=(const String& other) 
    {
        if (this != &other) 
        {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    //оператор присвоєння переміщенням
    String& operator=(String&& other) noexcept 
    {
        if (this != &other) 
        {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
            std::cout << "Move assignment operator called\n";
        }
        return *this;
    }

    ~String() 
    {
        delete[] str;
    }

    //методи доступу
    const char* GetString() const { return str ? str : ""; }
    size_t GetLength() const { return length; }
    bool IsEmpty() const { return length == 0; }

    //методи зміни значення рядка
    void SetString(const char* inputStr) 
    {
        *this = String(inputStr);
    }

    void SetString(const String& other) 
    {
        *this = other;
    }

    void SetString(const char arr[], size_t size) 
    {
        *this = String(arr, size);
    }
};

//ф-я для конвертації цифри в символ
char ConvertDigitToChar(int digit) 
{
    return (digit >= 0 && digit <= 9) ? (digit + '0') : '1';
}

//ф-я створення рядка з чисел
String CreateStringWithNumbers(const int arr[], size_t size) 
{
    if (!arr || size == 0) 
    {
        return String();  // Порожній рядок
    }

    std::string tempStr(size, '\0');
    for (size_t i = 0; i < size; i++) 
    {
        tempStr[i] = ConvertDigitToChar(arr[i]);
    }

    return String(tempStr.c_str());
}

int main() 
{
    std::cout << "Creating str1...\n";
    String str1("Hello, World!");

    std::cout << "\nCopying str1 to str2...\n";
    String str2(str1); //конструктор копіювання

    std::cout << "\nMoving str2 to str3...\n";
    String str3 = std::move(str2); //конструктор переміщення

    std::cout << "\nstr1 [" << str1.GetString() << "]\n";
    std::cout << "str2 [" << str2.GetString() << "]\n";  //порожній після переміщення
    std::cout << "str3 [" << str3.GetString() << "]\n";  //отрим. значення str2

    std::cout << "\nCreating str4 from temporary object...\n";
    String str4 = String("Temporary String"); //конструктор переміщення

    std::cout << "\nUsing move assignment operator...\n";
    str3 = std::move(str4); //оператор переміщення

    std::cout << "\nstr3 [" << str3.GetString() << "]\n";
    std::cout << "str4 [" << str4.GetString() << "]\n";  //порожній після переміщення

    //тестування CreateStringWithNumbers
    std::cout << "\nCreating string from numbers...\n";
    int numbers[5] = {4, 6, 9, 2, 1};
    String numStr = CreateStringWithNumbers(numbers, 5);
    std::cout << "Numbers as string: [" << numStr.GetString() << "]\n";

    return 0;
}
