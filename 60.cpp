#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
int* CreateVariable(int value);

void Initialize(int arr2[], int size1);
void Show(const int arr2[], int size1);

int main()
{
    int* a = new int (5); //new повертає адресу цієї комірки тому прийдеться записати її в вказівник того

//  вказівник видалиться в кінці блоку маин, а змінна на кучи коли напишете delete 
// змінна на кучі - new int
// вказівник на стеку - int* a

    //const int* a = new const int {5};
    std::cout << a << std::endl;
    std::cout << *a << std::endl;

    *a=10;
    std::cout << *a << std::endl;
//------------

    double** a1 = new double*; //вказівник на вказівнк
    std::cout << a1 << std::endl; //адреса
    std::cout << *a1 << std::endl; 
//------
    int* ptr1 = new int(10);
    const int* ptr2 = new const int (20);
    int** ptr3 = new int* (nullptr);
    /* попрацювали з даними на кучі */
    delete ptr1;
    delete ptr2;
    delete ptr3;
//------
    // код //
    int* ptr4 = CreateVariable(10);
    //працюємо
    delete ptr4;

//масив на кучи
    int* arr = new int[3];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
//-
    std::cout << "enter size: ";
    int size;
    std::cin >> size;
    // краще перед цим перевыряти його розмір
    int* arr1 = new int[size]; //масив створюэться на етапы виконання тому можемо задавати розмыр змынною

    for (int i = 0; i < 3; i++)
    {
        arr1[i] = 0;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
//-
//задача з рандомом
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "enter size1: ";
    int size1;
    std::cin >> size1;

    int* arr2 = new int[size];

    Initialize(arr2, size1);
    Show(arr2, size1);
//------ двовимрні масиви на стеку
    //int** p = new int* [5];
    #include <iostream>

    std::cout << "Enter rows: ";
    int rows;
    std::cin >> rows;

    std::cout << "Enter columns: ";
    int columns;
    std::cin >> columns;

    int** arr3 = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr3[i] = new int[columns]();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] arr3[i]; //спочатку видаляемо масиви на які вказують вказівникик
    }
    delete[] arr3;//видаляємо масив вказівників
//---
  /*   const int SIZE1 = 1000;
    char buffer[SIZE1];

    std::cin.getline(buffer, SIZE1);

    int length = strlen(buffer);

    char* str1 = new char[length + 1];

    strcpy(str1, length + 1, buffer);

    std::cout << str1 << std::endl;

    delete[] str1;
    str1 = nullptr; */

    return 0; 
}

int* CreateVariable(int value) //створює на кучі щмінну задає значеннні і повертає
{
    int* variable = new int(value);
    return variable;
}

void Initialize(int arr2[], int size1)
{
    if (arr2 == nullptr)
        return;

    for (int i = 0; i < size1; i++)
        arr2[i] = rand() % 100;
}
void Show(const int arr2[], int size1)
{
    if (arr2 == nullptr)
        return;

    for (int i = 0; i < size1; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
}
