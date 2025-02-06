#include <iostream>
//Стек, Куча, Статична пам'ять
/* накладаються як тарілки оди на одного перший останній, останній перший

Змінна в стеку знищується в кінці роботи своїх {}
Статичні створюються коли програма запускається і знищуються коли вона закінчує роботу

Спочатку чиститься стек, потім всі статичні данні
 
Створення даних на кучі повертає їх адресу
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
    /*code*/
    /*code*/
    //створити змінну на кучі
    /*code*/
    /*code*/
    //видалити змінну з кучі
    /*code*/
    /*code*/
}
//-----
void Function()
{
        std::cout << &"hello world" << std::endl;
}
void Show(const char* str);
int CountLenght(const char* str);
//------
/* void Func4;
void Func5;
void Func6; */

/* void Show1(const int* arr1, int size);
void Show1(const int (*arr1)[5], int rows);
void Show1(const char* str1); */

int main()
{
    int vari = 10;
    int arr[3] = {1,2,3};

    if (true)
    {
        int b;
    }
    Func1(arr[0], vari);

    vari = Func2();
// 59--------------

//значенням рядкого літерала є його адреса
/* можемо записати рядковий літерал у вказівник

*/
    //char arr1[] = "hello world"; //можна змінити: arr[0] = 'k';
//не можна змвнити; в памʼяті створюється масив який буде містити 12 елементів, всі вони константні і через нього не можна змінювати :
    //const char arr2[] = "hello world"; 
//створюється вказівник який містить лиш е 8 байтів

    const char* ptr = "hello world"; //"hello world" статично const char*

    std::cout << ptr << std::endl;

    //рядкові літерати можуть зберігатися як в стеку так і у статичній памʼяті

    std::cout << &"hello world" << std::endl; //якщо cout приймає char* або const char* то виводе конкретно значення
    Function(); //рядкові літерати у статичні памʼяті
//вказівники на рядки --------
    const char STR[] = "hello world";
    Show(STR);
//---------
    const char STR_[] = "hello world";
    std::cout << CountLenght(STR_);

// масив вказівників

    int a = 10;
    int b = 20;
    int c = 30;

    int* arr_[3] = { &a, &b, &c };

    for (int i = 0; i < 3; i++)
    {
        //std::cout << arr[i] << " "; //адреса
        std::cout << &arr_[i] << " "; //значення
    }
//--------------
/*     void (*ptr1) () = Func4;
    void (*ptr2)() = Func5;
    void (*ptr3) () = Func6;

    // void (*)()

    void (*arr[3]) () = { Func4, Func5, Func6 };
    for (int i = 0; i < 3; i++)
    {
        std::cout << &arr[i] << " ";
    } */
//------

    int arr2[3][5] = { 0 };
    int (*ptr1)[5] = arr2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << *(*(ptr1 + i) +j) << " "; //ptr[i][j] 
        }
        std::cout << std::endl;
    }
//----------
    /* int arr1[3] = {1, 2, 3};
    Show1(arr1, 3);

    int(*ptr11) [4];
    const char* str1 = "Hello World";
    Show1(str1);

    int doubleArr[3][5] =
    {
        {1, 10, 100, 1000, 10000 },
        {2, 20, 200, 2000, 20000 },
        {3, 30, 300, 3000, 30000 }
    };

    Show1(doubleArr, 3); */
    return 0;
}

/* void Show2(const char* str2)
{
    while (*str2 != '\0')
    {
        std::cout << *str2;
        str2++; //рухаємо в право
    }
} */

int CountLenght(const char* str)//кʼсть символів в рядку
{
    int lenght=0;
    while(*str++ != '\n') //спочатку застосувати інкремент- посфіксний інкремент повернає значення першого елементу, потім розіменовується. символ перевіряється з нуль-символом і далі вказівник рухається в право
    {
        lenght++;
    }
    return lenght;
}

/* void Show1(const int (*arr1) [5], int rows)
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
    */
    void Show(const char* str1)
    {
        if (str1 == nullptr)
            return;

        while (*str1)
            std::cout << *str1++;
        std::cout << std::endl;
    }
    