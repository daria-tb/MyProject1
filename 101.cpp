/*  */
#include <iostream>
#include <cstring>

//попереднє оголошення класу Shaman
class Shaman;

//клас Ork
class Ork 
{
private:
    int hp;
    char name[20];

public:
    Ork(const char* name, int hp = 100) 
    {
        if (name != nullptr && std::strlen(name) < 20)
            std::strncpy(this->name, name, 19);
        else
            std::strncpy(this->name, "NoName", 19);

        this->name[19] = '\0';
        this->hp = (hp > 0) ? hp : 100;
    }

    int GetHP() const { return hp; }
    const char* GetName() const { return name; }

    //Орк втрачає здоров'я
    void ReduceHP(int points) 
    {
        hp -= points;
        if (hp < 0) hp = 0;
        std::cout << name << " отримує " << points << " поранень. HP тепер: " << hp << std::endl;
    }

    //дружній клас
    friend class Shaman; //інший клас має доступ до приватних членів класу де оголошений цей дружній клпас
    //дружня функція для зміни імені
    friend void RenameOrk(Ork&, const char*);
    //дружній метод, який дозволяє шаману лікувати орка
    void SelfHeal(int healPoints) 
    {
        hp += healPoints;
        std::cout << name << " відновлюється на " << healPoints << " HP. HP тепер: " << hp << std::endl;
    }
};

//дружня функція для зміни імені орка
void RenameOrk(Ork& ork, const char* newName) {
    if (newName != nullptr && std::strlen(newName) < 20) 
    {
        std::strncpy(ork.name, newName, 19);
        ork.name[19] = '\0'; // Гарантія завершення рядка
        std::cout << "Ім'я орка змінено на: " << ork.name << std::endl;
    } 
    else 
    {
        std::cout << "Некоректне ім'я! Ім'я орка не змінено." << std::endl;
    }
}

//клас Shaman
class Shaman 
{
private:
    int hp;
    char name[20];

public:
    Shaman(const char* name, int hp = 100) 
    {
        if (name != nullptr && std::strlen(name) < 20)
            std::strncpy(this->name, name, 19);
        else
            std::strncpy(this->name, "NoName", 19);

        this->name[19] = '\0'; // Гарантія завершення рядка
        this->hp = (hp > 0) ? hp : 100;
    }

    int GetHP() const { return hp; }
    const char* GetName() const { return name; }

    //метод для лікування орка (дружній метод)
    void Heal(Ork& ork, int healPoints) 
    {
        ork.SelfHeal(healPoints); //викликає дружній метод Ork
        std::cout << name << " лікує орка " << ork.GetName() << " на " << healPoints << " HP." << std::endl;
    }
};

int main() 
{
    Ork myOrk("Demien", 100);
    Shaman myShaman("Sonya", 100);

    std::cout << "Ork name: " << myOrk.GetName() << "\n";
    std::cout << "Ork HP: " << myOrk.GetHP() << "\n";

    std::cout << "Shaman name: " << myShaman.GetName() << "\n";
    std::cout << "Shaman HP: " << myShaman.GetHP() << "\n";

    //Орк втрачає здоров'я
    myOrk.ReduceHP(30);

    //Шаман лікує орка (через дружній метод)
    myShaman.Heal(myOrk, 20);

    //Зміна імені орка
    RenameOrk(myOrk, "Grommash");

    return 0;
}