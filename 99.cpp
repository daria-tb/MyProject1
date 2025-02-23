#include <iostream>
#include <cstdlib>
//конструктор копії
class Color
{
private:
    using byte = unsigned char;

    byte red = 10;
    byte green = 0;
    byte blue = 0;

public:
    Color(byte red = 0, byte green = 0, byte blue = 0)
        : red(red), green (green), blue (blue)
    { 
        std::cout << "constr\n"; 
    }
    ~Color()
    {
        std::cout << "destr\n"; 
    }

    void SetR(byte red) { this->red = red; }
    void SetG(byte green) { this->green = green; }
    void SetB(byte blue) { this->blue = blue; }

    byte GetR() const { return red; }
    byte GetG() const { return green; }
    byte GetB() const { return blue; }

    void ShowRGB() const
    {
        std::cout << "[R = " << static_cast<int>(red);
        std::cout << " G = " << static_cast<int>(green);
        std::cout << " B = " << static_cast<int>(blue) << "]";
    }
};

class DynamicIntArray
{
private:
    int* arr = nullptr;
    size_t size = 0;
public:
    DynamicIntArray(size_t size)
    {
    if (size != 0)
    {
        std::cout << " DynamicIntArray const\n";
        this->size = size;
        arr = new int[size];

        for (size_t i = 0; i < size; i++)
            arr[i] = std::rand() % 100;
    }
    }

    DynamicIntArray(const DynamicIntArray& other)
        : size(other.size)
    {
    if (size != 0)
    {
        std::cout << " DynamicIntArray  copy const\n";

        arr = new int[size];

        for (size_t i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }   
    }


    ~DynamicIntArray()
    {
        std::cout << " DynamicIntArray dest\n";
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

    size_t GetSize() const { return size; }

    int GetElement(size_t index) const
    {
    if (index >= size)
    {
        std::cout << "Incorrect index.\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[index];
    }

    void SetElement(size_t index, int value)
    {
    if (index >= size)
    {
        std::cout << "Incorrect index.\n";
        std::exit(EXIT_FAILURE);
    }
    arr[index] = value;
    }
};

void Show(Color color);
void Show(DynamicIntArray dynamicArray);
void Initialize(DynamicIntArray dynamicArray);

DynamicIntArray CreateArr(size_t size);
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    /* Color black;
    Color white{ 255, 255, 255 };

    Show(black);
    Show(white); */

    DynamicIntArray dynamicArray(3);

    Show(dynamicArray);
    Initialize(dynamicArray);
    Show(dynamicArray);

    return 0;
}

void Show(Color color)
{
    std::cout << "Color RGB: ";
    color.ShowRGB();
    std::cout << std::endl;
}

void Show(DynamicIntArray dynamicArray)
{
    for (size_t i = 0; i < dynamicArray.GetSize(); i++)
        std::cout << dynamicArray.GetElement(i) << " ";
    std::cout << std::endl;
}

void Initialize(DynamicIntArray dynamicArray)
{
    for (size_t i = 0; i < dynamicArray.GetSize(); i++)
        dynamicArray.SetElement(i, std::rand() % 100);
}

DynamicIntArray CreateArr(size_t size);