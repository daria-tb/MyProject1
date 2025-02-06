//вказівники як параметри функцій
#include <iostream>

void Initialize(int arr[], int size);
void Show(const int arr[], int size, void (*showFunction)(int element));

void ShowElement(int element);
void ShowElementInBrackets(int element);
void ShowElementInSquareBrackets (int element);

int main()
{
    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);
    Show(arr, SIZE, ShowElement);
    Show(arr, SIZE, ShowElementInBrackets);
    Show(arr, SIZE, ShowElementInSquareBrackets);

    return 0;
}

void Initialize(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}
void Show(const int arr[], int size, void (*showFunction)(int element))
{
    for (int i = 0; i < size; i++)
    {
        showFunction(arr[i]);
    }
    std::cout << std::endl;
}
void ShowElement(int element)
{
    std::cout << element << " ";
}
void ShowElementInBrackets(int element)
{
    std::cout << "(" << element << ") ";
}
void ShowElementInSquareBrackets(int element)
{
    std::cout << "[" << element << "]";  
}
