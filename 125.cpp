/* 
std::shared_ptr это умный указатель, с разделяемым владением объектом через его указатель. Несколько указателей shared_ptr могут владеть одним и тем же объектом. Объект будет уничтожен и занятая им память будет освобождена в одном из следующих случаев:
когда последний shared_ptr, владеющий указателем на объект, будет уничтожен;
когда последнему shared_ptr, владеющему указателем на объект, будет присвоен другой указатель с помощью operator= или reset(). */
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
 
using namespace std::chrono_literals;
 
struct Base
{
    Base() { std::cout << "Base::Base()\n"; }
 
    // Примечание: здесь можно использовать невиртуальный деструктор
    ~Base() { std::cout << "Base::~Base()\n"; }
};
 
struct Derived: public Base
{
    Derived() { std::cout << "Derived::Derived()\n"; }
 
    ~Derived() { std::cout << "Derived::~Derived()\n"; }
};
 
void print(const std::string& rem, std::shared_ptr<Base> const& sp)
{
    std::cout << rem << "\n\tget() = " << sp.get()
              << ", use_count() = " << sp.use_count() << '\n';
}
 
void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(987ms);
    std::shared_ptr<Base> lp = p; // потокобезопасный, даже если
                                  // общий use_count инкрементриуется
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        print("Локальный указатель в потоке:", lp);
    }
}
 
int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    print("Создание общего Derived (как указателя на Base)", p);
 
    std::thread t1{thr, p}, t2{thr, p}, t3{thr, p};
    p.reset(); // освободить владение из main
 
    print("Совместное владение между 3 потоками и освобождение владения из main:", p);
 
    t1.join(); t2.join(); t3.join();
 
    std::cout << "Все потоки завершены, последним удаляется Derived.\n";
}