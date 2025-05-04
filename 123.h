#pragma once // гарантує, що заголовочний файл буде включено лише один раз
#define _NODISCARD [[nodiscard]] // макрос для атрибута, що забороняє ігнорування результату

// допоміжна структура для передачі ownership
template <class T>
struct auto_ptr_ref
{
	T* reference;
	explicit auto_ptr_ref(T* other) : reference(other) {}
};

// реалізація шаблону smart pointer auto_ptr
template <class T>
class auto_ptr
{
private:
	// вказівник на об'єкт
	T* pointer;

public:
	// псевдонім типу
	using element_type = T;

	// конструктор з вказівника або за замовчуванням
	explicit auto_ptr(T* ptr = nullptr) noexcept : pointer(ptr) {}

	// конструктор копіювання з передачею ownership
	auto_ptr(auto_ptr& other) noexcept : pointer(other.release()) {}

	// конструктор з auto_ptr_ref
	auto_ptr(auto_ptr_ref<T> other) noexcept
	{
		T* ptr = other.reference();
		other.reference() = nullptr;
		pointer = ptr;
	}

	// шаблонний конструктор з іншого типу auto_ptr
	template <class _Other>
	auto_ptr(auto_ptr<_Other>& other) noexcept : pointer(other.release()) {}

	// деструктор, звільняє ресурс
	~auto_ptr() noexcept { delete pointer; }

	// повертає raw-вказівник
	_NODISCARD T* get() const noexcept { return pointer; }

	// передає ownership і повертає вказівник
	T* release() noexcept
	{
		T* temp = pointer;
		pointer = nullptr;
		return temp;
	}

	// замінює ресурс новим
	void reset(T* ptr = nullptr) noexcept
	{
		if (pointer != ptr)
		{
			delete pointer;
		}
		pointer = ptr;
	}

	// приведення до auto_ptr з іншим типом
	template <class OtherT>
	operator auto_ptr<OtherT>() noexcept { return auto_ptr<OtherT>(*this); }

	// приведення до auto_ptr_ref з іншим типом
	template <class OtherT>
	operator auto_ptr_ref<OtherT>() noexcept
	{
		OtherT* temp = pointer;
		auto_ptr_ref<OtherT> result(temp);
		pointer = nullptr;
		return result;
	}

	// оператор присвоєння з іншого auto_ptr
	template <class OtherT>
	auto_ptr& operator=(auto_ptr<OtherT>& other) noexcept
	{
		reset(other.release());
		return *this;
	}

	// оператор присвоєння з auto_ptr того ж типу
	auto_ptr& operator=(auto_ptr& other) noexcept
	{
		reset(other.release());
		return *this;
	}

	// оператор присвоєння з auto_ptr_ref
	auto_ptr& operator=(auto_ptr_ref<T> other) noexcept
	{
		T* ptr = other.reference;
		other.reference = 0;
		reset(ptr);
		return *this;
	}

	// оператор розіменування
	_NODISCARD T& operator*() const noexcept
	{
#if _ITERATOR_DEBUG_LEVEL == 2
		_STL_VERIFY(pointer, "auto_ptr not dereferenceable");
#endif
		return *get();
	}

	// оператор доступу до члена
	_NODISCARD T* operator->() const noexcept
	{
#if _ITERATOR_DEBUG_LEVEL == 2
		_STL_VERIFY(pointer, "auto_ptr not dereferenceable");
#endif
		return get();
	}
};

// спеціалізація шаблону для типу void
template <>
class auto_ptr<void>
{
public:
	using element_type = void;
};

// спеціалізація шаблону для масивів
template <class T[]>
class auto_ptr
{
};
