#include <iostream>
#include <list>

//stack by list
/* Використовує стандартний контейнер std::list (двозв’язний список).
Кожен виклик Push() додає елемент у кінець списку (push_back).
Pop() — видаляє останній елемент (pop_back).
Top() — повертає останній елемент (back()).
Пам’ять виділяється динамічно, але керується автоматично std::list. */
/* template<typename T>
class Stack : private std::list<T>
{
public:
	void Push(const T& value)
	{
		std::list<T>::push_back(value);
	}

	void Pop()
	{
		std::list<T>::pop_back();
	}

	T& Top()
	{
		return std::list<T>::back();
	}

	bool IsEmpty() const
	{
		return  std::list<T>::empty();
	}

	size_t Size() const
	{
		return  std::list<T>::size();
	}
};
 */

//stack on heap
/* Реалізація вручну за допомогою динамічного масиву (new[]).
При кожному додаванні (Push) або видаленні (Pop) — створюється новий масив.
Копіювання (operator= і коп. конструктор) реалізовано вручну.
Управління пам’яттю: треба видаляти new[] у деструкторі. */
class Stack
{
	int* stack=nullptr;
	int top = -1;
public:
	Stack() = default;
	Stack(const Stack& other)
	{
		if (other.stack == nullptr)
		{
			stack = nullptr;
			top = -1;
		}
		else
		{
			stack = new int[other.top + 1];
			for (int i = 0; i <= other.top; ++i)
			{
				stack[i] = other.stack[i];
			}
			top = other.top;
		}
	}
	
	~Stack()
	{
		delete[] stack;
		stack = nullptr;
	}
	
	Stack& operator=(const Stack& other)
	{
		if (this != &other)
		{
			delete[] stack;
			if (other.stack == nullptr)
			{
				stack = nullptr;
				top = -1;
			}
			else
			{
				stack = new int[other.top + 1];
				for (int i = 0; i <= other.top; ++i)
				{
					stack[i] = other.stack[i];
				}
				top = other.top;
			}
		}
		return *this;
	}
	void Push(const int& value)
	{
		if (IsEmpty())
		{
			stack = new int[1];
			stack[++top] = value;
			return;
		}
		else
		{
			int* newStack = new int[top + 2];
			for (int i = 0; i <= top; ++i)
			{
				newStack[i] = stack[i];
			}
			delete[] stack;
			stack = newStack;
			stack[++top] = value;
		}
	}
	
	void Pop()
	{
		if (!IsEmpty())
		{
			if (Size() == 1)
			{
				delete[] stack;
				stack = nullptr;
				top = -1;
			}
			else
			{
				int* newStack = new int[top];
				for (int i = 0; i < top; ++i)
				{
					newStack[i] = stack[i];
				}
				delete[] stack;
				stack = newStack;
				--top;
			}
		}
	}
	
	int& Top()
	{
		return stack[top];
	}
	
	bool IsEmpty() const
	{
		return top == -1;
	}
	
	size_t Size() const
	{
		return top + 1;
	}
}; 

//stack on stack
/* Використовує статичний масив фіксованого розміру, який зберігається на стеку.
Найефективніша реалізація за часом виконання.
Push просто записує значення у масив, без алокації пам’яті. */
/* template<size_t MAX_SIZE>
class Stack
{
	int stack[MAX_SIZE] = {};
	int top = -1;
public:
	bool Push(const int& value)
	{
		if (!IsFull())
		{
			stack[++top] = value;
			return true;
		}
		return false;
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			--top;
		}
	}
	int& Top()
	{
		return stack[top];
	}
	bool IsFull() const
	{
		return top == MAX_SIZE - 1;
	}
	bool IsEmpty() const
	{
		return top == -1;
	}
	size_t MaxSize() const
	{
		return MAX_SIZE;
	}
	size_t Size() const
	{
		return top + 1;
	}
}; 
 */

class Person
{
private:
	std::string name;
	int age;
public:
	Person() = default;
	Person(const std::string& name, int age) 
		: name(name), age(age) 
	{}

	std::string Name() const
	{
		return name;
	}

	int Age() const
	{
		return age;
	}
};

int main()
{
	//Stack on stack memory
/* 	Stack<10> myStack;
	std::cout << (myStack.IsEmpty() ? "Stack is empty" : "Stack is not empty") << std::endl;
	std::cout << "Max size: " << myStack.MaxSize() << std::endl;

	for (int i = 0; i < myStack.MaxSize()-5; ++i)
	{
		if (myStack.Push(i))
		{
			std::cout << i << " was pushed" << std::endl;
		}
		else
		{
			std::cout << i << " was not pushed" << std::endl;
		}
	}

	std::cout << "Stack size: " << myStack.Size() << std::endl;
	
	while (!myStack.IsEmpty())
	{
		std::cout << myStack.Top() << " ";
		myStack.Pop();
	} */

	//Stack on heap memory
	Stack myStack;
	std::cout << "Size Stack1 = " << myStack.Size() << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		myStack.Push(i);
		std::cout << "Size Stack1 = " << myStack.Size() << std::endl; 
	}

	Stack myStack2(myStack);
	std::cout << "Size Stack2 = " << myStack2.Size() << std::endl;

	Stack myStack3;
	myStack3 = myStack;
	std::cout << "Size Stack3 = " << myStack3.Size() << std::endl;
	
	//Stack by list
	/* Stack<double> myStack;
	for (int i = 0; i < 10; ++i)
	{
		myStack.Push(i);
	}

	while (!myStack.IsEmpty())
	{
		std::cout << myStack.Top() << " ";
		myStack.Pop();
	}

	Stack<Person> myStack2;
	myStack2.Push(Person("John", 25));
	myStack2.Push(Person("Jane", 30));
	myStack2.Push(Person("Alice", 28));
	while (!myStack2.IsEmpty())
	{
		std::cout << myStack2.Top().Name() << " " <<
			myStack2.Top().Age() << std::endl;
		myStack2.Pop();
	}*/	
    return 0;
}