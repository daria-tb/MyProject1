#include <iostream>
//ієрархія типів данних, привелення типів даних, сайзоф, опер.порівняння, логічні оператори

int main ()
{
    // long double
    // double
    // float
    // unsigned long long
    // long long
    // unsigned int
    // int
    // unsigned short
    // short
    // (Автоматичне приведення)

    int a = 2;
    char b = 'A';
    float c = 1.1F;
    double d = 2.2;

    /* std::cout << 5.2 / 2;
    std::cout << a + b + c + d; */

//----------
// char, bool, wchar_t, char16_t, char32_t, short, unsigned short (Автоматичне приведення> int)
    
    //std::cout << 'a' + 'b';
    std::cout << a + b + c + d << std::endl; //=70.3
    
//-----------

    //std::cout << true + true; //=2
    /* std::cout << true + false; //=1
    std::cout << false + false; */ //=0

//---------------------
    /* unsigned int a = 1;
    int b = 2;
    std::cout << a - b; */  
    //b перетворюється в unsigned int, тобто b = 2u. Виконується 1u - 2u = 4294967295u.

// 24 ----------------------

//явне перетворення ʼ приведення
//неявне

// 1 c ->  (тип)значення
// 2 с++ -> тип(значення)
// 3 с++ -> static_cast<тип>(значення)

    int side1 = 3, side2 = 4;
    //double division = (double)side1 / side2; //1
    //double division = double(side1) / side2; //2
    double division = static_cast<double>(side1) / side2; //3

    std::cout << division << std::endl;
// 25 ------------------------
// sizeof(тип_даних)
// sizeof(вираз/значення)
// sizeof вираз/значення

    std::cout << "--- Characters ---\n";
    std::cout << "char: " << sizeof(char) << std::endl;
    std::cout << "wchar_t: " << sizeof(wchar_t) << std::endl;
    std::cout << "char16_t: " << sizeof(char16_t) << std::endl;
    std::cout << "char32_t: " << sizeof(char32_t) << std::endl;

    std::cout << std::endl;

    std::cout << "--- Integers ---\n";
    std::cout << "short: " << sizeof(short) << std::endl;
    std::cout << "unsigned short: " << sizeof(unsigned short) << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "unsigned int: " << sizeof(unsigned) << std::endl;
    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "unsigned long: " << sizeof(unsigned long) << std::endl;
    std::cout << "long long: " << sizeof(long long) << std::endl;
    std::cout << "unsigned long long: " << sizeof(unsigned long long) << std::endl;

    std::cout << std::endl;

    std::cout << "--- Floats ---\n";
    std::cout << "float: " << sizeof(float) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "long double: " << sizeof(long double) << std::endl;
//----------------
/*     std::cout << "--- Characters ---\n";
    std::cout << "char: " << sizeof('f') << std::endl;
    std::cout << "wchar_t: " << sizeof(L'G') << std::endl;
    std::cout << "char16_t: " << sizeof(u'9') << std::endl;
    std::cout << "char32_t: " << sizeof(U'H') << std::endl; */

//----------------
    std::cout << sizeof(3)<< std::endl; //4
    std::cout << sizeof(3+2)<< std::endl; //4
    std::cout << sizeof(3+2.0)<< std::endl; //8 - результат типу дабл
//-------------------
    int num = 7;
    std::cout << sizeof(num) << std::endl;

// 26 -------------------
// >, <, <=, >=, ==, != (bool)
    //std::cout << (5 < 10); //1
    //std::cout << (5 > 10); //0
//------------------------
    //bool expression = 5 > 2; //>, <, <=, >=, ==, !=
    //bool expression = 765 >= 2; 
    //bool expression = 789 <= 5; 

    double a1 = 1.0 / 3;
    double b1 = 2.0 / 7;

    std::cout << a1 << " \n" << b1 << std::endl;
    bool expression = (10 + 6 == 30 - 14);

    std::cout << expression << std::endl;

// 27 ------------------------

// ! - логічне не
////////////////////// && - логічне І
// умова1 && умова2
// tr && tr > tr
// tr && fa > fa
// fa && tr > fa
// fa && fa > fa

    std::cout << "Enter numb: " << std::endl;
    int numb;
    std::cin >> numb;

    bool expression1 = (2 < numb && numb < 5);
    std::cout << expression1 << std::endl;

///////////////// || - логічне АБО
// умова1 && умова2
// tr && tr > tr
// tr && fa > tr
// fa && tr > tr
// fa && fa > fa

    std::cout << "Enter numb1: " << std::endl;
    int numb1;
    std::cin >> numb1;

    bool expression2 = ((numb1 == 50) || (numb1 == 80));
    std::cout << expression2 << std::endl;

///////////////// || - логічне НІ
// !умова
// !true = false
// !false = true

    bool expression3 = (!strcmp("Dasha", "dasha"));
    std::cout << expression3 << std::endl;
    
    bool expression4 = (!strcmp("dasha", "dasha"));
    std::cout << expression4 << std::endl;

    return 0;
}