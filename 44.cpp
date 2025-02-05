#include <iostream>
// exter тип_даних імʼя; - пошукай десь там у проекті таке в іншому файлв. 
// static тип_даних імʼя - тільки у цьому файлі, засекречено від інших файлів, область видимості - цей файл

int globalVar; //задається початкове значення 0

void Func1()
{
    globalVar = 1;
    std::cout << "Func1: " << globalVar << std::endl;
}

void Func2()
{
    globalVar = 2;
    std::cout << "Func2: " << globalVar << std::endl;
}
//-----
/* void Initialize(int arr[], int size);
void Show(const int arr[], int size); */
//----------

void Funct()
{
    int a = 0; //буде 1 1 1 виводитись, бо кожен раз викликається і завершуєтьч=ся
    a++;
    std::cout << a << std::endl; 
}
void Funct1()
{
    static int a = 0; //буде 1 2 3 виводитись, бо кожен раз викликається 1 функ статично
    a++;
    std::cout << a << std::endl; 
}

int main()
{
    //int variable; //локальні жанні розміщуються у фігурних дужках, а глобальні поза дужками - у статичній памяті
    globalVar = 3;
    std::cout << "Main: " << globalVar << std::endl;
    Func1();
    Func2();

//------
/* const int SIZE = 5;
int arr[SIZE] = {};

    Show(arr, SIZE);
    Initialize(arr, SIZE);
    Show(arr, SIZE); */
//---------
    for (int i = 0; i < 3; i++)
    {
        Funct();
    }
//---------
    for (int i = 0; i < 3; i++)
    {
        Funct1();
    }
    return 0;
}

 /* void Initialize(int arr[], int size)
 {
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
 }

 void Show(int arr[], int size)
 {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    } 
    std::cout << std::endl;
 } */
