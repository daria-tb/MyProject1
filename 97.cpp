#include <iostream>

class DynamicNumber
{
private:
    int* number;

public:
    DynamicNumber (int value)
        : number(new int (value))
    { }
    void SetValue(int value)
    {
        *number = value;
    }
    int GetValue() const
    {
        return *number;
    }
    /* синтаксис створення конструктора:
    імя_класу(список_параметрів)

    синтаксис створення деструктора
    ~імя_класу()
    {
    }
    */
   ~DynamicNumber()
   {
        delete number;
        number = nullptr;
   }
};
//---------
class Test 
{
public:
    Test()
    {
        std::cout << "const\n";
    }
    ~Test()
    {
        std::cout << "destr\n";
    }
};
void Func()
{
    Test a;
}

int main() 
{
    Func();
    //деструктор це метод який автоматично викликається коли знищується обʼєкт
    {
        DynamicNumber number (5);

        std::cout << number. GetValue() << std::endl;
        number.SetValue(10);
        std::cout << number.GetValue() << std::endl;
        number.SetValue(3);
        std::cout << number.GetValue() << std::endl;   
    }
//------------------------------------------------------------------------------------------------------------
// вказівник this

    return 0;
}