// [+] 5. Модифікатор доступу protected
// [-] 6. Наслідування і конструктори

// 5. Модифікатор доступу protected
//використовується для визначення рівня доступу до змінних та методів класу
// -члени класу з модифікатором protected доступні всередині самого класу.
// -успадковані класи можуть використовувати protected-члени без обмежень.
// -але об'єкти зовнішніх класів не можуть звертатися до protected-членів безпосередньо.

//якщо писати взагалі без модифікатору то автоматично все буде private
/*  ПРИКЛАД
class Vehicle //батьківський клас
{
private:
    Point position;
    double height;
    double length;
    double width;

protected:
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
    void FillUp(int points)
    {
        weight += points;
    }
    void Start();
}; 
*/

// 6. Наслідування і конструктори
