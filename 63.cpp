#include <iostream>
//struct
//структура - це користувацький тип данних який обїєднує інші типи данних
/* 
Синтаксис опису структури:
struct Ім'я_Структури
{
    Дані№№1;
    Дані№№2;
    Дані№№3;
    ...
};
*/

/* struct Point
{
    int c; //4
    int x; // 4 //////компілятор вирівнює поля по кількісті байтів
    double y; //8 , бо 4+4 8 одного типу

    int a;
    char b[2]; //8
    але char b[5]; //12 бо чар 1 але всім виділяє 4 бо инт
    найменші вгорі

}; */

struct MyStruct
    {
        char a;
        int b;
        double c;
    };
//---------
struct Student
{
    char name [30];
    int age;
};
//----------
struct DynamicArray
    {
        int* arr = nullptr;
        int size = 0;
    };
//----------
//структура або опис структури
struct Point
{
    int x;
    int y;
};

struct Points
{
    int x;
    int y;
};
//------------
struct Triangle
    {
        //Point arr[3]; або так або так
        Points a;
        Points b;
        Points c;
    };

struct Piramide
{
    Triangle mainSide;
    double height;
};

void Show(const Piramide& piramide);
//void Set(Piramide& piramide);

//описи структур в блоках
/* void f()
{
    struct Points
    {  
        int x;
        int y;
    };
    Points a;
    Points arr[9];
}; */

int main()
{
    // Синтаксис створення змінної структури:
    // Тип Структури Ім'я Змінної;


    // Варіанти ініціалізації:
    //MyStruct variable{}; // a = '\0', b = 0, c = 0.0
    //MyStruct variable = {}; // a = '\0', b = 0, c = 0.0
   
    //MyStruct variable{ 'G', 10, 23.4 }; // a = 'G', b= 10, c = 23.4
    //MyStruct variable = { 'G', 10, 23.4 }; // a = 'G', b = 10, c = 23.4

    MyStruct variable = { 'G', 10, 23.4 };

    /* std::cout << "enter a: ";
    std::cin >> variable.a; */
    //або так:
    /* variable.a = 'G';
    variable.b = 10;
    variable.c = 23.4; */

    // Синтаксис звернення до поля структури:
    // Ім'я_Змінної.Ім'я_Поля

    std::cout << "variable.a = " << variable.a << std::endl;
    std::cout << "variable.a = " << variable.b << std::endl;
    std::cout << "variable.a = " << variable.c << std::endl;
//-------------
    Student demien { "Demien", 23 };
    std::cout << demien.name << std::endl;
//--------
    Student copyDemien;

    copyDemien.age = demien.age;

    int i;
    for (i = 0; i < demien.name[i] != '\0'; i++) 
        { copyDemien.name[i] = demien.name[i];}
    copyDemien.name[i] = '\0';
//----------- копыюванння ы присвоэння структур
    Student demien1{ "Demien", 23 };

/* Student copyDemien(demien);
Student copyDemien{ demien };
Student copyDemien = { demien };
Student copyDemien = Student{ demien }; */

    Student copyDemien1(demien);

    Student copyDemien2;
    /*
    ....
    */
    copyDemien2 = demien;
//-------------- поля-вказывники 
    DynamicArray array1;

    array1.size = 5;
    array1.arr = new int[array1.size];

    for (int i = 0; i < array1.size; i++)
    {
        array1.arr[i] = i + 1;
        std::cout << array1.arr[i] << " ";
    }

    DynamicArray array2;

    array2.size = array1.size;

    if (array1.arr != nullptr)
    {
        array2.arr = new int[array2.size];
        
        for (int i = 0; i < array2.size; i++)
            { array2.arr[i] = array1.arr[i];}
    }
    else
        array2.arr = nullptr;

    delete[] array1.arr;
    delete[] array2.arr;
//------------ вказывники на структури
//point1 це змінна/обʼєкт/екземпляр структури
    Point point1 { 10, 20 };

    Point* ptr = &point1;

/* також можемо змінювати значення
point1.x = 100;
point1.y = 678; */ 
    std::cout << "x = " << point1.x << std::endl;
    std::cout << "y = " << point1.y << std::endl;

/*також можемо змінювати значення
(*ptr).x = 789;
(*ptr).y = 785; */
    std::cout << "x = " << (*ptr).x << std::endl;
    std::cout << "y = " << (*ptr).y << std::endl;

/* також можемо змінювати значення
ptr->x = 67;
ptr->y =345; */
    std::cout << "x = " << ptr->x << std::endl;
    std::cout << "y = " << ptr->y << std::endl;
//----------- посилання на структури
    Point ref = point1;

/* також можемо змінювати значення
ref.x = 456;
ref.y = 234; */
    std::cout << "x = " << ref.x << std::endl; //бо ref.x = point1.x
    std::cout << "x = " << ref.y << std::endl;
//-------- константи структур
    Point point2 { 10, 20 };  //можна тільки користуватись полями

    Point* ptr2 = &point2; //можна окремо вибирати що буле константне, і можна не робити структуру константною, але якщо константна структура вказівник і посилання обовʼязково мають бути константними
    Point ref2 = point2;
// -------- масиви структур
    const int SIZE = 3;

    Point arr[SIZE]
    {
        //{ 10, 20}, { 30, 40}, { 50, 60};
        Point{ 10, 20},
        Point{ 30, 40},
        Point{ 50, 60 }
    }; 

for (int i = 0; 1 < SIZE; i++)
{
    std::cout << "Struct #" << i + 1 <<": [" << arr[i].x << ", " << arr[i].y << "]\n";
}

Point* pointers [SIZE] =

    {
        &arr[0],
        &arr[1],
        &arr[2],
    };
    
for (int i = 0; 1 < SIZE; i++)
{
    std::cout << "Struct #" << i + 1 <<": [" << pointers[i]->x << ", " << pointers[i]->y << "]\n"; //pointers це масив і його і-тий елемент це вказівник тому стрілка
}

//структури на кучі
    Point* point3 = new Point{};

    point3->x = 10;
    point3->y = 20;

    delete point3;
//структури в структурах
    Triangle myTriangle =
    {
        Points{ 10, 20 },
        Points{ 1, 40 },
        Points{ 6, 50 }
    };
//передача структур у функ
    Piramide piramide{};
    //Set(piramide);
    Show(piramide);

    return 0;
}

void Show(const Piramide& piramide) //якщо масив то * або const Piramide piramide[], int size
{
    std::cout << "Height = " << piramide.height << std::endl;
    std::cout << "Main Side A: [" << piramide.mainSide.a.x << ", " << piramide.mainSide.a.y << "]" << std::endl;
    std::cout << "Main Side B: [" << piramide.mainSide.b.x << ", " << piramide.mainSide.b.y << "]" << std::endl;
    std::cout << "Main Side C: [" << piramide.mainSide.c.x << ", " << piramide.mainSide.c.y << "]" << std::endl;
}
