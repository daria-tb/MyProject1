#include <iostream>
void Func1();
void Func2(int a);
void Func3(int a, int b);
void Func4(int a, double b);
int Func5();
double Func6(int a);
char Func7(int a, int b); 
long Func8(int a, double b);
void Func9(int arr[], int size);
void Func10(const int a);
void Func11 (const int arr[], int size);

//функція створює не масив, а свій вказівник який зберігає адресу
//масиви і вказівнки
void Show(const int arr4[], int size1) //const int arr[] = const int* arr
{
    for (int i = 0; i < size1; i++)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;
}
//вказівники як параметри функцій
void Change(int* g)
{
    *g = 0;
}
void Swap(int* k, int* l)
{
    int temp = *k;
    *k = *l;
    *l = temp;
}

//вказівники - це змінна, яка в собі зберігає адресу
/* синтаксис створення вказівника:
1. тип_даних *імʼя_вказівника;
2. тип_даних *імʼя_вказівника = адреса; <- ініціалізація
*/


int main()
{
// аперсант - &
// 1 аперсант - отримання ношої адреси

    int a = 5;
    int b = 10;
    int* p;

//вказівний НА ЗМІННУ

    p = &a;
    //*p = 0; можна через вказівник змінити значення змінної
    std::cout << "&a = " << &a << std::endl;
    std::cout << "p = " << p << std::endl;
    // отримати значення яке лежить за цією адресою, через розіменування
    std::cout << "a = " << a << std::endl;
    std::cout << "*p = " << *p << std::endl;  

    p = &b;
    std::cout << "&b = " << &b << std::endl;
    std::cout << "p = " << p << std::endl;  
    std::cout << "b = " << b << std::endl;
    std::cout << "*p = " << *p << std::endl;  

//вказівник НА КОНСТАНТУ
    const int a1 = 8;
    const int b1 = 6;
    const int* p1; //змінювати не можна, але якщо не константна змінна її саму змінити можна

    p1 = &a1;
    std::cout << "&a1 = " << &a1 << std::endl;
    std::cout << "p1 = " << p1 << std::endl;
    // отримати значення яке лежить за цією адресою, через розіменування
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "*p1 = " << *p1 << std::endl;  
    p1 = &b1;
    std::cout << "&b1 = " << &b1 << std::endl;
    std::cout << "p1 = " << p1 << std::endl;  
    std::cout << "b1 = " << b1 << std::endl;
    std::cout << "*p1 = " << *p1 << std::endl; 

//вказівник на вказiвник
    int a2 = 4;
    int* p2 = &a2;

    int** pp2 = &p2; 
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "&a2 = " << &a2 << std::endl;
    ////std::cout << "*a2 = " << *a2 << std::endl; не існує

    std::cout << "p2 = " << p2 << std::endl; // =*pp2
    std::cout << "&p2 = " << &p2 << std::endl; //=pp2
    std::cout << "*p2 = " << *p2 << std::endl;

    std::cout << "pp2 = " << pp2 << std::endl;
    std::cout << "&pp2 = " << &pp2 << std::endl;
    std::cout << "*pp2 = " << *pp2 << std::endl;

//вказівник НА МАСИВ
    const int SIZE = 5;
    int arr[SIZE] = {1,2,3,4,5};

    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
    std::cout << arr[3] << std::endl;
    std::cout << arr[4] << std::endl;

    std::cout << &arr[0] << std::endl;
    std::cout << &arr[1] << std::endl;
    std::cout << &arr[2] << std::endl;
    std::cout << &arr[3] << std::endl;
    std::cout << &arr[4] << std::endl;

    //щоб створити вказівник на масив треба дізнатись адресу масиву
//імʼя масиву і являється адресою його першого елементу
    int* p3 = arr;

    //std::cout << p3 << std::endl;
    //std::cout << arr << std::endl;
    //std::cout << &arr << std::endl;
    //std::cout << &arr[0] << std::endl;
        std::cout << *p3 << std::endl;
        std::cout << arr[0] << std::endl;

// std::cout << arr[0...4] << std::endl; те само що:
    std::cout << p3[0] << std::endl;
    std::cout << p3[1] << std::endl;
    std::cout << p3[2] << std::endl;
    std::cout << p3[3] << std::endl;
    std::cout << p3[4] << std::endl;

// і через цикл
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

//вказівник НА КОНСТАНТНИЙ МАСИВ

    const int SIZE1 = 5;
    const int arr1[SIZE1] = { 1,2,3,4,5 }; //завжди константний треба ініціалізувати

    const int* p_ = arr;

//вказівник НА ФУНКЦІЇ
    //адреса функції по її імені

    /*
        синтаксис створення вказ на функц:
        1. тип_повертаючого значення (*імʼя_вказівника)(типи параметрів функції);
        2. тип_даних (*імʼя_вказівника) = адреса_функції; <- ініціалізація
    */
    void (*p11)() = Func1;
    void (*p22)(int) = Func2;
    void (*p33)(int, int) = Func3;
    void (*p4)(int, double) = Func4;
    int (*p5)() = Func5;
    double (*p6)(int) = Func6;
    char (*p7)(int, int) = Func7;
    long (*p8)(int, double) = Func8;
    void (*p9)(int[], int) = Func9;
    void (*p10)(const int) = Func10;
    void (*p111)(const int[], int) = Func11;

    std::cout << p11 << " = " << &Func1 << std::endl; //значення вказівника - адреса
//через вказівник можна викликати функцію 

//КОНСТАНТНИЙ вказівник
    int a3 = 15;
    int b3 = 5;
    const int c = 5;
//чи можна вказівник зробити константою
    int* const p12 = &a3; //константний вказівник, не можемо змінити значення вказівника після створення, але через нього можемо змінювати данні на які він вказує
    const int* p13 = &a3; //вказівник на константу і вказує на любі данні але не можна міняти данні *р = ...
    //const int* const p12 = &a; //константний вказівник на константу

//НУЛЬОВИЙ вказівник
    int* a4 = nullptr; 
    std::cout << a4 << std::endl;

//VOID вказівник
    int a5 = 10;
    double b5 = 1.2;

    void* ppp; // але не можемо розіенувати бо не відома кількість байтів
    
    ppp = &a5;
    std::cout << "&a5 = " << &a5 << std::endl;
    std::cout << "ppp = " << ppp << std::endl;
    //але треба для явного приведення 
    std::cout << "*ppp = " << *(static_cast<int*>(ppp)) << std::endl;

    ppp = &b5;
    std::cout << "&b5 = " << &b5 << std::endl;
    std::cout << "ppp = " << ppp << std::endl;
    std::cout << "*ppp = " << *(static_cast<double*>(ppp)) << std::endl;

//АРИФМЕТИКА вказівників
    //
    const int SIZE2 = 3;
    int arr2[SIZE2] = {1,2,3};

    int* p_1 = &arr2[0];
    int* p_2 = &arr2[4];

    std::cout << "p_1 + 0 = " << p_1 + 0 << std::endl;
    std::cout << "p_1 + 1 = " << p_1 + 1 << std::endl;
    std::cout << "p_1 + 2 = " << p_1 + 2 << std::endl;
    std::cout << "p_1 + 3 = " << p_1 + 3 << std::endl;
    std::cout << "p_1 + 4 = " << p_1 + 4 << std::endl;

    std::cout << "p_1 - 0 = " << p_1 - 0 << std::endl;
    std::cout << "p_1 - 1 = " << p_1 - 1 << std::endl;
    std::cout << "p_1 - 2 = " << p_1 - 2 << std::endl;
    std::cout << "p_1 - 3 = " << p_1 - 3 << std::endl;
    std::cout << "p_1 - 4 = " << p_1 - 4 << std::endl;

    std::cout << "&p_1[0] = " << &p_1[0] << std::endl;
    std::cout << "&p_1[1] = " << &p_1[1] << std::endl;
    std::cout << "&p_1[2] = " << &p_1[2] << std::endl;
    std::cout << "&p_1[3] = " << &p_1[3] << std::endl;
    std::cout << "&p_1[4] = " << &p_1[4] << std::endl;
    
    std::cout << "&arr2[0] = " << &arr2[0] << std::endl;
    std::cout << "&arr2[1] = " << &arr2[1] << std::endl;
    std::cout << "&arr2[2] = " << &arr2[2] << std::endl;
    std::cout << "&arr2[3] = " << &arr2[3] << std::endl;
    std::cout << "&arr2[4] = " << &arr2[4] << std::endl;

    std::cout << "p_2 - p_1 = " << p_2 - p_1 << std::endl;


//схожість масивів і вказівників
    const int SIZE3 = 5; 
    int arr3[SIZE3] = {1, 2, 3, 4, 5}; 
    int* ptr = arr3;

//через імя масиву можем діставати адресу кожного елементу

// Звернення до елементів значень через індекс
    for (int i = 0 ; i < SIZE3; i++) 
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
    
    for (int i = 0 ; i < SIZE3; i++) 
        std::cout << ptr[i] << " ";
    std::cout << std::endl;

    // Звернення до значень елементів через розіменуваня
    for (int i = 0 ; i < SIZE3; i++)
        std::cout << *(arr3 + i) << " "; 
    std::cout << std::endl;

    for (int i = 0 ; i < SIZE3; i++) 
        std::cout << *(ptr + i) << " ";
    std::cout << std::endl;

    // Звернення до адреси елементів через індекс
    for (int i = 0 ; i < SIZE3; i++) 
        std::cout << &arr3[i] << " "; 
    std::cout << std::endl;

    for (int i = 0 ; i < SIZE3; i++) 
        std::cout << &ptr[i] << " ";
    std::cout << std::endl;

    // Звернення до адреси елементів
    for (int i = 0; i < SIZE; i++)
        std::cout << arr + i << " ";
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
        std::cout << ptr + i << " ";
    std::cout << std::endl;

//вказівники як параметри функцій
    const int SIZE4 = 5; 
    int arr4[SIZE4] = {1, 2, 3, 4, 5}; 
    int* ptr = arr4;

    Show(arr4, SIZE4); //arr - адреса першого елемент, тобто функ-я створювала свій сласний вказівник
//------------
    int g = 10;
    Change(&g);
    std::cout << g << std::endl;
//-------------
    int k = 10, l = 20;

    std::cout << "k = " << k << ", l = " << l << std::endl;
    Swap(&k, &l);
    std::cout << "k = " << k << ", l = " << l << std::endl;
//-------

//вказівники як типи повертаючого значення


    return 0;
}

void Func1() 
{
    std::cout << "hello\n";
}
void Func2(int a) { }
void Func3(int a, int b) { }
void Func4(int a, double b) { }
int Func5() { return 0; }
double Func6(int a) { return 0; }
char Func7(int a, int b) { return 0; }
long Func8(int a, double b) { return 0; }
void Func9(int arr[], int size) { }
void Func10(const int a) { }
void Func11 (const int arr[], int size) { }