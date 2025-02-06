#include <iostream>

// Стек, Куча, Статична пам'ять
/* накладаються як тарілки один на одного: перший останній, останній перший

Змінна в стеку знищується в кінці роботи своїх {}
Статичні створюються, коли програма запускається, і знищуються, коли вона закінчує роботу

Спочатку чиститься стек, потім всі статичні дані
 
Створення даних на кучі повертає їхню адресу
*/
int global1;
int* global2;
const int global3 = 5;
int global4[3];

int Func2()
{
    int a = 5;
    return a;
}
void Func1(int a, int b)
{
    double c;
    char arr[3];
    char* p;
}
void Func3(int a, int b)
{
    /* code */
    /* code */
    // створити змінну на кучі
    int* heapVar = new int(10);
    /* code */
    /* code */
    // видалити змінну з кучі
    delete heapVar;
    /* code */
    /* code */
}
//-----
void Function()
{
    std::cout << "hello world" << std::endl;
}
void Show(const char* str);
int CountLength(const char* str);
//------

void Show1(const int* arr1, int size);
void Show1(const int (*arr1)[5], int rows);
void Show1(const char* str1);

int main()
{
    int vari = 10;
    int arr[3] = {1, 2, 3};

    if (true)
    {
        int b;
    }
    Func1(arr[0], vari);

    vari = Func2();

    const char* ptr = "hello world";
    std::cout << ptr << std::endl;
    
    std::cout << "hello world" << std::endl;
    Function();

    const char STR[] = "hello world";
    Show(STR);

    const char STR_[] = "hello world";
    std::cout << CountLength(STR_);

    int a = 10, b = 20, c = 30;
    int* arr_[3] = { &a, &b, &c };

    for (int i = 0; i < 3; i++)
    {
        std::cout << *arr_[i] << " ";
    }
    std::cout << std::endl;

    int arr2[3][5] = { 0 };
    int (*ptr1)[5] = arr2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << ptr1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int arr1[3] = {1, 2, 3};
    Show1(arr1, 3);

    const char* str1 = "Hello World";
    Show1(str1);

    int doubleArr[3][5] =
    {
        {1, 10, 100, 1000, 10000 },
        {2, 20, 200, 2000, 20000 },
        {3, 30, 300, 3000, 30000 }
    };

    Show1(doubleArr, 3);
    return 0;
}

int CountLength(const char* str)
{
    int length = 0;
    while (*str != '\0') 
    {
        length++;
        str++;
    }
    return length;
}

void Show1(const int (*arr1)[5], int rows)
{
    if (arr1 == nullptr)
        return;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            std::cout << arr1[i][j] << " ";
        std::cout << std::endl;
    }
}
    
void Show1(const char* str1)
{
    if (str1 == nullptr)
        return;

    while (*str1)
        std::cout << *str1++;
    std::cout << std::endl;
}
