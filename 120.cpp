#include <iostream>
//використовувати explicit (явний), можна його писати до конструкторів та до оператора привелення тип. 
//завдяки ньому заьороняється неявне приведення типу
class A 
{
public:
    A(int) { std::cout << "A::A(int)\n"; }
    A(int, int) { std::cout << "A::A(int, int)\n"; }
    A(const A&) { std::cout << "A::A(const A&)\n"; }
    operator bool() const { std::cout << "A::operator bool()\n"; return true; }
};

class B 
{
public:
    explicit B(int) { std::cout << "B::B(int)\n"; }
    explicit B(int, int) { std::cout << "B::B(int, int)\n"; }
    explicit operator bool() const { std::cout << "B::operator bool()\n"; return true; }
};

int main() 
{
    A a1(1); // OK: copy-initialization selects A::A(int)
    A a2(2); // OK: direct-initialization selects A::A(int)
    A a3(4, 5); // OK: direct-list-initialization selects A::A(int, int)
    A a4 = A(4, 5); // OK: copy-list-initialization selects A::A(int, int)
    A a5 = static_cast<A>(1); // OK: explicit cast performs static_cast

    if (a1) // OK: A::operator bool()
    { 
        std::cout << "a1 is true\n";
    }

    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization

    B b1(1); // OK: direct-initialization selects B::B(int)
    B b2(2); // OK: direct-initialization selects B::B(int)
    B b3(4, 5); // OK: direct-list-initialization selects B::B(int, int)

    // b4(4, 5); // error: copy-list-initialization does not consider B::B(int, int)
    
    B b5 = static_cast<B>(1); // OK: explicit cast performs static_cast

    if (b2) // OK: explicit cast performs static_cast
    { 
        std::cout << "b2 is true\n";
    }

    // bool nb1 = b2; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization
}