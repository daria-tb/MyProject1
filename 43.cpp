#include <iostream>
 // 43 функції --------

    //функція іменовай набір коду, який може приймати якусть інформацію та овертати результат
    
    /*синтаксис визначення фукн:
    тип_повертаючого_значення імя_функціф(список_формальних_параметрів)
    {
     код
    }

    синтаксис виклику функції
    імя_функц(список фактичних параметрів);


    при створенні функції ʼ при виклику функції
        формальні параметри ʼ   фактичні параметри
    формальні аргументи ʼ   фактичні аргументи
    параметри ʼ             аргументи
    */

//-----
int Multiple(int a, int b) //створюються данні
{
    int prod = a * b;
    return prod;
}
//----
double ToCube(double number)
{
    double cube = number * number * number;
    return cube;
}
//-----
double GetPI()
{
    double PI = 3.14159;
    return PI;
}
//-----
void Show(int numb) //нічого не повертає і без return 
{
    std::cout << "it's " << numb << " numb.\n";
}
//-----
void Show1(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//-----

void Show2(const int arr[], const int size)
{
    if (size <= 0)
    {
        std::cout << "Error\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void Initialize(int arr[], int size1)
{
    for (int i = 0; i < size1; i++)
    {
        arr[i] = i + i;
    }
}
//-------
void A(int arr[], int size2)
{
    arr[0] = 5;
}
void B(int a)
{
    a = 3;
}







int main()
{
    double number = 2.5;
    double cube = ToCube(number);

    std::cout << "Number = " << number << std::endl;
    std::cout << "Cube = " << cube << std::endl;
//---------
    double radius = 3;
    double area = GetPI() * radius * radius;
//----------
    Show(3+5);
//------
    const int SIZE1 = 3;
    const int SIZE2 = 5;

    int arr1[SIZE1] = {1, 2, 3};
    int arr2[SIZE2] = {1, 2, 3, 4, 5};

    //std::cout << arr; //виведе адресу першого елементу масиву

    Show1(arr1, SIZE1);
    Show1(arr2, SIZE2);
//-----
    const int SIZE3 = 2;
    const int SIZE4 = 4;

    int arr3[SIZE3] = {1, 3};
    int arr4[SIZE4] = {1, 2, 4, 5};

    //Initialize(arr3, SIZE1);
    //Initialize(arr4, SIZE2);

    Show2(arr3, SIZE1);
    Show2(arr4, SIZE2);
//--------
    int arr[3] = {1,2,3};
    int a = 10; // залишається, а в функції воід вона знищується

    A(arr, 3);
    B(a);

    std::cout << arr[0] << std::endl;
    std::cout << a << std::endl;

//синтаксис створення прототипу:
// Тип_повертаючого_значення iмя_функції(список_формальних_пареметрів);
/*
прототип
маин(){}
визначеня функ
*/

    return 0;
}