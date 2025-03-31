#include <iostream>
/* -std=c++11 */
using namespace std;
/*
Поліморфізм і конструктори - для конструкторів ене можна писати ключове слово virtual
00:57:53 - Поліморфізм і деструктори */
/* class Base 
{
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; } // ВІРТУАЛЬНИЙ!
};

class Derived : public Base 
{
public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};
 */
/* 01:10:48 - Ключове слово override 
01:16:42 - Ключове слово final 
01:19:40 - Що таке раннє і пізнє зв'язування? 
01:27:25 - Таблиця віртуальних функцій (vtable) */

/* 
- Інкапсуляція - це концепція в ооп яка жозволяє обєднувати данні та методи їх обробки 
в одну єдину сутність (структура або клас) та дозволяє їх захищати від зовнішнього втручання 
завдяки модифікаторам доступу privat, protected, public. 

- Наслідування - це концепція в ооп яка дозволяє створювати нові класи 
на основі вже існуючих(без дублювання полів та методів)

- Поліморфізм - це концепція в ооп яка дозволяє отримувати різну реалізацію 
за один інтерфейс(різну реал. коду)

Перевантаження функцій - це можливість визначати кілька функцій з однаковим іменем, 
але з різними наборами параметрів. Компілятор визначає, яку саме функцію викликати, 
залежно від кількості, типів та порядку аргументів.

Шаблони ф-й дозволяють створювати узагальнені функції, 
які можуть працювати з різними типами даних без необхідності перевантаження. 
Це дозволяє уникнути дублювання коду та робить програму більш гнучкою. 
*/

template <typename T>
void Show(const T arr[], size_t size) 
{
    for (size_t i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//-----
void Show1(int number) 
{
    std::cout << number << std::endl;
}

void Show1(const char* str) 
{
    size_t size = std::strlen(str);
    for (size_t i = 0; i < size; i++) 
    {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
}
//-----------------
struct Position 
{
    int x, y;
};

class Unit 
{
private:
    Position position;
    int hp; // health points

public:
    Unit(const Position& position, int hp)
        : position(position), hp(hp > 0 ? hp : 100) {}

    Position GetPosition() const { return position; }
    int GetHP() const { return hp; }

    virtual void Show9() const 
    {
        std::cout << "Unit info:\n";
        std::cout << "Position: [" << position.x << ", " << position.y << "]\n";
        std::cout << "HP: " << hp << "\n";
    }
};

// Лучник
class Archer : public Unit 
{
private:
    float bowDamage;
    int countArrows;

public:
    Archer(const Position& position, int hp, float bowDamage, int countArrows)
        : Unit(position, hp),
          bowDamage(bowDamage > 0 ? bowDamage : 0),
          countArrows(countArrows > 0 ? countArrows : 8) {}

    float GetBowDamage() const { return bowDamage; }
    int GetArrowsCount() const { return countArrows; }

    void Show9() const override 
    {
        Unit::Show9();
        std::cout << "Archer Info:\n";
        std::cout << "Bow damage: " << bowDamage << "\n";
        std::cout << "Arrows: " << countArrows << "\n";
    }
};

// Мечник
class Swordsman : public Unit 
{
private:
    float swordDamage;
    int armorLevel;

public:
    Swordsman(const Position& position, int hp, float swordDamage, int armorLevel)
        : Unit(position, hp),
          swordDamage(swordDamage > 0 ? swordDamage : 0),
          armorLevel(armorLevel > 0 ? armorLevel : 0) {}

    float GetSwordDamage() const { return swordDamage; }
    int GetArmorLevel() const { return armorLevel; }

    void Show9() const override 
    {
        Unit::Show9();
        std::cout << "Swordsman Info:\n";
        std::cout << "Sword damage: " << swordDamage << "\n";
        std::cout << "Armor level: " << armorLevel << "\n";
    }
};

void ShowInfoOnUI(const Unit& unit)
{
    std::cout << "\n";
    unit.Show9();
    std::cout << "----------------\n";
};

int main() 
{
    //Що таке параметризований поліморфізм? 
    int arr1[] = {1, 2, 3};
    double arr2[] = {1.1, 2.2, 3.3};
    char arr3[] = {'A', 'B', 'C'};

    Show(arr1, 3);
    Show(arr2, 3);
    Show(arr3, 3);

    //Що таке ad-hoc поліморфізм?
    int number = 10;
    char str[] = "Hello World";

    Show1(number);
    Show1(str);

    //Що таке поліморфізм підтипів?
    //Віртуальні методи - (метод)  у дочірніх класах його можна перевизначити
        Unit unit(Position{20, 30}, 100);
    Archer archer(Position{25, 40}, 80, 30, 20);
    Swordsman swordsman(Position{100, 32}, 200, 35, 4);

    ShowInfoOnUI(unit);
    ShowInfoOnUI(archer);
    ShowInfoOnUI(swordsman);

    return 0;
}


/* #include <iostream>

class A {
public:
    void UsualMethodA() { std::cout << "I'm usual method A\n"; }

    virtual void Method() { std::cout << "A::Method()\n"; } // Віртуальний метод
};

class B : public A {
public:
    void UsualMethodB() { std::cout << "I'm usual method B\n"; }

    virtual void Method() { std::cout << "B::Method()\n"; } // Перевизначений метод
};

class C : public B {
public:
    void UsualMethodC() { std::cout << "I'm usual method C\n"; }

    virtual void Method() { std::cout << "C::Method()\n"; } // Перевизначений метод
};

int main() {
    C objectC;
    
    A* ptrA = &objectC; // Покажчик на базовий клас A
    B* ptrB = &objectC; // Покажчик на клас B
    C* ptrC = &objectC; // Покажчик на клас C

    std::cout << "Calling Method() through different pointers:\n";
    ptrA->Method(); // Викличе C::Method()
    ptrB->Method(); // Викличе C::Method()
    ptrC->Method(); // Викличе C::Method()

    return 0;
} */





