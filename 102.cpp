#include <iostream>
//статичні члени класу

class Tank
{
private:
    static int tanks;
    static int destroyedTanks;
    int damage;
    int hp;
    float moveSpeed; // km/h
    float rotateSpeed; // degrees/second
    bool isAlive;

public:
    Tank(int damage = 5, int hp = 100, float moveSpeed = 30, float rotateSpeed = 3)
        : damage(damage > 0 ? damage : 5), hp(hp > 0 ? hp : 100),
          moveSpeed(moveSpeed > 0 ? moveSpeed : 30), rotateSpeed(rotateSpeed > 0 ? rotateSpeed : 3),
          isAlive(true)
    {
        tanks++;
    }
    
    ~Tank()
    {
        if (!isAlive) 
        {
            destroyedTanks++;
        }
        tanks--;
    }
    
    int GetDamage() const { return damage; }
    int GetHP() const { return hp; }
    float GetMoveSpeed() const { return moveSpeed; }
    float GetRotateSpeed() const { return rotateSpeed; }
    bool IsAlive() const { return isAlive; }
    
    static int GetTanks() { return tanks; }
    static int GetDestroyedTanks() { return destroyedTanks; }
    
    void ReduceHP(int points)
    {
        if (points > 0)
        {
            hp -= points;
            if (hp <= 0)
            {
                hp = 0;
                isAlive = false;
            }
        }
    }
};

int Tank::tanks = 0;
int Tank::destroyedTanks = 0;

int main()
{
    std::cout << "Number of tanks: " << Tank::GetTanks() << std::endl;
    
    Tank* tank1 = new Tank();
    Tank* tank2 = new Tank();
    Tank* tank3 = new Tank();

    std::cout << "Number of tanks after creation: " << Tank::GetTanks() << std::endl;

    tank1->ReduceHP(100);
    delete tank1;
    tank1 = nullptr;

    std::cout << "Number of tanks: " << Tank::GetTanks() << ", Destroyed: " << Tank::GetDestroyedTanks() << std::endl;

    tank3->ReduceHP(100);
    delete tank3;
    tank3 = nullptr;

    std::cout << "Number of tanks: " << Tank::GetTanks() << ", Destroyed: " << Tank::GetDestroyedTanks() << std::endl;

    tank2->ReduceHP(100);
    delete tank2;
    tank2 = nullptr;

    std::cout << "Number of tanks: " << Tank::GetTanks() << ", Destroyed: " << Tank::GetDestroyedTanks() << std::endl;

    return 0;
}
