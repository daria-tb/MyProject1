/*
План уроку:
1. Про що буде урок?
2. Що таке функтор?
3. Що таке лямбда-функція?
   // Лямбда-ф-я — це анонімна функція, яка може бути визначена 
   прямо в місці її використання.
4. Де можуть використовуватись лямбда-функції?
5. Лямбда-функції без параметрів і повертаючого значення.
6. Параметри лямбда-функцій.
7. Повертаюче значення лямбда-функцій.
8. Об'єкт для зберігання лямбда-функції.
9. Узагальнені (шаблонні) лямбда-функції.
10. Список захоплення в лямбда-функції.
11. Ключове слово mutable в лямбда-функції.
*/

#include <iostream>
#include <cmath>
/* // Функтор — це клас з перевантаженим оператором (), який дозволяє викликати об'єкт як функцію.
class Sum
{
public:
    int operator()(int a, int b) const
    {
        return a + b;
    }
}; */


/* template<typename LambdaFunction>
void Test(LambdaFunction function)
{
	//int arr[] = { 1, 2, 3, 4, 5 };
	//function(arr, 5);
	int sum = function(10, 20);
	std::cout << "Sum: " << sum << std::endl;
} */

/* template <typename T, typename Func>
void ForAllElements(T* arr, size_t size, Func func)
{
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
	std::cout << std::endl;
} */

//Ñïèñîê çàõâàòó â ëÿìáäà-ôóíêö³¿
int globalVariable = 10;

class MyClass
{
public:
	static int staticClassField;
};

int MyClass::staticClassField = 20;

class LambdaRealization
{
private:
	int functionParameter;
public:
	LambdaRealization( int& functionParameter) 
		: functionParameter(functionParameter){}
	void operator()()
		{
		std::cout << "Function parameter = " << functionParameter << std::endl;
		functionParameter = 100;
		std::cout << "Function parameter = " << functionParameter << std::endl;
	}
};

void Func(int functionParameter)
{
	int localVariable = 234;	
	std::cout << "Func -> functionParameter = " << functionParameter << std::endl;
	auto lambda = [functionParameter]() mutable
		{
			std::cout << "Function parameter = " << functionParameter << std::endl;
			functionParameter = 100;
			std::cout << "Function parameter = " << functionParameter << std::endl;
		};
	lambda();
	std::cout << "Func -> functionParameter = " << functionParameter << std::endl;
}

/* class NewMyClass
{
private:
	int field1 = 10;
	double	field2 = 20.23456;
public:
	void Method()
	{
		auto show = [this]()
			{
				std::cout << "field1 = " << field1 << std::endl;
				std::cout << "field2 = " << field2 << std::endl;
			};
		show();
	}
}; */

int main()
{
 /*        // Функтор
    int num1 = 10, num2 = 20;
    int sum = Sum()(num1, num2); // використання функтора

    // Лямбда-функція
    // Синтаксис створення лямбда-функції:
    // [список_захоплення](параметри){ тіло функції }

    // Лямбда-функція без параметрів і повертаючого значення
    []() {
        std::cout << "Проста лямбда без параметрів\n";
    }();

    // Лямбда з параметрами, яка викликається одразу
    int result = [](int num1, int num2) { return num1 + num2; }(num1, num2);
    std::cout << "Sum = " << result << std::endl;

    // Приклади використання лямбда-функції з масивом
    int arr[] = { 1, 2, 3, 4, 5 };
    ForAllElements(arr, 5, [](int num) {
        std::cout << num << " ";
    }); // виведе: 1 2 3 4 5

    ForAllElements(arr, 5, [](int num) {
        std::cout << num * 2 << " ";
    }); // виведе: 2 4 6 8 10

    // Лямбда без параметрів і повертаючого значення, передається як аргумент
    Test([]() {
        std::cout << "Лямбда в Test без параметрів\n";
    });

    // Параметри лямбда-функції
    Test([](int arr[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << "\n";
        }
    });

    // Лямбда з типом повернення
    Test([](int a, int b) -> int {
        std::cout << "Hello from lambda" << std::endl;
        return a + b;
    });

    // Збереження лямбда-функції в об'єкті
    auto myLambda = []() {
        std::cout << "Збережена лямбда" << std::endl;
    };
    myLambda();

    // Робота з масивами різних типів
    const size_t SIZE1 = 3;
    int arr1[SIZE1] = { 1, 2, 3 };
    const size_t SIZE2 = 3;
    double arr2[SIZE2] = { 1.0, 2.0, 3.0 };
    const size_t SIZE3 = 3;
    char arr3[SIZE3] = { 'A', 'B', 'C' };

    auto showCube = [](int num) { std::cout << std::pow(num, 3) << " "; };
    auto showSqrt = [](int num) { std::cout << std::sqrt(num) << " "; };
    auto show = [](auto element) { std::cout << element << " "; };

    ForAllElements(arr1, SIZE1, showCube);
    std::cout << std::endl;
    ForAllElements(arr2, SIZE2, showCube);
    std::cout << std::endl;
    ForAllElements(arr1, SIZE1, showSqrt);
    std::cout << std::endl;
    ForAllElements(arr2, SIZE2, showSqrt);
    std::cout << std::endl;
    ForAllElements(arr1, SIZE1, show);
    std::cout << std::endl;
    ForAllElements(arr2, SIZE2, show);
    std::cout << std::endl;
    ForAllElements(arr3, SIZE3, show);
    std::cout << std::endl;

    //// Список захоплення в лямбда-функції
    int externalValue = 42;

    auto lambdaValue = [=]() { // захоплення всіх зовнішніх змінних за значенням
        std::cout << "externalValue = " << externalValue << std::endl;
    };
    auto lambdaReference = [&]() { // захоплення всіх зовнішніх змінних за посиланням
        std::cout << "externalValue (by ref) = " << externalValue << std::endl;
    };

    lambdaValue();
    lambdaReference();

    //// Виклик методу класу, який використовує лямбду з доступом до this
    NewMyClass myObject;
    myObject.Method();
 */


    return 0;
}