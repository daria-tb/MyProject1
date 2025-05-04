// проблеми обробки помилок
// виключення — механізм відокремлення обробки помилок від основного коду
// ключові слова: throw — для генерації помилок, try — для пошуку виключень, catch — для обробки
// якщо не зловити виключення, програма може завершитися з помилкою
// кілька блоків catch дозволяють обробити різні типи виключень
// блок try в блоці try — можливий
// повторне кидання виключення в catch дозволяє передати помилку іншому catch
// catch-all зловить будь-яке виключення, захищає від непередбачених помилок
// стандартна ієрархія виключень є в бібліотеці cppreference
// наслідування виключень: catch працює з похідними класами
// при throw відбувається копіювання об'єкта
// розкрутка стека — знищення локальних змінних при виключеннях
// специфікація throw(...) для вказівки можливих виключень
// noexcept — вказівка, що функція не кидає виключень
// не можна кидати виключення в конструкторах та деструкторах
// кидання виключень між new і delete — заборонено
// незручності: необхідність обробляти виключення, сповільнення програми, розкрутка стека

#include <iostream>

struct MeException
{
	int errorCode;
	char errorMassage[50];
};

void InterestingFunction()
{
	int randomNumber = std::rand() % 3;

	try
	{
		if (randomNumber == 0)
		{
			throw MeException{- 1, "Incorrect random number"};
		}
		else if(randomNumber==1)
		{
			throw 's';
		}
		else if (randomNumber == 3)
		{
			throw 2.5;
		}
	}
	catch (const MeException exc)
	{
		std::cout << "Function name: "<<__func__<<std::endl;
		std::cout << "Error code = " << exc.errorCode<<"\n\n";

		throw;
	}
	
}

void Func1() throw() {} //функція не кидає виключення
void Func2() throw(...) {} //функція кидає виключення будь-якого типу
void Func3() throw(MeException, std::exception, std::bad_alloc) {} //функція кидає виключення MeException, std::exception, std::bad_alloc

void Func4() noexcept {} //функція не кидає виключення
void Func5() noexcept(false) {} //функція кидає виключення
void Func6() noexcept(true) {} //функція не кидає виключення

int main() 
{
	std::exception object1;
	std::exception object2("My own exception");
	std::exception object3(object2);
	std::exception object4;
	object4 = object2;

	/*try
	{
		InterestingFunction();
	}
	
	catch (int errorInteger)
	{
		std::cout << errorInteger;
	}
	catch (char errorCharacter)
	{
		std::cout << errorCharacter;
	}
	catch (double errorDouble)
	{
		std::cout << errorDouble;
	}
	catch (...)
	{
		std::cout << "Error.\n";
	}*/

	if (noexcept(Func4()))
	{
		std::cout << "Func4() не кидає виключення\n";
	}
	else
	{
		std::cout << "Func4() кидає виключення\n";
	}



	return 0;
}
 