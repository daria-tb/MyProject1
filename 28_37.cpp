#include <iostream>

int main()
{
    /* 28
    Синтаксис оператора if:
    if (умова/вираз)
    {
        Перелік_Дій
    }
    */

    std::cout << "Enter a num1: ";
    int num1;
    std::cin >> num1;

    if (num1 == 0) //!num1
    {
        std::cout << "You entered zero!\n";
    }
//-------
    std::cout << "Enter a num2: " << std::endl;
    int num2;
    std::cin >> num2;

    if (num2)
    {
        std::cout << "Yes!\n";
    }
//-------
    std::cout << "Enter a num3: " << std::endl;
    int num3;
    std::cin >> num3;

    if (num3 == 10)
    {
        std::cout << "I don`nt like this number! Try again: \n";
        std::cin >> num3;
    }
    std::cout << "Ok! you entered " << num3 << std::endl;
//------

// if (умова 1)
//      дія 1
// else
//      дія 2

    std::cout << "Enter a num4 in range [1...10]: " << std::endl;
    int num4;
    std::cin >> num4;

    if (num4 >= 1 && num4 <= 10)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";

    }
//-------
    //3 if
    std::cout << "Enter a num5: " << std::endl;
    int num5;
    std::cin >> num5;

    if (num5 == 1)
    {
        std::cout << "One.\n";
    }
    else if (num5 == 2)
    {
        std::cout << "Two.\n";
    }
    else if (num5 == 3)
    {
        std::cout << "Three.\n";
    }
    else
    {
        std::cout << "Other.\n";
    }
// 29 ----------

    /*
    if (умова №1)
        Дія №1
    else
        Дія №2 */

    /*
    синтаксис тернарного оператора 
    умова ? вираз1 або  дія1 : вираз2 або дія2
    */

    std::cout << "Enter two num6_7: " << std::endl;
    int num6, num7;
    std::cin >> num6 >> num7;

    //int max;
    /* if (num6 > num7)
        max = num6;
    else if (num7 > num6)
        max = num7;
    else
        max = num6; */

    /* if (num6 > num7)
        max = num6;
    else
        max = num2; */

    int max = (num6 > num7) ? num6 : num7;

    std::cout << "Max = " << max << std::endl;

//---------
    // x > 0 && y > 0 -> 1
    // x < 0 && y > 0 -> 2
    // x < 0 && y < 0 -> 3
    // x > 0 && y < 0 -> 4
    // x == 0 && у == 0 -> між площинами

    std::cout << "Enter x: " << std::endl; 
    int x; 
    std::cin >> x;

    std::cout << "Enter y: " << std::endl; 
    int y; 
    std::cin >> y;

    std::cout << (x > 0 && y > 0 ? 
    "1" : (x < 0 && y > 0) ? 
    "2" : (x < 0 && y < 0) ? 
    "3" : (x > 0 && y < 0) ? 
    "4" : "Between") << std::endl;


    /* if (x > 0 && y > 0) 
        std::cout << "1\n";
    else if (x < 0 && y > 0) 
        std::cout << "2\n"; 
    else if (x < 0 && y < 0) 
        std::cout << "3\n"; 
    else if (x > 0 && y < 0) 
        std::cout << "4\n";
    else 
        std::cout << "Between\n"; */

// 30 ------------------
 /*
    синтаксис оператору switch
    switch (імʼя змінної)
    {
        case значення1:
            перелік дій 1
            break;
        case значення2:
            перелік дій 2
            break;
        case значення3:
            перелік дій 3
            break;
        default:
            Перелік дій за замоувчуванням
            break;

    }
  */


    int num8 = 3;

    switch (num8)
    {
    case 1:
        std::cout << "It's 1!\n";
        std::cout << num8 << std::endl;
        break;

    case 2:
        std::cout << "It's 2!\n";
        std::cout << num8 * 2 << std::endl;
        break;

    case 3:
        std::cout << "It's 3!\n";
        std::cout << num8 * 3 << std::endl;
        break;

    default:
        std::cout << "No!\n" << std::endl;
        break;
    }

    /* if (num8 == 1)
    {
        std::cout << "It's 1!\n";
        std::cout << num8 << std::endl;
    }
    else if (num8 == 2)
    {
        std::cout << "It's 2!\n";
        std::cout << num8 * 2 << std::endl;
    }
    else if (num8 == 3)
    {
        std::cout << "It's 3!\n";
        std::cout << num8 * 3 << std::endl;
    }
    else 
    {
        std::cout << "No!\n";
    } */

// 31 ------------------ цикл

//дія: ввести число і додати до суми
//умова: поки число не рівне 0

// while
// do while
// for

// 32 while ----------

/* синатксис циклу while - викор коли не знаєио кількість ітерацій

    while (умова)
    {
    перелік дій
    }
*/

    int stars = 0;

    while (stars < 10) // while (stars++ < 10); ітерація 
    {
        std::cout << "+" << std::endl;
        stars++;
    }

    int numb = 1;

    while (numb < 20)
    {
        std::cout << numb << " " << std::endl; // або std::cout << numb++ << " "; без другого ряка
        numb++;
    }

//-------

    std::cout << "enter 2 bounds" << std::endl;
    int min1, max1;
    std::cin >> min1 >> max1;

    int numb1 = min1; 
    while (numb1 <= max1)
    {
        std::cout << numb1++ << " " << std::endl;
    }
// ---------------

    int sum2 = 0;
    int numb2;

    std::cout << "enter a numb2 (or 0 to stop): " << std::endl;
    std::cin >> numb2;
    sum2 += numb2;

    while (numb2 != 0)
    {
        std::cout << "enter a numb2 (or 0 to stop): " << std::endl;
        std::cin >> numb2;
        sum2 += numb2;
    }
    
    std::cout << "sum2 = " << sum2 << std::endl;

// 33 - do while

    /*
        по любому виконується умова хоча б 1 раз

        do
        {
            перелік дій
        } while (умова)
    */

   int stars2 = 0;

   do
   {
        std::cout << "*" << std::endl;
        stars2++;
   } while (stars2 < 5);
   
//-----------
// через while

    int numb3;

    /* std::cout << "enter a numb3 (or negative to stop): ";
    std::cin >> numb3;

    while (numb3 >= 0)
    {
        std::cout << "square = " << numb3 * numb3 << std::endl;

        std::cout << "enter a numb3 (or negative to stop): ";
        std::cin >> numb3;
    } */

    do 
    {
        std::cout << "enter a numb3 (or negative to stop): ";
        std::cin >> numb3;

        std::cout << "square = " << numb3 * numb3 << std::endl;

    } while (numb3 >= 0); //використовується коли у умові є змінна яка визначається у циклі
// for -------------

    //виконання циклу конкретну кількість разів
/* синтаксис 
    for (щператор_ініц; умова; оператор_зміни)
    {
        перелік_дій
    }
*/
    for (int star = 0; star < 10; star++)
    {
        std::cout << "*" << std::endl;
    }
//---------
    /* for (int numb4 =1; numb4 <= 10; numb4++) //зміна живе до кінця циклу, і можна створити таку змінну(з такою назвою) іншого типи 
    {
        std::cout << numb4 << " ";
    } */

   int numb4; //якщо потім треба викор. цю змінну
   for (numb4 = 1; numb4 <= 10; numb4++) 
    {
        std::cout << numb4 << " " << std::endl;
    }

//-------
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        std::cout << letter << std::endl;
    }
//------------
    for (int numb5 = 1, numb6 = 20; numb5 < 10 && numb6 < 40; numb5++, numb6++)
    {
        std::cout << numb5 << " " << numb6 << std::endl;
    }
// 36 break ----------

    int criticalNum = 5;

    int mini, maxi;
    std::cout << "enter mins and maxi: " << std::endl;
    std::cin >> mini >> maxi;

    /* int numb7;
    for (numb7 = mini; numb7 <= maxi && numb7 != criticalNum; numb7++)
    {
        std::cout << numb7 << " ";
    }
    std::cout << std::endl;

    if (numb7 == criticalNum)
    {
        std::cout << "we found cratical numb7.\n";
    } */

   for (int numb7 = mini; numb7 <= maxi; numb7++)
    {
       if (numb7 == criticalNum)
        {
            std::cout << "error\n" << std::endl;
            break;
        }

        std::cout << numb7 << " ";
    }

    std::cout << std::endl;
//-----------

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter a day number: "; 
        int day;
        std::cin >> day;

        switch (day)
        {
        case 1:
            std::cout << "It's Monday \n"; 
            break;
        case 2:
            std::cout << "It's Tuesday \n"; 
            break;
        case 3:
            std::cout << "It's Wednesday \n"; 
            break;
        case 4:
            std::cout << "It's Thursday \n"; 
            break;
        case 5:
            std::cout << "It's Friday \n"; 
            break;
        case 6:
            std::cout << "It's Suturday \n"; 
            break;
        case 7:
            std::cout << "It's Sunday \n"; 
            break;
    }

// 37 continue (переходимо на наступну ітерацію)-----------
// while - умова
// do while - умова
// for - блок_інкременту
    int sum1 = 0;
    int numb5;

    do 
    {
        std::cout << "enter next positive numb8 (or 0 to stop): ";
        std::cin >> numb5;

        if (numb5 < 0)
        {
            std::cout << "you entered negative numb5\n";
            continue;
        }

        sum1 += numb5;

    } while (numb5 != 0);

    std::cout << "sum1 = " << sum1 << std::endl;

    return 0;
}}
