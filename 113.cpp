#include <iostream>
#include <cstdlib>  // Для std::rand()
#include <ctime>    // Для std::time()

class Byte {
private:
    static const size_t SIZE = 8;  // Розмір біта (8 біт)
    unsigned bits[SIZE];           // Масив для збереження бітів

public:
    Byte() 
    {
        std::srand(static_cast<unsigned>(std::time(0)));
        for (size_t i = 0; i < SIZE; ++i) {
            bits[i] = std::rand() % 2; 
        }
    }

    void ShowBits() const 
    {
        for (size_t i = 0; i < SIZE; ++i) 
        {
            std::cout << "[" << bits[i] << "]";
        }
        std::cout << std::endl;
    }

    unsigned getBit(size_t i) const 
    {
        return bits[i];
    }

    void setBit(size_t i, unsigned value) 
    {
        bits[i] = value;
    }

    static size_t getSize() 
    {
        return SIZE;
    }

    // Перезавантаження бітових операторів (методи):
    //оператор бітового AND
    Byte bitwiseAnd(const Byte& other) const 
    {
        Byte result;
        for (size_t i = 0; i < SIZE; ++i) 
        {
            result.setBit(i, this->getBit(i) & other.getBit(i));
        }
        return result;
    }

    //оператор бітового OR
    Byte bitwiseOr(const Byte& other) const 
    {
        Byte result;
        for (size_t i = 0; i < SIZE; ++i) 
        {
            result.setBit(i, this->getBit(i) | other.getBit(i));
        }
        return result;
    }

    //оператор бітового XOR
    Byte bitwiseXor(const Byte& other) const 
    {
        Byte result;
        for (size_t i = 0; i < SIZE; ++i) 
        {
            result.setBit(i, this->getBit(i) ^ other.getBit(i));
        }
        return result;
    }

    //оператор бітового NOT (унарний)
    Byte bitwiseNot() const 
    {
        Byte result;
        for (size_t i = 0; i < SIZE; ++i) 
        {
            result.setBit(i, ~this->getBit(i) & 1); 
        }
        return result;
    }

    //оператор зсуву вліво
    Byte leftShift(int offset) const 
    {
        Byte result;
        for (size_t i = 0; i < SIZE - offset; ++i) 
        {
            result.setBit(i, this->getBit(i + offset));
        }
        return result;
    }

    // Оператор зсуву вправо
    Byte rightShift(int offset) const 
    {
        Byte result;
        for (size_t i = offset; i < SIZE; ++i) 
        {
            result.setBit(i, this->getBit(i - offset));
        }
        return result;
    }
};

// Функції для перезавантаження бітових операторів
//оператор бітового AND
Byte operator&(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::getSize(); ++i) 
    {
        result.setBit(i, lhs.getBit(i) & rhs.getBit(i));
    }
    return result;
}

/* //оператор бітового OR
Byte operator|(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::getSize(); ++i) 
    {
        result.setBit(i, lhs.getBit(i) | rhs.getBit(i));
    }
    return result;
}

//оператор бітового XOR
Byte operator^(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::getSize(); ++i) 
    {
        result.setBit(i, lhs.getBit(i) ^ rhs.getBit(i));
    }
    return result;
}

//оператор бітового NOT (унарний)
Byte operator~(const Byte& obj) 
{
    Byte result;
    for (size_t i = 0; i < Byte::getSize(); ++i) 
    {
        result.setBit(i, ~obj.getBit(i) & 1); //інвертуємо кожен біт
    }
    return result;
}

//оператор зсуву вліво
Byte operator<<(const Byte& obj, int offset) 
{
    Byte result;
    for (size_t i = 0; i < Byte::getSize() - offset; ++i) 
    {
        result.setBit(i, obj.getBit(i + offset));
    }
    return result;
}

//оператор зсуву вправо
Byte operator>>(const Byte& obj, int offset) 
{
    Byte result;
    for (size_t i = offset; i < Byte::getSize(); ++i) 
    {
        result.setBit(i, obj.getBit(i - offset));
    }
    return result;
}
 */
int main() 
{
    Byte b1, b2;

 /*    std::cout << "Побітове \"або\" (|):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();  //виведення випадкових бітів
    std::cout << "Byte #2:\n";
    b2.ShowBits(); //виведення випадкових бітів
    Byte resultOr = b1 | b2;
    std::cout << "byte1 | byte2: ";
    resultOr.ShowBits();
    
    std::cout << "\nПобітове \"виключне або\" (^):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();  
    std::cout << "Byte #2:\n";
    b2.ShowBits();
    Byte resultXor = b1 ^ b2;
    std::cout << "byte1 ^ byte2: ";
    resultXor.ShowBits();

    std::cout << "\nПобітова інверсія (~):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultNot = ~b1;
    std::cout << "~byte1: ";
    resultNot.ShowBits();
    
    std::cout << "\nПобітовий зсув вліво (<<):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultLeftShift = b1 << 2;
    std::cout << "byte1 << 2: ";
    resultLeftShift.ShowBits();

    std::cout << "\nПобітовий зсув вправо (>>):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultRightShift = b1 >> 3;
    std::cout << "byte1 >> 3: ";
    resultRightShift.ShowBits();
 */
    //------------------------
    std::cout << "Побітове \"або\" (|):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();  //виведення випадкових бітів
    std::cout << "Byte #2:\n";
    b2.ShowBits();  //виведення випадкових бітів
    Byte resultOr = b1.bitwiseOr(b2);
    std::cout << "byte1 | byte2: ";
    resultOr.ShowBits();
    
    std::cout << "\nПобітове \"виключне або\" (^):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    std::cout << "Byte #2:\n";
    b2.ShowBits();
    Byte resultXor = b1.bitwiseXor(b2);
    std::cout << "byte1 ^ byte2: ";
    resultXor.ShowBits();
    
    std::cout << "\nПобітова інверсія (~):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultNot = b1.bitwiseNot();
    std::cout << "~byte1: ";
    resultNot.ShowBits();
    
    std::cout << "\nПобітовий зсув вліво (<<):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultLeftShift = b1.leftShift(2);
    std::cout << "byte1 << 2: ";
    resultLeftShift.ShowBits();

    std::cout << "\nПобітовий зсув вправо (>>):\n";
    std::cout << "Byte #1:\n";
    b1.ShowBits();
    Byte resultRightShift = b1.rightShift(3);
    std::cout << "byte1 >> 3: ";
    resultRightShift.ShowBits();

    return 0;
}
