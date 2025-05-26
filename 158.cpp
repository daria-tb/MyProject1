#include <iostream>
#include <vector>
#include  <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>

int main()
{
	//  Конструктори
	//	1. queue()						конструктор за замовчуванням.
	//	2. queue(const Alloc & alloc)	конструктор за замовчуванням з указанням алокатора.

	//	3. queue(const std::queue<T>&other)							конструктор копії.
	//	4. queue(const std::deque<T>&other)							конструктор копії deque.
	//	5. queue(const std::queue<T>&other, const Alloc & alloc)	конструктор копії з указанням алокатора.
	//	6. queue(const std::deque<T>&other, const Alloc & alloc)	конструктор копії deque з указанням алокатора.

	//	7. queue(std::queue<T> && other)						конструктор переміщення.
	//	8. queue(std::deque<T> && other)						конструктор переміщення deque.
	//	9. queue(std::queue<T> && other, const Alloc & alloc)	конструктор переміщення з указанням алокатора.
	//	10. queue(std::deque<T> && other, const Alloc & alloc)	конструктор переміщення deque з указанням алокатор

	// Деструктор
	// Опис : оскільки std::queue містить лише одне поле std::queue викликає деструктор класу std::deque.контейнер std::deque, τо деструктор класу

	//Методи
	//	1. bool empty() const							- повертає true, якщо об'єкт queue пустий, і false, якщо має елементи. 
	//	2. void push(const T & value)					- копіює значення в кінець черги.
	//	   void push(T && value)						- переміщає значення в кінець черги.
	//	3. decltype(auto) emplace(Args&&...)			- конструює новий елемент в кінці черги.
	//	4. T & front()									- повертає посилання на перший елемент черги.
	//	   const T & front() const						- повертає посилання на перший елемент черги.
	//	5. T & back()									- повертає посилання на останній елемент черги.
	//	   const T & back() const						- повертає посилання на останній елемент черги.
	//	6. void pop()									- видаляє останній елемент з черги(викликає деструктор).
	//	7. size t size() const							- повертає розмір черги.
	//	8. void swap(const std::queue<T>&other)			- міняє вміст двох черг.
	//	9. const std::deque<T>&_Get_Container() const	- повератає посилання на внутрішній контейнер.
	//	10. void operator=(const std::queue<T>&other)	- переписує вміст черги, копіюючи значення нової черги.
	//	    void operator=(std::queue<T> && other)		- переписує вміст черги, переміщаючи значення нової черги

	// Функції 
	//  1. bool operator==[const std::queue<T>&si, const std::queue<T>&21 порівнює 2 стеки(чи рівні їх елементи).
	//	2. bool operator>(const std::queue<T>&51, const std::queue < T>6 s2 - (видалений в С++28).
	//	3. bool operator>=(const std::queue<T>&s1, const std::queue<T>&2)   - (видалений в С++20).
	//	4. bool operator<(const std::queue<T>&s1, const std::queue<T>&s2)   - (видалений в С++20).
	//	5. bool operator<=(const std::queue<T>&s1, const std::queue<T>&s2)  - (видалений в С++28).
	//	6. bool operator!=(const std::queue<T>&s1, const std::queue<T>&s2)  - (видалений в C++28).
	//	7. std::compare_three_way_result_t < Container operator<=>(const std::queue<T>&s1, const std::stack<T>&s2)
	//	8. std::swap(std::queue<T>&s1, std::queue<T>&s2) міняє вміст двох стеків.

	// Приклад використання
	std::queue<int> queue;
	for (int number = 0; number < 5; number++)
	{
		queue.push(number);
	}
	while (!queue.empty())
	{
		int value = queue.front();
		queue.pop();
		std::cout << value << " ";
	}
	std::cout << std::endl;
	if (queue.empty())
	{
		std::cout << "Queue is empty.\n";
	}
}