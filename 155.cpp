/* принцип роботи контейнера deque
Конструктори класу
Деструктор класу
Основні методи контейнера
Глобальні перевантаження операторів і допоміжні функції
Оцінка складності операцій у нотації O*/

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>

class Person 
{
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

template<typename T>
void Show(const std::deque<T>& dq)
{
    for (const auto& el : dq)
        std::cout << el << " ";
    std::cout << "\n";
}

int main()
{
	//Constructors
	{
		std::cout << "Constructors\n";
		// 1. Default constructor
		{
			std::deque<int> deque; // empty deque
			Show(deque);
		}
		// 2. std::initializer_list constructor
		{
			std::deque<int> deque{ 1, 2, 3, 4, 5 };
			Show(deque);
		}
		//3. Copy constructor
		{
			std::deque<int> deque1{ 1, 2, 3, 4, 5 };
			std::deque<int> deque2(deque1); // copy constructor
			Show(deque2);
		}
		// 4. Move constructor
		{
			std::deque<int> deque1{ 1, 2, 3, 4, 5 };
			std::deque<int> deque2(std::move(deque1)); // move constructor
			Show(deque2);
			Show(deque1); // deque1 is now empty
		}
		// 5. Parameters: Iterator begin, Iterator End
		{
			std::deque<int> deque1{ 1, 2, 3, 4, 5 };
			std::deque<int> deque2(deque1.begin(), deque1.end()); // copy constructor
			Show(deque2);
		}
		// 6. Parameters: size_t count
		{
			std::deque<int> deque(5); // 5 elements with value 0
			Show(deque);
		}
		// 7 . Parameters: size_t count, const T& value
		{
			std::deque<int> deque(5, 10); // 5 elements with value 10
			Show(deque);
		}
	}
	
	// Destructors
	{
		std::cout << "Destructors\n";
		std::deque<Person> people;
	}
	// Methods
	{
		std::cout << "Methods\n";
		std::deque<int> deque{ 1, 2, 3, 4, 5 };
		Show(deque);


		deque.push_back(6); // Add to the end
		Show(deque);

		deque.push_front(0); // Add to the front
		Show(deque);

		deque.pop_back(); // Remove from the end
		Show(deque);

		deque.pop_front(); // Remove from the front
		Show(deque);

		std::cout << "Front: " << deque.front() << "\n"; // Access first element
		std::cout << "Back: " << deque.back() << "\n"; // Access last element

		std::cout << "Size: " << deque.size() << "\n"; // Get size
		std::cout << "Is empty: " << std::boolalpha << deque.empty() << "\n"; // Check if empty

		//shrink_to_fit - reduce capacity to fit size
		deque.resize(20); // Resize to 10 elements, new elements initialized to 0
		deque.shrink_to_fit(); // Reduce capacity to fit size
		Show(deque);

		deque.clear(); // Clear all elements
		Show(deque);

		// Insert elements
		deque.insert(deque.begin(), 100); // Insert at the beginning
		deque.insert(deque.end(), 200); // Insert at the end
		Show(deque);

		// Erase elements
		deque.erase(deque.begin()); // Erase first element
		Show(deque);

		// Emplace elements
		deque.emplace(deque.begin(), 300); // Emplace at the beginning
		Show(deque);

		// Emplace back
		deque.emplace_back(400); // Emplace at the end
		Show(deque);

		// Emplace front
		deque.emplace_front(500); // Emplace at the front
		Show(deque);

		// Swap deques
		std::deque<int> deque2{ 10, 20, 30 };
		std::cout << "Before swap:\n";
		Show(deque);
		Show(deque2);
		deque.swap(deque2); // Swap contents
		std::cout << "After swap:\n";
		Show(deque);
		Show(deque2);
	}
	// Global reloading 
	{
// Глобальне перевантаження операторів і функцій:
		std::cout << "--- Global operators & Functions ---\n";

// 1. operator== - повертає true, якщо 2 контейнери мають однаковий розмір і однакові значення.
		{
			std::deque<int> deque1{ 1, 2, 3 };
			std::deque<int> deque2{ 1, 2, 3 };
			std::deque<int> deque3{ 1, 2, 3, 4 };
			std::deque<int> deque4{ 1, 2, 5 };

			if (deque1 == deque2) // true
			{
				std::cout << "deque1 == deque2\n";
			}

			if (deque1 == deque3) // false
			{
				std::cout << "deque1 == deque3\n";
			}

			if (deque1 == deque4) // false
			{
				std::cout << "deque1 == deque4\n";
			}
		}

	}
}