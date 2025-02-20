#include <iostream>
#include <cstring>
/*
    class Ім'я_Класу
    {
        Члени_Класу
    };*/
//класс - це опис того як треба створюваи обʼєкт
//данні в класі = поля
//методи = функц в класі

class Student
{
private:
    // Поля:
    char name [20];
    int age;

public:
    // Методи:
    Student()
    {
        std::strcpy(name, "NoName");
        int age = 0;
    }

    void Show()
    {
        std::cout << "\tName: " << name << std::endl;
        std::cout << "\tAge: " << age << std::endl;
    }
    void ChangeAge (int newAge)
    {
        if (newAge > 0)
        {
            age = newAge;
        }
        else
        {
            std::cout << "New age is incorrect.\n";
        }
    }
    void ChangeName (const char* newName)
    {
        if (newName != nullptr && std::strlen(newName) < 20)
        {
            std::strncpy(name, newName, 19); 
            name[19] = '\0';
        }
        else
        {
            std::cout << "New name is incorrect.\n";
        }
    }
    void EnterName()
    {
        char temp[255];
        std::cout << "Enter name: ";
        std::cin >> temp;

        ChangeName (temp);
    }
    void EnterAge()
    {
        int temp;
        std::cout << "Enter age: ";
        std::cin >> temp;
        
        ChangeAge(temp);
    }
};
void Initialize (Student students[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Student #" << i+1 << ":\n";
        students[i].EnterName();
        students[1].EnterAge();
    }
}
    void Show(Student students[], size_t size)
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << "Student #" << i+1 << ":\n";
            students[i].Show();
        }
    } 
int main()
{
    // Ім'я_Класу Ім'я_Об'єкту;

    // Інкапсуляція це механізм в мові С++, який дозволяє об'єднувати
    // дані та методи їх обробки (функції) в одну єдину сутність, яка
    // зветься класом, або структурою, та дозволяє захищати дані та методи
    // від зовнішнього втручання завдяки модифікаторам доступу.
    
    Student demien;
    Student olga;

    demien. ChangeAge(23);
    demien.ChangeName("kiril");
    olga. ChangeAge(25);
    olga.ChangeName("katya");
    demien.Show();
    olga.Show();
//--------------------------------
/* 
    int a; - змінні типу
    const int b = 10; - константи
    int arr[2]; - масиві змінні
    const int arr2[3] = {1, 2, 3}; - константні масиви
    int* p = &a; - вказівники на ці змінні дані
    const int* p2 = &a ; -  вказівники на незмінні дані
    int* const p3 = &a; - незмінні вказівники
    const int* const p4 = &a; - незмінні вказівники на константні данні
    int& r = a; - посилання
    const int& r2 = a; - посилання на константи

    так можна і з класами
    змінні обʼєктів класів
    масиві класів
*/
//-------------------------------- вказівники
    Student david;

    david.ChangeAge (23);
    david.ChangeName("Demien");
    david.Show();

    Student* pDavid = &david;


    pDavid->ChangeAge (25);
    pDavid->ChangeName("DEMIEN");
    pDavid->Show();

//на кучі
    Student* dem = new Student;

    dem->ChangeAge(25);
    dem->ChangeName("DEMIEN");
    dem->Show();

    delete dem;
//посилання
    Student dada;

    dada.ChangeAge(23);
    dada.ChangeName("Dada");
    dada.Show();

    Student& refDada = dada;

    refDada.ChangeAge (30); //може посилатись за змынены данны
    refDada.ChangeName("DEMIEN");
    refDada.Show();
// масиви класу
    const size_t COUNT = 3;
    Student arr[COUNT];

    for (size_t i = 0; i < COUNT; i++)
    {
        std::cout << "Student #" << i + 1 << ":\n";
        arr[i].EnterName();
        arr[i].EnterAge();
    }
    
    for (size_t i = 0; i < COUNT; i++)
    {
        std::cout << "Student #" << i + 1 << ":\n";
        arr[i].Show();
    }
// будь яка к-сть студентів
    std::cout << "Enter amount of students: ";
    size_t size;
    std::cin >> size;

    Student* students = new Student [size];

    for (size_t i = 0; i < size; i++)
        {
            std::cout << "Student #" << i+1 << ":\n";
            students[i]. EnterName();
            students[i].EnterAge();
        }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Student #" << i+1 << ":\n";
        students[i].Show();
    }
//хочете у функ передати одиночний обʼєкт і вона має його змінити то відправляйте його по посиланню на змінні обʼєкти 
    std::cout << "Enter amount of students: ";
    size_t size1;
    std::cin >> size1;

    Student* students1 = new Student [size1];

    Initialize(students, size1);
    Show (students, size1);

    delete[] students;

    return 0;
}
