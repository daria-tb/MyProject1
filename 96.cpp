#include <iostream>
//конструктор це метод який автоматично викликається при створенні обʼєкту 
/*
Синтаксис створення конструктору:

1. Прототип:
Ім'я Класу (Список Параметрів);

2. Визначення:
Ім'я Класу::Ім'я_Класу (Список_Параметрів)
{код}
*/
class Window
{
private:
    int x;
    int y;
    int height;
    int width;

public:
    // Конструктор з параметрами
    Window(int originX, int originY, int originHeight, int originWidth)
    {
        SetX(originX);
        SetY(originY);
        SetHeight(originHeight);
        SetWidth(originWidth);
    }

        Window() : x(0), y(0), height(10), width(10) { } // Ініціалізація полів за замовчуванням через список ініціалізації конструктора


    // Конструктор за замовчуванням
    //Window() { } // Ініціалізація полів за замовчуванням

    // Гетери
    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetHeight() const { return height; }
    int GetWidth() const { return width; }

    // Сетери
    void SetX(int newX)
    {
        if (newX > 0)
        {
            x = newX;
        }
    }

    void SetY(int newY)
    {
        if (newY > 0)
        {
            y = newY;
        }
    }

    void SetHeight(int newHeight)
    {
        if (newHeight > 0)
        {
            height = newHeight;
        }
    }

    void SetWidth(int newWidth)
    {
        if (newWidth > 0)
        {
            width = newWidth;
        }
    }

    // Виведення вікна на екран
    void Show() const
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)  // Змінили змінну з i на j
            {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
    }
};
//-------
class Rectangleee 
{
    int width, height;

public:
    //конструктор зі списком ініціалізації
    Rectangleee(int w, int h) : width(w), height(h) {}

    //метод для виведення прямокутника
    void draw() const 
    {
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++) 
            {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{
    // Створення об'єктів
    Window window(3, 5, 10, 10);
    Window window1;    // Використовує конструктор за замовчуванням
    Window window2(3, 5, 10, 10);
    Window window3;    // Використовує конструктор за замовчуванням

    // Виведення результатів
    window.Show();
    std::cout << std::endl;
    window1.Show();
    std::cout << std::endl;
    window2.Show();
    std::cout << std::endl;
    window3.Show();
//---------
    int w, h;
    std::cout << "enter width: ";
    std::cin >> w;
    std::cout << "enter height: ";
    std::cin >> h;

    Rectangleee rect(w, h);
    rect.draw();
//---------
/* // Виклик конструктора за замовчуванням (на стеку):
Window window1;
Window window2{};

// Виклик конструктора з параметрами (на стеку):
Window window7(1, 2, 3, 4);
Window window8{1, 2, 3, 4};

// Виклик конструктора за замовчуванням (на купі):
Window* window3 = new Window;
Window* window4 = new Window();

// Виклик конструктора з параметрами (на купі):
Window* window9 = new Window(1, 2, 3, 4);
//Window* window10 = new Window{1, 2, 3, 4};  //такий синтаксис некоректний

// Виклик конструктора за замовчуванням (у статичній пам’яті):
Window window5;
Window window6{};

// Виклик конструктора з параметрами (у статичній пам’яті):
Window window11(1, 2, 3, 4);
Window window12{1, 2, 3, 4};
 */
// Виклик конструктора для масиву об'єктів:
/* Window arr[3]; 

Window arr3[3] =
{
    Window(3, 4),
    Window(),
    Window(1, 2, 50, 60)
}; 

Window* arr = new Window[3]
{
    Window(),
    Window(1, 2),
    Window(1, 5, 6)
};
*/
    return 0;
}
