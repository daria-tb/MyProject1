#include <iostream>

int main()
{
    //cout - character output (вивід символів)
    std::cout << "Hello world" << std::endl;
    std::cout << std::endl;
    std::cout << "\\My name is Dasha!\\" << std::endl;
    std::cout << "ghjkldfghjk\n";
//----------------------------------------------------------------------------
    std::cout << "My name is Dasha!" << std::endl;
    return 0;
}


// \' - вивід одинарної лапки (застаріла, уже просто так можна виводити одинарну лапку).
// \? - оминання триграфів.
// \" - вивід подвійної лапки.
// \\ - вивід оберненої риски.
// \a - проігрування одинарного системного звуку (в сучасних комп'ютерах просто грає звук системного повідомлення).
// \b - переніс курсору на 1 позицію вліво. Ця послідовність являється клавішою backspace.
// \f - переніс курсору на нову сторінку (використовується в друці).
// \n - переніс курсору на наступний рядок. Ця послідовність являється клавішою Enter.
// \r - переніс курсору на початок даного рядка.
// \t - переніс курсору на наступну горизонтальну табуляцію. Ця послідовність являється клавішою Tab.
// \v - переніс курсору на наступну вертикальну табуляцію. (використовується в друці).
// \0цц - вивід символу по його коду у 8-ковій системі числення (ц - цифра)
// \Хцц - вивід символу по його коду у 16-ковій системі числення (ц - цифра)
// \Uцц - вивід символу по його коду у таблиці кодування Unicode (ц - цифра)