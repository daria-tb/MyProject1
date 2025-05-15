// Робота з контейнером forward_list
// Конструктори
// Деструктор
// Методи
// Перевантаження глобальних операторів і функцій
// Member types — типи-учасники

// forward_list — односпрямований список

#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

class Person {
private:
    int age;
    std::string name;

public:
    Person() : age(0), name("") {
        std::cout << "Default constructor" << std::endl;
    }

    Person(int age, const std::string& name) : age(age), name(name) {
        std::cout << "2param constructor" << std::endl;
    }

    Person(int age, const std::string& name)
        : age(age), name(name)
    {
        std::cout << "2param constructor\n";
    }

    Person(const Person& other)
        : age(other.age), name(other.name)
    {
        std::cout << "Copy constructor\n";
    }

    Person(Person&& other) noexcept
        : age(other.age), name(other.name)
    {
        std::cout << "Move constructor\n";
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            std::cout << "copy operator=\n";
            age = other.age;
            name = other.name;
        }
        return *this;
    }

    Person& operator=(Person&& other) noexcept
    {
        if (this != &other)
        {
            std::cout << "move operator=\n";
            age = std::move(other.age);
            name = std::move(other.name);
        }
        return *this;
    }

    const std::string& Name() const
    {
        return name;
    }

    int Age() const
    {
        return age;
    }
};

bool operator==(const Person& person1, const Person& person2)
{
    return person1.Age() == person2.Age() && person1.Name() == person2.Name();
}

bool operator<(const Person& person1, const Person& person2)
{
    return person1.Name() < person2.Name();
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "[Name: " << person.Name() << ", Age: " << person.Age() << "]\n";
    return os;
}

void Show(const std::forward_list<int>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "Elements: ";
		for (int value : container)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

void Show(const std::forward_list<Person>& container)
{
	if (container.empty())
	{
		std::cout << "Container is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "Elements: ";
		for (const Person& person : container)
		{
			std::cout << "\t(Name: " << person.Name() <<
				", age: " << person.Age() << ")\n";
		}
		std::cout << std::endl;
	}
}

int main()
{
	/// Конструктори
	std::cout << "--- Constructors ---\n";
	{
		std::forward_list<int> container1; // конструктор за замовчуванням
		Show(container1);

		std::forward_list<int> container2 = { 1,10,30 }; // список ініціалізації
		Show(container2);

		std::vector<int> vec = { 1,2,3,4,5 };
		std::forward_list<int> container3(vec.cbegin(), vec.cend()); // з діапазону
		Show(container3);

		std::forward_list<int> container4(container3); // копіювання
		Show(container4);

		std::forward_list<int> container5(std::move(container2)); // переміщення
		Show(container5);

		std::forward_list<int> container6(6); // створення 6 елементів зі значенням 0
		Show(container6);

		std::forward_list<int> container7(5, 25); // створення 5 елементів зі значенням 25
		Show(container7);
	}
	std::cout << "\n\n";


	/// Деструктор
	std::cout << "--- Destructor ---\n";
	{
		std::forward_list<Person> container(2); // створюється список з 2 об'єктів Person
	}
	std::cout << "\n\n";

	/// Методи
	std::cout << "--- Methods ---\n";
	{
		std::forward_list<int> list;
		std::forward_list<int> otherList{ 0,1,0,1 };
		std::list<int> otherContainer { 1000,999,888 };

		// 1. operator=
		list = { 100,101,102,103 };
		Show(list);
		list = std::forward_list<int>(10,-1); // список з 10 значень -1
		Show(list);
		list = otherList;
		Show(list);

		// 2. assign
		list.assign(5, 100); // 5 елементів зі значенням 100
		Show(list);
		list.assign({ -1, -2, -3 }); // список ініціалізації
		Show(list);
		list.assign(otherContainer.begin(), otherContainer.end()); // з іншого контейнера
		Show(list);

		// 3. get_allocator
		auto alloc = list.get_allocator(); // отримання алокатора

		// 4. front
		std::cout << "Front: " << list.front() << std::endl;
		list.front() = 1000;
		std::cout << "Front: " << list.front() << std::endl;

		// 5–8. ітератори
		Show(list);
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			*it += 1000;
		}
		for (auto it = list.cbegin(); it != list.cend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// 9. clear
		list.clear();
		Show(list);

		// 10–11. push_front / pop_front
		list.push_front(10);
		list.push_front(20);
		list.push_front(30);
		Show(list);
		list.pop_front();
		list.pop_front();
		Show(list);

		// 12. sort
		list = { 5,4,3,2,1 };
		list.sort(); // за зростанням
		Show(list);
		list.sort([](int value1, int value2) { return value1 > value2; }); // за спаданням
		Show(list);

		// 13. unique
		list = { 1,1,2,2,3,3,4,4,5,5 };
		Show(list);
		list.unique();
		Show(list); 

		// 14. reverse
		list = { 1,10,100 };
		Show(list);
		list.reverse();
		Show(list);

		// 15. swap
		list = { 1,2,3 };
		std::forward_list<int> list2{ 10,20,30,40 };
		Show(list);
		Show(list2);
		list.swap(list2);
		Show(list);
		Show(list2);

		// 16. resize
		list.resize(1);
		Show(list);
		list.resize(10);
		Show(list);

		// 17–18. remove / remove_if
		list = { 1,2,3,4,5,6,7,8,9 };
		Show(list);
		list.remove(2);
		Show(list);
		list.remove_if([](int value) { return value >=5; });
		Show(list);

		// 19. merge
		list = { 1,10,100 };
		list2 = { 0,2,5,20,40,200 };
		list.merge(list); // об’єднує сам із собою (небезпечна операція)
		Show(list);
		Show(list2);

		// 20. emplace_front
		{
			std::forward_list<Person> people;
			people.emplace_front(25, "Demian");
			people.emplace_front(26, "Olga");
			people.emplace_front(22, "Helena");
			Show(people);
		}

		// 21. empty
		list = { 1,2,3 };
		std::cout << (list.empty() ? "List is empty\n" : "List is not empty\n");
		list.clear();
		std::cout << (list.empty() ? "List is empty\n" : "List is not empty\n");

		// 22. max_size
		std::cout << "Max size = " << list.max_size() << std::endl;

		// 23–28. insert_after, emplace_after, erase_after, splice_after
		{
			// insert_after:
			list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Show(list);
			auto iter1 = std::find(list.cbegin(), list.cend(), 5);
			list.insert_after(iter1, 100);
			Show(list);

			// emplace_after:
			std::forward_list<Person> people {
				Person(10, "George"),
				Person(25, "Demian"),
				Person(20, "Viktoria"),
			};
			Show(people);
			auto iter2 = std::find(people.cbegin(), people.cend(), Person(25, "Demian"));
			people.emplace_after(iter2, 30, "David");
			Show(people);

			// before_begin / cbefore_begin:
			list.insert_after(list.before_begin(), { 200, 200, 200 });
			Show(list);

			// erase_after:
			list.erase_after(iter1);
			Show(list);

			// splice_after:
			list2 = { 1000, 1001, 1002 };
			list.splice_after(iter1, list2);
			Show(list);
			Show(list2);
		}
	}
	std::cout << "\n\n";

	/// Глобальні оператори та функції
	std::cout << "--- Global operators and functions ---\n";
	{
		// 1. operator== — порівнює два списки.
		// true — якщо всі елементи однакові й у тому ж порядку
		std::forward_list<int> list1 = { 1, 2, 3 };
		std::forward_list<int> list2 = { 1, 2, 3 };
		std::forward_list<int> list3 = { 1, 2, 3, 4 };
		std::forward_list<int> list4 = { 1, 2, 5 };

		if (list1 == list2)
			std::cout << "list1 == list2\n";
		if (list1 == list3) // ні, різна довжина
			std::cout << "list1 == list3\n";
		if (list1 == list4) // ні, різні елементи
			std::cout << "list1 == list4\n";

		// Оператори 2–6 доступні з C++20.
		// 2. operator!=
		// 3. operator<
		// 4. operator<=
		// 5. operator>
		// 6. operator>=

		// У C++20 з'явився <=> (трикрапковий оператор порівняння)

		// 8. std::swap — викликає forward_list::swap()

		// У C++20 також додано:
		// 9. std::erase
		// 10. std::erase_if
	}
	std::cout << "\n\n";

	// Типи-учасники (member types)
	std::cout << "--- Member types ---\n";
	{
		std::forward_list<int>::value_type value = 10;               // int value = 10;
		std::forward_list<int>::const_reference reference = value;  // const int& reference = value;
		std::forward_list<int>::pointer pointer = &value;           // int* pointer = &value;
	}
	std::cout << "\n\n";

	return 0;
}