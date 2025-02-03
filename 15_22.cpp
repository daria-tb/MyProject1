#include <iostream>

//літерали,коментарі, оператор, ариф.опер., пріорітет опер., асоц.опер., комбін.ариф.опер., інкремент та декремент
int main()
{
    /* short a = 10;
    int b = 10;
    long c = 11L;
    long long d = 10LL;

    unsigned short a = 10;
    unsigned int b = 10U;
    unsigned long c = 10UL;
    unsigned long long d = 10ULL;

    float a = 1.5F;
    double b = 1.5;
    long double c = 1.5L;

    char a = 'g';
    wchar_t b = L'g';
    char16_t c = u'g';
    char32_t d = U'g'; */

    bool a = false;
    std::cout << a << std::endl;

    //оперетор людина, операнд кирпич, це все операція

    // - + - * / %
    int a1, b1;
    std::cout << "enter 2 num: ";
    std::cin >> a1 >> b1;

    a1 = 3 + 5;
    a1 = 3 - 5;
    a1 = 3 * 5;
    a1 = 3 / 5;

    int a2, b2;

    std::cout << "Enter two numbers: ";
    std::cin >> a2 >> b2;

    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "b2 = " << b2 << std::endl;

    std::cout << "+a2 = " << +a2 << std::endl;
    std::cout << "+b2 = " << +b2 << std::endl;

    std::cout << "-a2 = " << -a2 << std::endl;
    std::cout << "-b2 = " << -b2 << std::endl;

//---------------

    int a3 = 10, b3 = 7;

    std::cout << "a3 = " << a3 << std::endl;
    std::cout << "b3 = " << b3 << std::endl;
    std::cout << "a % b = " << a3 % b3 << std::endl;
//-------------
    std::cout << "Enter seconds: ";
    int userSeconds;
    std::cin >> userSeconds;
    const int SEC_IN_MIN = 60;

    // 200 s = 3 m 20 s
    int seconds = userSeconds % SEC_IN_MIN;
    int minutes = userSeconds / SEC_IN_MIN;
    std::cout << "It is " << seconds << " minutes and " << seconds << "seconds\n";
//--------------
    /* std::cout << "Enter seconds: ";
    int userSeconds;
    std::cin >> userSeconds;
    const int SEC_IN_MIN = 60;

    int seconds = userSeconds % SEC_IN_MIN;
    int minutes = userSeconds / SEC_IN_MIN;
    std::cout << "It is " << minutes << "minutes and " << seconds << "seconds\n"; */
//-------------------
   /*  std::cout << "Enter a number: " ;
    int number;
    std::cin >> number;

    std::cout << "Number = " << number << std::endl;
    number = number + 10;
    std::cout << "Number = " << number << std::endl;
    number = number 10;
    std::cout << "Number = " << number << std::endl;
    number = number * 2;
    std::cout << "Number = " << number << std::endl;
    number = number / 4;
    std::cout << "Number = " << number << std::endl;
    number = number % 2;
    std::cout << "Number = " << number << std::endl; */

    // таке саме як нижче

    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    std::cout << "Number = " << number << std::endl;
    number += 10;
    std::cout << "Number = " << number << std::endl;
    number -= 10;
    std::cout << "Number = " << number << std::endl;
    number *= 2;
    std::cout << "Number = " << number << std::endl;
    number /= 4;
    std::cout << "Number = " << number << std::endl;
    number %= 2;
    std::cout << "Number = " << number << std::endl;

//-------------------
    std::cout << "Enter a num1: ";
    int num1;
    std::cin >> num1;

    std::cout << "Num1 = " << num1 << std::endl;
    number += number + number / 2 * 3;
    std::cout << "Num1 = " << num1 << std::endl;

//----------------------
//in de
    std::cout << "Enter a num2: ";
    int num2;
    std::cin >> num2;

    std::cout << "Num2 = " << num2 << std::endl;
    num2++;
    std::cout << "Num2 = " << num2 << std::endl;
    num2--;
    std::cout << "Num2 = " << num2 << std::endl;
//---------------------
    int c = 1;
    //int d = c++; 
    int d = c++; 

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
//---------------------
    int k = 1, f = 2;
    int r = ++k + f--;
    std::cout << "r = " << r << std::endl;
//------------------
    return 0;
}