// [+] 1. Згадуємо інкапсуляцію - це конуепція ооп яка дозвволяє обєднувати жанні та методи їх обробки в одну єдину сутність яка наз. класом або структорую, і захищає їх від зовнішнього втручання завдяки модиф. доступу privat i protected
// [+] 2. Що таке наслідування? - це концепція ООп яка дозволяє створювати нові класи на основі уже існуючмх
// [+] 3. Визначення наслідування - це концепція ООп яка дозволяє створювати нові класи на основі уже існуючмх
// [+] 4. Реалізація наслідування

struct Point
{ };

class Person
{ };
// 1. Згадуємо інкапсуляцію - це конуепція ооп яка дозвволяє обєднувати данні 
//та методи їх обробки в одну єдину сутність яка наз. класом або структорую, 
//і захищає їх від зовнішнього втручання завдяки модиф. доступу privat i protected
/* 
class User
{
private:
    int age;

public:
    void SetAge(int age)
    {
        if (age > 0)
        {
            this->age = age;
        }
    }
};
 */

// 2. Що таке наслідування? - це концепція ООп яка дозволяє створювати нові класи на основі уже існуючмх
// 3. Визначення наслідування - це концепція ООп яка дозволяє створювати нові класи на основі уже існуючмх

// [-] 4. Реалізація наслідування -можна використовувати методи інших класів (батьківських)
/* 
Синтаксис наслідування:

class Ім'я_Дочірнього_Класу: Модифікатор_Наслідування Ім'я_Батьківського_Класу
{Реалізація Класу}
*/
class Vehicle //батьківський клас
{
private:
    Point position;
    double height;
    double length;
    double width;
    double weight;

public:
    void Move(Point direction); // Виправлено Nove → Move
    void Rotate(Point direction);
    void Scale(float factor);
};

class Car : public Vehicle //дочірній клас, успадкування від Vehicle
{
private:
    int doors;
    int tankCapacity;
    char model[30];
    char mark[30];
    bool isStarted;

public:
    void FillUp(int points);
    void Start();
};

class Plane : public Vehicle 
{
private:
    int seats; 
    Point route[2];

public:
    void AuthorizePeople(const Person* peopleList);
    void Fly();
    void CallDispatcher(const Person& dispatcher); // Передача за посиланням для оптимізації
};

int main()
{

    return 0;
}




