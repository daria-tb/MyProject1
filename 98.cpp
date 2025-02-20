#include <iostream>
#include <string>

/* class String
{
private:
    char* str;
    void Copy(const char* other)
    {
        size_t length = std::strlen(other);
        str = new char[length + 1];
        std::strncpy(str, other, length + 1);
    }

public:
    String()
        : str(nullptr)
    {    }
    String(const char* originStr)
        : str(nullptr)
    {
        if (originStr != nullptr)
        Copy (originStr);
    }

    ~String()
    {
        delete[] str;
        str = nullptr;
    }

    const char* GetString() const
    {
        return str != nullptr ? str : "";
    }
    size_t GetSize() const
    {
        return str != nullptr ? std::strlen(str) : 0;
    }
    void SetString(const char* newStr)
    {
        if (newStr != nullptr)
        {
            delete[] str;
            Copy (newStr);
        }
    }
}; */

//використання this коли треба указати де яке поле

class String
{
private:
    char* str;
    void Copy(const char* str)
    {
        size_t length = std::strlen(str);
        this->str = new char[length + 1];
        std::strncpy(this->str, str, length + 1);
    }

public:
    String()
        : str(nullptr)
    {    }
    String(const char* originStr)
        : str(nullptr)
    {
        if (originStr != nullptr)
        Copy (originStr);
    }

    ~String()
    {
        delete[] str;
        str = nullptr;
    }

    const char* GetString() const
    {
        return str != nullptr ? str : " ";
    }
    size_t GetSize() const
    {
        return str != nullptr ? std::strlen(str) : 0;
    }
    void SetString(const char* str)
    {
        if (str != nullptr)
        {
            delete[] this->str;
            Copy (str);
        }
    }

    const String& CompareBySize (const String& other)
    {
        return other.GetSize() >= GetSize() ? other : *this;
    }

};

int main()
{
    String emptyString;

    std::cout << "Empty string:\n";
    std::cout << "str = [" << emptyString.GetString() << "]\n";
    std::cout << "size = " << emptyString.GetSize() << "\n";

    String someString("I am unique!");

    std::cout << "Some string:\n";
    std::cout << "str = [" << someString.GetString() << "]\n"; //викликаємо функ і відправляємо наш обʼєкт GetString(someString)
    std::cout << "size = " << someString.GetSize() << "\n";

    someString.SetString("I am not unique anymore :(");

    std::cout << "Some string (again):\n";
    std::cout << "str = [" << someString.GetString() << "]\n";
    std::cout << "size = " << someString.GetSize() << "\n";

    //--------------------
    //This треба в ситуація коли вам треба повертати кудись обʼєкт метод якого викликається

    String someString1("aghjklsdbc");

    std::cout << "Some string #1:\n";
    std::cout << "str = [" << someString1.GetString() << "]\n"; // GetString(someString)
    std::cout << "size = " << someString1.GetSize() << "\n"; // GetSize(someString)

    String someString2("abcd");

    std::cout << "Some string #2:\n";
    std::cout << "str = [" << someString2.GetString() << "]\n";
    std::cout << "size = " << someString2.GetSize() << "\n";

    const String& biggerString = someString2.CompareBySize(someString1);

    std::cout << "Bigger String:\n";
    std::cout << "str = [" << biggerString.GetString() << "]\n";
    std::cout << "size =" << biggerString.GetSize() << "\n";

return 0;
} 