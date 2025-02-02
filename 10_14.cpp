#include <iostream>

int main()
{
// (10) RAW - string - рядки в C++ дозволяють записувати рядки без необхідності екранізації спеціальних символів (наприклад, лапок, слешів тощо). Це зручно, коли потрібно включити в рядок текст з великою кількістю спецсимволів, виразів. 
 //std::cout << R"(<head><h1>Hello</h1></head>)" << std::endl;
//----------------------------------------------------------------------------------------------------------------------------
// (12) змінні
    int myAge = 18; //тип_данних ім.я_змінної = значення
    std::cout << "my age is " << myAge << std::endl;

    short num = 1000;
    
    double a = 2.6;
    
    char ch = '$';
    
    bool c = 20;
    bool b = 0;

    std::cout << 3.5 + a << std::endl;
    std::cout << ch << std::endl;
    std::cout << c << std::endl;
    std::cout << b << std::endl;
//----------------------------------------------------------------------------------------------------------------------------
// (13) константи
    const double PI = 3.14;
    int number1 = 3;
    number1 = 5;

    std::cout << "PI = " << PI << std::endl;
    std::cout << "PI + 2 = " << PI + 2 << std::endl;
    //задавати можна так як і змінні =, (), ={}, {}
//----------------------------------------------------------------------------------------------------------------------------
    // (14) ввід інформації
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "you entered " << number << std::endl;
//----------------------------------------------------------------------------------------------------------------------------
    int number3, number4;
    int sum;
    std::cout << "Enter first number: ";
    std::cin >> number3;
    std::cout << "Enter second number: ";
    std::cin >> number4;
    sum = number3 + number4;  // Оператор присвоєння для обчислення суми
    std::cout << "Sum = " << sum << std::endl;
//----------------------------------------------------------------------------------------------------------------------------
    std::cout << "Enter the side of the square: ";
    int side;
    std::cin >> side;
    int perimeter = side * 4;
    std::cout << "Perimeter = " << perimeter << std::endl;
    int area = side * side;
    std::cout << "Area = " << area << std::endl;

//----------------------------------------------------------------------------------------------------------------------------
    std::cout << "Enter the radius of the circle: ";
    double radius;
    std::cin >> radius;

    const double PI = 3.1415;
    double diameter = radius * 2;
    double area = PI * radius * radius;
    double length = 2 * PI * radius;

    std::cout << "----- Circle information--\n";
    std::cout << "Radius = " << radius << std::endl;
    std::cout << "Diameter = " << diameter << std::endl;
    std::cout << "Area = " << area << std::endl;
    std::cout << "Length = " << length << std::endl;
    
    return 0;
}

/*Тип	            Розмір (байти)	    Діапазон
signed char	            1	            -128 ... 127
short (short int)	    2	            -32 768 ... 32 767
int	                    (2)4	        -2 147 483 648 ... 2 147 483 647
long (long int)         4(Win)/8(Unix)	

4 байти: -2 147 483 648 ... 2 147 483 647
8 байт: -9 223 372 036 854 775 808 ... 9 223 372 036 854 775 807

long long	            8           	-9 223 372 036 854 775 808 ... 9 223 372 036 854 775 807*/

// unsigned - від 0 до +...х2(напр. char не 127 а 255)


/*  Тип дробовий    Розмір (байти)	    Діапазон*	                                        Точність (значущих цифр)
    float	        4	            приблизно 1.2×10⁻³⁸ ... 3.4×10³⁸	                    ~6-7
    double	        8	            приблизно 2.3×10⁻³⁰⁸ ... 1.7×10³⁰⁸	                    ~15-16
    long double	    8, 10 або 16	залежить від реалізації (зазвичай ширший, ніж double)	більше, ніж у double */

/* 
Тип символьний	Розмір (байти)	         Діапазон	
char            1                       (-128 ... 127)/(0 ... 255) 
wchar_t	        2/4	                    (-32 768...32 767)/(0...65 535)
char16_t	    2                       (-32 768...32 767)/(0...65 535)
char32_t	    4	                    (-2 147 483 648...2 147 483 647)/(0 ... 4 294 967 295)
*/

/*
bool (бул) (1б) = true = 1/false = 0
*/
