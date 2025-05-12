#include <iostream>
#include <string>
#include <queue>
#include <list>

// черга — це структура даних, яка працює за принципом FIFO (First In, First Out),
// тобто перший елемент, який був доданий, буде першим, що буде видалено.
// черга забезпечує додавання елементів в кінець і видалення з початку.

template<typename T>
class Queue
{
private:
    std::list<T> list; // використовуємо список для збереження елементів черги

public:
    // видалення елементу з початку черги
    void Pop()
    {
        list.pop_front(); // pop_front() видаляє перший елемент зі списку
    }

    // додавання елементу в кінець черги
    void Push(const T& value)
    {
        list.push_back(value); // push_back() додає елемент у кінець списку
    }

    // отримання кількості елементів у черзі
    size_t Size() const
    {
        return list.size(); // size() повертає кількість елементів у списку
    }

    // обмін вмістом двох черг
    void Swap(Queue& other) noexcept
    {
        list.swap(other.list); // swap() міняє місцями вміст двох списків
    }

    // перевірка, чи пуста черга
    bool IsEmpty() const
    {
        return list.empty(); // empty() перевіряє, чи список порожній
    }

    // доступ до першого елементу черги
    T& Front()
    {
        return list.front(); // front() повертає перший елемент у списку
    }

    // константна версія доступу до першого елементу черги
    const T& Front() const
    {
        return list.front(); // const версія для доступу до першого елементу без змін
    }

    // доступ до останнього елементу черги
    T& Back()
    {
        return list.back(); // back() повертає останній елемент у списку
    }

    // константна версія доступу до останнього елементу черги
    const T& Back() const
    {
        return list.back(); // const версія для доступу до останнього елементу без змін
    }
};

// приклад класу для збереження особи (Person)
class Person
{
private:
    std::string name; // ім'я особи
    int age; // вік особи
public:
    Person() = default; // конструктор за замовчуванням

    // конструктор, який ініціалізує ім'я та вік
    Person(const std::string& name, int age)
        : name(name), age(age)
    {
    }

    // геттер для імені
    std::string Name() const
    {
        return name;
    }

    // геттер для віку
    int Age() const
    {
        return age;
    }
};

int main()
{
    Queue<double> myQueue;// створення черги для чисел типу double

    for (double value = 1.0; value < 3.0; value+=0.2) // додавання чисел до черги
    {
        myQueue.Push(value);
    }

    
    Queue<double> myQueue2;// створення іншої черги для чисел типу double

    
    for (double value = 5.0; value < 6.0; value += 0.3)// додавання чисел до іншої черги
    {
        myQueue2.Push(value);
    }

    
    myQueue.Swap(myQueue2);// обмін вмістом двох черг

    // виведення розміру та елементів першої черги
    std::cout << "Size = "<<myQueue.Size() << std::endl;
    while (!myQueue.IsEmpty())
    {
        std::cout << myQueue.Front() << "    "; // виведення першого елементу
        myQueue.Pop(); // видалення першого елементу
    }
    std::cout << std::endl;

    // виведення розміру та елементів другої черги
    std::cout << "Size = "<<myQueue2.Size() << std::endl;
    while (!myQueue2.IsEmpty())
    {
        std::cout << myQueue2.Front() << "    "; // виведення першого елементу
        myQueue2.Pop(); // видалення першого елементу
    }
    std::cout << std::endl;
    return 0;
}
