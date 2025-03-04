//шаблони функцій
/*
Синтаксис написання шаблону функції:
template <typеnаmе Ім'я-Типу1, typename Ім'я_Типу2>
Функція
*/
#include <iostream>

template <typename T>
void Show(const T arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//-----------------------------------
template <typename S> 
void ShowSum(S a, S b)
{
    std::cout << a + b << std::endl;
}
//-----------------------------------
template <typename S1, typename S2> 
void ShowSum(S1 a, S2 b)
{
    std::cout << a + b << std::endl;
}
int main() 
{
    const int SIZE = 5;

    int arr1[SIZE] = {1, 2, 3, 4, 5};
    double arr2[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr3[SIZE] = {'1', '2', '3', '4', '5'};

    Show(arr1, SIZE);
    Show(arr2, SIZE);
    Show(arr3, SIZE);

    ShowSum(3.4, 5.76);
    ShowSum(3, 5.732);
 
    return 0;
}