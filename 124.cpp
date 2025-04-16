#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <stdexcept>
 /* std::unique_ptr это умный указатель, который владеет другим объектом и управляет им через указатель и удаляет этот объект, когда unique_ptr выходит за пределы области видимости. */
// вспомогательный класс для демонстрации полиморфизма времени выполнения ниже
struct B {
 
    virtual ~B() = default;
 
    virtual void bar() { std::cout << "B::bar\n"; }
 
};
 
struct D : B
{
    D() { std::cout << "D::D\n";  }
    ~D() { std::cout << "D::~D\n";  }
 
    void bar() override { std::cout << "D::bar\n";  }
};
 
// функция, принимающая unique_ptr, может принимать его по значению или по правосторонней
// ссылке
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}
 
// вспомогательная функция для демонстрации пользовательского удаления ниже
void close_file(std::FILE* fp)
{ 
    std::fclose(fp);
}
 
// Демонстрация связанного списка на основе unique_ptr
struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };
 
    std::unique_ptr<Node> head;
 
    ~List()
    {
        // уничтожение узлов списка последовательно в цикле, деструктор по умолчанию
        // рекурсивно вызывал бы свой `следующий` деструктор, что вызвало бы
        // переполнение стека для достаточно больших списков.
        while (head)
        {
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }
 
    void push(int data)
    {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};
 
int main()
{
    std::cout << "1) Демонстрация уникальной семантики владения\n";
    {
        // Создаётся ресурс (с уникальным владением)
        std::unique_ptr<D> p = std::make_unique<D>();
 
        // Передача права собственности в `pass_through`, которая, в свою очередь,
        // передаёт право собственности обратно через возвращаемое значение
        std::unique_ptr<D> q = pass_through(std::move(p));
 
        // `p` теперь находится в перемещённом 'пустом' состоянии, равном `nullptr`
        assert(!p);
    }
 
    std::cout << "\n" "2) Демонстрация полиморфизма времени выполнения\n";
    {
        // Создаёт производный ресурс и указывает на него через базовый тип
        std::unique_ptr<B> p = std::make_unique<D>();
 
        // Динамическая диспетчеризация работает должным образом
        p->bar();
    }
 
    std::cout << "\n" "3) Демонстрация пользовательского удаления\n";
    std::ofstream("demo.txt") << 'x'; // подготовка файла для чтения
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("demo.txt", "r"), &close_file);
        if (fp)
            std::cout << char(std::fgetc(fp.get())) << '\n';
    } // здесь вызывается `fclose()` (если `fp` не null)
 
    std::cout << "\n" "4) Демонстрация пользовательского удаления лямбда-выражением"
                 "и безопасности исключений\n";
    try
    {
        std::unique_ptr<D, void(*)(D*)> p(new D, [](D* ptr)
        {
            std::cout << "уничтожение с помощью пользовательского средства удаления...\n";
            delete ptr;
        });
 
        throw std::runtime_error(""); // `p` повис бы здесь, если бы вместо этого
                                      // был бы простой указатель
    }
    catch (const std::exception&) { std::cout << "Поймано исключение\n"; }
 
    std::cout << "\n" "5) Демонстрация формы массива unique_ptr\n";
    {
        std::unique_ptr<D[]> p(new D[3]);
    } // `D::~D()` вызывается 3 раза
 
    std::cout << "\n" "6) Демонстрация связанного списка\n";
    {
        List wall;
        const int enough{1'000'000};
        for (int beer = 0; beer != enough; ++beer)
            wall.push(beer);
 
        std::cout.imbue(std::locale("en_US.UTF-8"));
        std::cout << enough << " бутылок пива на стойке...\n";
    } // уничтожает всё пиво
}