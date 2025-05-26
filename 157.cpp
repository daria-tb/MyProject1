#include <iostream>
#include <stack>

int main()
{
	// Конструктори:
	// 1. stack()                         – конструктор за замовчуванням.
	// 2. stack(const Alloc & alloc)     – конструктор за замовчуванням з вказанням алокатора.
	// 3. stack(const std::stack<T>& other)                     – копіюючий конструктор.
	// 4. stack(const std::deque<T>& other)                     – копіюючий конструктор з deque.
	// 5. stack(const std::stack<T>& other, const Alloc& alloc)– копіюючий з алокатором.
	// 6. stack(const std::deque<T>& other, const Alloc& alloc)– копіюючий deque з алокатором.
	// 7. stack(std::stack<T>&& other)                         – move-конструктор.
	// 8. stack(std::deque<T>&& other)                         – move-конструктор з deque.
	// 9. stack(std::stack<T>&& other, const Alloc& alloc)     – move-конструктор з алокатором.
	// 10. stack(std::deque<T>&& other, const Alloc& alloc)    – move-конструктор deque з алокатором.

	// Деструктор:
	// stack містить лише один контейнер std::deque, тому деструктор stack викликає деструктор deque.

	// Методи:
	// 1. bool empty() const – повертає true, якщо стек порожній.
	// 2. void push(const T& value) – копіює значення у кінець стека.
	//    void push(T&& value) – переміщує значення у кінець стека.
	// 3. decltype(auto) emplace(Args&&...) – створює новий елемент у кінці стека.
	// 4. T& top() / const T& top() const – повертає посилання на останній (верхній) елемент.
	// 5. void pop() – видаляє останній елемент із стека.
	// 6. size_t size() const – повертає розмір стека.
	// 7. void swap(const std::stack<T>& other) – обмінює вміст стеків.
	// 8. const std::deque<T>& _Get_container() const – повертає посилання на внутрішній контейнер (нестандартний метод, залежить від реалізації).
	// 9. Оператори присвоєння (копіювання та переміщення)

	// Функції:
	// 1. operator== – порівнює два стеки на рівність.
	// 2-6. Інші оператори порівняння (частина з них видалені у C++20/23).
	// 7. <=> оператор трьохзначного порівняння (C++20).
	// 8. std::swap – міняє місцями два стеки.

	// Приклад використання:
	std::stack<int> numbers;
	for (int number = 0; number < 5; number++)
	{
		numbers.push(number);
	}

	size_t initialSize = numbers.size();

	for (size_t i = 0; i < initialSize; i++)
	{
		int value = numbers.top();
		numbers.pop();
		std::cout << value << " ";
	}
	std::cout << std::endl;

	if (numbers.empty())
	{
		std::cout << "Stack is empty.\n";
	}

	return 0;
}
