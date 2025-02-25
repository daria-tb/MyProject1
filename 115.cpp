#include <iostream>
//Перезавантаження індексатора
class DArray 
{
private:
    size_t size;
    int* arr;

public:
    DArray(size_t size) : size(size), arr(new int[size] {}) {}

    DArray(const DArray& other) : size(other.size), arr(new int[other.size]) 
    {
        for (size_t i = 0; i < size; i++) 
        {
            arr[i] = other.arr[i];
        }
    }

    //rонструктор переміщення
    DArray(DArray&& other) noexcept : size(other.size), arr(other.arr) 
    {
        other.arr = nullptr;
        other.size = 0;
    }

    //oператор присвоєння копіювання
    DArray& operator=(const DArray& other) 
    {
        if (this != &other) 
        {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (size_t i = 0; i < size; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Оператор присвоєння переміщення
    DArray& operator=(DArray&& other) noexcept 
    {
        if (this != &other) 
        {
            delete[] arr;
            size = other.size;
            arr = other.arr;
            other.arr = nullptr;
            other.size = 0;
        }
        return *this;
    }

     // Перевантаження оператора []
    int& operator[](size_t index) 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Індекс виходить за межі масиву!");
        }
        return arr[index];
    }

int& operator()(const char* index) 
{
        if (arr == nullptr) 
        {
            std::cerr << "arr == nullptr in " << __func__ << " method.\n";
            std::exit(1);
        }

        if (std::strcmp(index, "zero") == 0) 
        {
            return arr[0];
        } 
        else if (std::strcmp(index, "first") == 0) 
        {
            return arr[1];
        } 
        else if (std::strcmp(index, "second") == 0) 
        {
            return arr[2];
        } 
        else if (std::strcmp(index, "third") == 0) 
        {
            return arr[3];
        } 
        else 
        {
            std::cerr << "Incorrect index in '" << __func__ << "' method.\n";
            std::exit(1);
        }
    }

    const int& operator[](size_t index) const 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Індекс виходить за межі масиву!");
        }
        return arr[index];
    }

    // Отримання розміру масиву
    size_t GetSize() const 
    {
        return size;
    }

    // Деструктор
    ~DArray() 
    {
        delete[] arr;
    }
};

int main() 
{
    DArray arr(5);

    for (size_t i = 0; i < arr.GetSize(); i++) 
    {
        arr[i] = static_cast<int>(i) * 10;
    }

    for (size_t i = 0; i < arr.GetSize(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //pміна елемента масиву через індексатор
    arr[1] = 11671;
    arr[4] = 11;
    arr("first");

    for (size_t i = 0; i < arr.GetSize(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << arr("first") << std::endl;

    return 0;
}