#include <iostream> 
#include <memory>   // для std::unique_ptr

// клас для демонстрації створення та знищення об'єкта
class MyClass
{
public:
	void Method()
	{
		std::cout << "MyClass::Method()" << std::endl;
	}

	MyClass()
	{
		std::cout << "Constructor MyClass" << std::endl;
	}

	~MyClass()
	{
		std::cout << "Destructor MyClass" << std::endl;
	}
};

// функціональний делетер
void MyDeleterF(int* ptr)
{
	std::cout << "MyDeleterF" << std::endl;
	delete ptr;
}

// об'єктний делетер
struct MyDeleterC
{
	void operator()(int* ptr)
	{
		std::cout << "MyDeleterC" << std::endl;
		delete ptr;
	}
};

// функція приймає const reference на unique_ptr
void Show(const std::unique_ptr<int>& ptr)
{
	std::cout << *ptr << std::endl;
}

// функція приймає unique_ptr по значенню (передає ownership)
void ShowAndDelete(std::unique_ptr<int> ptr)
{
	std::cout << *ptr << std::endl;
}

// створює динамічний масив і повертає raw-вказівник
int* CreateArray1()
{
	std::cout << "Enter size of array:";
	size_t size;
	std::cin >> size;
	return new int[size];
}

// створює динамічний масив і повертає unique_ptr
std::unique_ptr<int[]> CreateArray2()
{
	std::cout << "Enter size of array:";
	size_t size;
	std::cin >> size;
	std::unique_ptr<int[]> arr{ new int[size] };
	return arr;
}

int main()
{
#pragma region конструктори
	{
		std::unique_ptr<int> ptr1; // створення порожнього вказівника
		std::unique_ptr<int> ptr2 { nullptr }; // явно вказано nullptr
		std::unique_ptr<int> ptr3 { new int{5} }; // створення з ініціалізацією
		std::unique_ptr<int, void(*)(int*)> ptr4{ new int{ 5 }, MyDeleterF }; // з функціональним делетером
		std::unique_ptr<int, MyDeleterC> ptr5{ new int{ 5 }, MyDeleterC() }; // з об'єктним делетером
		std::unique_ptr<int> ptr7 { std::move(ptr2) }; // передача ownership через move
		std::unique_ptr<int>(); // тимчасовий об'єкт
	}
#pragma endregion

#pragma region перевантаження операторів
	{
		std::unique_ptr<MyClass> ptr{ new MyClass{} }; // створення об'єкта
		std::unique_ptr<MyClass> ptr2;
		ptr.operator->(); // виклик методу через ->
		ptr.operator*(); // розіменування
		ptr.operator bool(); // перевірка на null
		ptr.operator=(nullptr); // присвоєння nullptr
		ptr2.operator=(std::move(ptr)); // переміщення ownership
	}
#pragma endregion

#pragma region методи
	{
		std::unique_ptr<MyClass> ptr1{ new MyClass{} };
		std::unique_ptr<MyClass> ptr2;
		ptr1.get(); // отримаємо raw-вказівник
		ptr1.get()->Method(); // викликаємо метод через get()
		ptr1.get_deleter(); // отримуємо делетер
		ptr1.reset(); // звільняє ресурс
		ptr1.release(); // віддає ownership без звільнення пам'яті
		ptr1.swap(ptr2); // обмін ресурсами
	}
#pragma endregion

#pragma region масиви
	{
		std::unique_ptr<int[]> arr{ new int[5] { 1, 2, 3, 4, 5 } }; // створення масиву
		arr.get()[0] = 10; // доступ до елемента
		for (int i = 0; i < 5; ++i)
		{
			std::cout << arr.get()[i] << std::endl; // вивід елементів
		}
		arr.get_deleter(); // доступ до делетера
		arr.reset(); // очищення масиву
		arr.release(); // передача ownership
		arr.swap(arr); // обмін із собою (немає ефекту)
		arr.operator bool(); // перевірка на null
		arr.operator=(nullptr); // присвоєння nullptr
		arr.operator=(std::move(arr)); // move-присвоєння
		//arr.operator ; // доступ до елемента через оператор []
	}
#pragma endregion

#pragma region передача та повернення з функцій
	{
		std::unique_ptr<int> ptr1{ new int{5} };
		Show(ptr1); // передача по посиланню (без звільнення)
		ShowAndDelete(std::move(ptr1)); // передача з передачею ownership
		std::unique_ptr<int[]> ptr2{ CreateArray1() }; // створення з raw-вказівника
		std::unique_ptr<int[]> ptr2{ CreateArray2() }; // створення через функцію
	}
#pragma endregion

	return 0;
}
