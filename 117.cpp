//Перезавантаження оператора виклику функції
#include <iostream>

class EvenOddFunctor
{
private:
    int evenSum = 0;
    int oddSum = 0;

public:
    void operator() (int number)
    {
        if (number % 2 == 0)
        {
            evenSum += number;
        }
        else
        {
            oddSum += number;
        }
    }
    int GetEvenSum() const { return evenSum; }
    int GetOddSum() const { return oddSum; }
};

class Greeting
{
private:
    int value = 7;

public:
    int operator()(const char* name, int age) const //функціональні обʼєкти

    {
        std::cout << "Hello, " << name << "!\n";
        std::cout << "your age is " << age << "!\n";
        //value = 6; якщо без конст після дужок
        std::cout << "value = " << value << "!\n";

        return 2025;
    }

    void operator()() const
    {
        std::cout << "hello\n";
    }
//Синтаксис перезавантаження оператора виклику функції:
//Тип-Повертаючого_Значення operator () (Список_Параметрів)
//{Код}

};

int main()
{
    Greeting myGreeting;

    int value = myGreeting("Dasha", 18);//при перезавантаженні оператора виклику функ ваш обʼєкт може себе вести як функ
    std::cout << value << std::endl;

    myGreeting();
    //----------------

    EvenOddFunctor functor;
    
    const size_t SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 0; i < SIZE; i++)
    {
        functor(arr[i]);
    }
    std::cout << "Even numbers: " << functor.GetEvenSum() << "\n";
    std::cout << "Odd numbers: " << functor.GetOddSum() << std::endl;
    return 0;
}


