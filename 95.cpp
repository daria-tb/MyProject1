#include <iostream>
//константні методи це методи які не міняють полів класу 
//методи які не міняють полів константами
class Rectangle
{
private:
    int height; //без ініц
    int width;

public:
    Rectangle() : height(10), width(10) {}
    void SetHeight(int newHeight) //змінює полів
    {
        if (newHeight > 0)
        {
            height = newHeight;
        }
    }
    void SetWidth(int newWidth) //змінює полів
    {
        if (newWidth > 0)
        {
            width = newWidth;
        }
    }
    int GetHeight()const//не змінює полів
    { 
        return height; 
    }
    int GetWidth()const//не змінює полів
    { 
        return width; 
    }
};

void Show (Rectangle& rectangle)
{
    std::cout << "Height = " << rectangle.GetHeight() << std::endl;
    std::cout << "Width = " << rectangle.GetWidth() << "\n\n";
};

int main()
{
    Rectangle one;

    Show(one);

    one.SetHeight(20);
    one.SetWidth(30);

    Show(one);

    return 0;
}