#include <iostream>
/* масиви




*/
int main()
{
    //40 - масив - іменова сукупність однотипних даних
    //елемент - змінна масива

    // синтаксис масиву
    // тип_даних шмя_масиву[к-сть_ елемент];

    //синтаксис звернення до елем масиву:
    //імя_масиву[індекс_елем]


    //int arr[3];
    //індекси
    /* arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30; */

    /* std::cout << "arr[" << 0 << "] = " << arr[0] << std::endl;
    std::cout << "arr[" << 1 << "] = " << arr[1] << std::endl;
    std::cout << "arr[" << 2 << "] = " << arr[2] << std::endl; */

    /* int index = 0;

    arr[index] = 10;
    index++;

    arr[index] = 20;
    index++;

    arr[index] = 30;
    index++; */

    const int SIZE = 10;
    int arr[SIZE];
    for (int index = 0; index < SIZE; index++)
        arr[index] = index + index;

    for (int index = 0; index < SIZE; index++)
        std::cout << "arr[" << index << "] = " << arr[index] << std::endl;

    //ініціалізація

    /* const int SIZE = 5;

    int arr[SIZE] = { 10, 20, 30, 40, 50 };
    for (int index = 0; index < SIZE; index++)
        std::cout << "arr[" << index << "] = " << arr[index] << std::endl; */

// 41 -
// двовимірний масив це масив кожен елемент якого масив (кожен елемент якого має два індекси)
//багато вимірний масив - це масив масивів
//синтакисис двовимірних масивів
//тип_даних імя_масиву[к-сть_підмасивів] [к-сть_елем];

    //синтаксис до звернення елем 2-вимырного масиву:
    //імя_масиву[індекс_підмасиву][індекс_елем_підмасиву]

    const int WEEKS = 3, DAYS = 5;

    double temperatures[WEEKS][DAYS];
    //обхід масива через цикл, 
    //двовим: в першому циклі проходимся по всіх підмасивах і в внутрішньому циклі по елем. підмасивів
    for (int i = 0; i < WEEKS; i++)
    {  for (int j = 0; j < DAYS; j++)
            { temperatures[i][j] = j + i * j + i;} }

    for (int i = 0; i < WEEKS; i++)
    {  for (int j = 0; j < DAYS; j++)
            std::cout << "temperatures[" << i << "][" << j << "] = " << temperatures[i][j] << std::endl;
    std::cout << std::endl;
    }
    /* for (int i = 0; i < DAYS; i++)
        temperatures[0][i] = i * i + i;
    for (int i = 0; i < DAYS; i++)
            temperatures[1][i] = i * i + i;
    for (int i = 0; i < DAYS; i++)
            temperatures[2][i] = i * i + i; */

    /* for (int i = 0; i < DAYS; i++)
        std::cout << "temperatures[" << 0 << "][" << i << "] = " << temperatures[0][i] << std::endl;
    for (int i = 0; i < DAYS; i++)
        std::cout << "temperatures[" << 1 << "][" << i << "] = " << temperatures[1][i] << std::endl;    
    for (int i = 0; i < DAYS; i++)
        std::cout << "temperatures[" << 2 << "][" << i << "] = " << temperatures[2][i] << std::endl;
 */
    /* temperatures[0][0] = 2;
    temperatures[0][1] = 4;

    temperatures[1][0] = 78;
    temperatures[1][1] = 3;

    temperatures[2][0] = 5;
    temperatures[2][1] = 65; */

    /* std::cout << "temperatures[" << 0 << "][" << 0 << "] = " << temperatures[0][0] << std::endl;
    std::cout << "temperatures[" << 0 << "][" << 1 << "] = " << temperatures[0][1] << std::endl;

    std::cout << "temperatures[" << 1 << "][" << 0 << "] = " << temperatures[1][0] << std::endl;
    std::cout << "temperatures[" << 1 << "][" << 1 << "] = " << temperatures[1][1] << std::endl;

    std::cout << "temperatures[" << 2 << "][" << 0 << "] = " << temperatures[2][0] << std::endl;
    std::cout << "temperatures[" << 2 << "][" << 1 << "] = " << temperatures[2][1] << std::endl; */

//-------------
//спискова ініціалізація
    const int WEEK = 3, DAY = 2;
    int temperatures[WEEK][DAY] = 
    {
        {10, 20}, 
        {100, 200}, 
        {1000, 2000}
    };
// 42 масиви рядки

    char greeting1[5] = { 'h', 'e', 'l', 'l', 'o'};
    char greeting2[6] = "Hello"; //6 бо 0\ символ

    for (int i = 0; i < 5; i++)
        std::cout << greeting1[i];
    std::cout << std::endl; 
    std::cout << greeting2 << std::endl; 

//-------
    std::cout << "enter word: ";

    char word[30];

    std::cin >> word; //до першого пробелу читає

    std::cout << "your word: " << word << std::endl;
//--------
    char sentence [50];

    std::cout << "enter sentence: ";
    std::cin.getline(sentence, 50); //зчитвє до ентер

    std::cout << "your sentence: " << sentence << std::endl;

// 43 функції --------

    //функція іменовай набір коду, який може приймати якусть інформацію та овертати результат
    
    /*синтаксис визначення фукн:
    тип_повертаючого_значення імя_функціф(список_параметрів)
    {
     код
    }
    синтаксис виклику функції
    */
// 44 ------


    return 0;
}