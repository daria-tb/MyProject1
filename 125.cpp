/* 
std::shared_ptr это умный указатель, с разделяемым владением объектом через его указатель. Несколько указателей shared_ptr могут владеть одним и тем же объектом. Объект будет уничтожен и занятая им память будет освобождена в одном из следующих случаев:
когда последний shared_ptr, владеющий указателем на объект, будет уничтожен;
когда последнему shared_ptr, владеющему указателем на объект, будет присвоен другой указатель с помощью operator= или reset(). */
#include <iostream>
#include <memory>   // для std::shared_ptr

// клас для демонстрації shared_ptr з користувацьким типом
class Person
{
private:
	int age = 0;
	char name[30] = "NoName";

public:
	Person() = default;

	Person(int age, const char* name)
		: age(age)
	{
		//strcpy_s(this->name, name); // копіюємо ім'я
		std::cout << "Constructor called" << std::endl;
	}

	~Person()
	{
		std::cout << "Destructor called" << std::endl;
	}

	void SomeMethod()
	{
		std::cout << "SomeMethod called" << std::endl;
	}
};

// функціональний делетер
void DeleterF(int* p)
{
	std::cout << "Deleter called" << std::endl;
	delete p;
}

// об'єктний делетер
struct DeleterC
{
	void operator()(int* p)
	{
		std::cout << "Deleter called" << std::endl;
		delete p;
	}
};

// функція повертає shared_ptr з делетером
std::shared_ptr<int> CreateInteger(int value)
{
	return std::shared_ptr<int>(new int(value), DeleterF);
}

int main()
{
#pragma region конструктори
	{
		std::shared_ptr<int> ptr1{ nullptr }; // порожній вказівник
		std::shared_ptr<int> ptr2{ new int{ 10 } }; // звичайне створення
		int* p = new int{ 10 };
		std::shared_ptr<int> ptr3{ p }; // з raw-вказівника
		std::shared_ptr<int> ptr4{ p, DeleterF }; // з функціональним делетером
		std::shared_ptr<int> ptr5{ p, DeleterC() }; // з об'єктним делетером
		std::shared_ptr<int> ptr6{ ptr5 }; // копіювання shared_ptr (підрахунок посилань)
		std::shared_ptr<int> ptr7{ CreateInteger(5) }; // створення через функцію
		std::shared_ptr<Person> ptr8{ new Person(20, "John") }; // з користувацьким типом
	}
#pragma endregion

#pragma region масиви
	{
		//std::shared_ptr<Person[]> ptr1{ new Person[10] }; // робота з масивом
	}
#pragma endregion

#pragma region псевдонім element_type
	{
		std::shared_ptr<int> ptr1(new int(1)); // стандартне створення
		std::shared_ptr<int>::element_type variable; // псевдонім типу
	}
#pragma endregion

#pragma region перевантажені оператори
	{
		std::shared_ptr<Person> ptr1(new Person()); // створення об'єкта
		ptr1.operator bool(); // перевірка на null
		ptr1.operator*(); // розіменування
		ptr1.operator->(); // доступ до членів класу
		ptr1->SomeMethod(); // виклик методу
		ptr1.operator= (nullptr); // присвоєння nullptr
		//std::shared_ptr<Person[]> ptr2(new Person[3]); // масив об'єктів
		//ptr2.operator ; // доступ до елементу
		//ptr2[0] = Person(10, "John"); // присвоєння об'єкта
	}
#pragma endregion

#pragma region методи
	{
		std::shared_ptr<int> ptr1(new int(10));
		std::shared_ptr<int> ptr2(new int(20));

		std::cout << "*ptr1 = " << *ptr1 << std::endl;
		std::cout << "*ptr2 = " << *ptr2 << std::endl;

		ptr1.swap(ptr2); // обмін вмістом
		std::cout << "*ptr1 = " << *ptr1 << std::endl;
		std::cout << "*ptr2 = " << *ptr2 << std::endl;

		std::cout << "&ptr1 = " << &ptr1 << std::endl;
		std::cout << "&ptr1 = " << ptr1.get() << std::endl; // отримаємо raw-вказівник

		std::shared_ptr<Person> ptr1(new Person(20, "John"));
		ptr1.reset(); // звільнення ресурсу
		ptr1.use_count(); // кількість посилань
	}
	{
		std::shared_ptr<int> ptr1(new int(10));
		std::shared_ptr<int> ptr2(ptr1);
		if (ptr1.owner_before(ptr2)) // порівняння ownership
			std::cout << "Ok";
	}
#pragma endregion

#pragma region std::make_unique/std::make_shared
	{
		std::unique_ptr<int> ptr1{ std::make_unique<int>(10) }; // створення з make_unique
		std::unique_ptr<Person> ptr1_{ std::make_unique<Person>(10, "Jane") }; // з класом
		std::unique_ptr<int[]> arr{ std::make_unique<int[]>(10) }; // масив

		std::shared_ptr<int> ptr2(new int{ 20 }); // звичайне створення
		std::shared_ptr<Person> ptr2_{ std::make_shared<Person>(10, "Jane") }; // створення з make_shared
	}
#pragma endregion

	return 0;
}
