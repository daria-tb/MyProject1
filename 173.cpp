#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
/*
Методи unordered-контейнерів (unordered_map, unordered_multimap, unordered_set, unordered_multiset) в C++14 однакові:
----------------------------------------------------------------------------
begin           — ітератор на початок
cbegin          — константний ітератор на початок
end             — ітератор на кінець
cend            — константний ітератор на кінець
clear           — очищення контейнера
empty           — перевірка на порожнечу
count           — кількість елементів з певним ключем
insert          — вставка елементів
emplace         — вставка з конструюванням на місці
emplace_hint    — вставка з підказкою позиції
upper_bound     — ітератор на перший елемент з ключем більшим за вказаний
lower_bound     — ітератор на перший елемент з ключем не меншим за вказаний
equal_range     — діапазон елементів з однаковим ключем
erase           — видалення елементів
find            — пошук елемента
max_size        — максимальна кількість елементів
reserve         — резервування пам’яті
size            — поточна кількість елементів
get_allocator   — доступ до аллокатора
key_eq          — порівняння ключів
swap            — обмін вмістом контейнерів
operator=       — оператор присвоєння
----------------------------------------------------------------------------
unordered_map додатково має:
at              — доступ до значення за ключем з перевіркою
operator[]      — доступ до значення за ключем (з додаванням за замовчуванням)
----------------------------------------------------------------------------
Функції хеш-таблиці:
bucket(key)            — повертає індекс бакету, де зберігається ключ
bucket_count()         — кількість бакетів (сегментів) у таблиці
bucket_size(n)         — кількість елементів у бакеті з індексом n
hash_function()        — хеш-функція, що використовується контейнером
load_factor()          — середня кількість елементів на бакет
max_bucket_count()     — максимально можлива кількість бакетів
max_load_factor()      — максимальний коефіцієнт заповнення
rehash(n)              — перепакування таблиці на n бакетів або більше

Примітка: hash — це структура, яка є функтором (об'єктом, що виконує функцію).
*/

class Person
{
private:
	std::string name;
	int age;
public:
	Person(const std::string& name, int age)
		: name(name), age(age) {
	}

	std::string GetName() const { return name; }
	int GetAge()const { return age; }

	bool operator==(const Person& other) const
	{
		return name == other.name && age == other.age;
	}
};

namespace std
{
	template<>
	struct  hash<Person>
	{
		size_t operator()(const Person& p) const
		{
			return hash<string>()(p.GetName()) ^ hash<int>()(p.GetAge());
		}
	};
}

void HashTest()
{
	std::unordered_map<Person, int> ageMap;
	Person demian("Demian Blogan", 26);
	Person clementina("Clementina Wolder", 20);
	ageMap[demian] = 30;
	ageMap[clementina] = 25;
}

int main()
{

}