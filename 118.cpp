#include <iostream>
#include <cstring>

class Person 
{
private:
    char firstName[30];
    char lastName[30];
    int age;

public:
    // Конструктор класу Person
    Person(const char* firstName, const char* lastName, int age) 
    {
        this->age = age;
        std::strncpy(this->firstName, firstName, 30 - 1);        
        std::strncpy(this->lastName, lastName, 30 - 1);
    }

    // Гетери для доступу до даних
    const char* FirstName() const { return firstName; }
    const char* LastName() const { return lastName; }
    int Age() const { return age; }

    // Перевантаження оператора виведення
    friend std::ostream& operator<<(std::ostream& os, const Person& person) 
    {
        os << "Person Info: [Name: " << person.firstName;
        os << ", Surname: " << person.lastName;
        os << ", Age: " << person.age << "]";
        return os;
    }
};

class PersonPointer 
{
private:
    Person* ptr;

public:
    PersonPointer(Person& person) : ptr(&person) {}

    ~PersonPointer() { } //delete ptr; ptr = nullptr;

    // Методи доступу через оператори
    Person& operator*() const { return *ptr; } //перезавант * повертається посилання
    Person* operator&() const { return ptr; }
    Person* operator->() const { return ptr; }

    // Дружні функції
    //friend Person& operator*(const PersonPointer& pointer) { return *pointer.ptr; }
    //friend Person* operator&(const PersonPointer& pointer) { return pointer.ptr; } //перезавантаж &
    //friend Person* operator->(const PersonPointer& pointer) { return *pointer.ptr; } //пмилка бо -> має бути методом
};

int main() 
{
    // Створення об'єкта Person
    Person demien("Demien", "Blogan", 24);

    
    std::cout << demien << std::endl; // Використовуємо перевантажений оператор <<
//--------
    PersonPointer ptr{demien};

    std::cout << &demien << std::endl;
    std::cout << &ptr << std::endl; //якщо не перезакатажувати & то буде адреса птр а не демиана
//-----------
//щоб вивело інформацію треба перезаванаж *
    std::cout << (*ptr) << std::endl;

    
    std::cout << (*ptr).Age() << std::endl;    
    std::cout << ptr->Age() << std::endl;

/*     //вказівник р в класі ptr
    ptr->p* */

    return 0;
}
