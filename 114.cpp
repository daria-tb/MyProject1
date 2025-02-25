#include <iostream>
/*
Синтаксис перезавантаження операторів:
Тип_Повертаючого_Значення operator Знак (Список_Параметрів)
{Код}
*/
class DInt
{
private:
    int* value;

public:
    DInt(int value)
        : value(new int(value))
    { }

    DInt(const DInt& other)
        : value(new int(other.GetValue()))
    { }

    DInt(DInt&& other) noexcept
        : value(other.value)
    {
        other.value = nullptr;
    }

    ~DInt()
    {
        delete value;
        value = nullptr;
    }

    int GetValue() const
    {
        return value != nullptr ? *value : 0;
    }
    void SetValue(int val)
    {
        *value = val;
    }




    DInt& operator+=(const DInt& other)
    {
        *value += other.GetValue();
        return *this;
    }

    DInt& operator-=(const DInt& other)
    {
        *value -= other.GetValue(); 
        return *this;
    }

    DInt& operator*=(const DInt& other)
    {
        *value *= other.GetValue(); 
        return *this;
    }

    DInt& operator/=(const DInt& other)
    {
        if (other.GetValue() != 0) 
        {
            *value /= other.GetValue();
        }
        return *this;
    }

    DInt& operator%=(const DInt& other)
    {
        if (other.GetValue() != 0) 
        {
            *value %= other.GetValue();
        }
        return *this;
    } 
};

/* // Перезавантаження комбінованих арифметичних операторів (функції)
// Оператор += як функція
DInt& operator+=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() + sourceNumber.GetValue());
    return destinationNumber;
}

// Оператор -= як функція
DInt& operator-=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() - sourceNumber.GetValue());
    return destinationNumber;
}

// Оператор *= як функція
DInt& operator*=(DInt& destinationNumber, const DInt& sourceNumber)
{
    destinationNumber.SetValue(destinationNumber.GetValue() * sourceNumber.GetValue());
    return destinationNumber;
}

// Оператор /= як функція
DInt& operator/=(DInt& destinationNumber, const DInt& sourceNumber)
{
    if (sourceNumber.GetValue() != 0)
    {
        destinationNumber.SetValue(destinationNumber.GetValue() / sourceNumber.GetValue());
    }
    return destinationNumber;
}

// Оператор %= як функція
DInt& operator%=(DInt& destinationNumber, const DInt& sourceNumber)
{
    if (sourceNumber.GetValue() != 0)
    {
        destinationNumber.SetValue(destinationNumber.GetValue() % sourceNumber.GetValue());
    }
    return destinationNumber;
} */

//--------------------
/* Синтаксис перезавантаження операторів:
Тип_Повертаючого_Значення operatorЗнак (Список_Параметрів)
{ code } */
class Byte
{
private:
    static const size_t SIZE = 8;
    unsigned bits[SIZE];

public:
    Byte()
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            bits[i] = std::rand() % 2;
        }
    }
        void ShowBits() const
        {
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cout << "[" << bits[i] << "]";
        }
}

// Перезавантаження оператора &= 
    Byte& operator&=(const Byte& other)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            bits[i] &= other.bits[i];
        }
        return *this;
    }

    // Перезавантаження оператора |= 
    Byte& operator|=(const Byte& other)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            bits[i] |= other.bits[i];
        }
        return *this;
    }

    // Перезавантаження оператора ^=
    Byte& operator^=(const Byte& other)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            bits[i] ^= other.bits[i];
        }
        return *this;
    }

    // Перезавантаження оператора <<=
    Byte& operator<<=(int offset)
    {
        if (offset > 0)
        {
            for (size_t i = SIZE - 1; i >= offset; --i)
            {
                bits[i] = bits[i - offset];
            }
            for (size_t i = 0; i < offset; ++i)
            {
                bits[i] = 0;
            }
        }
        return *this;
    }

    // Перезавантаження оператора >>=
    Byte& operator>>=(int offset)
    {
        if (offset > 0)
        {
            for (size_t i = 0; i < SIZE - offset; ++i)
            {
                bits[i] = bits[i + offset];
            }
            for (size_t i = SIZE - offset; i < SIZE; ++i)
            {
                bits[i] = 0;
            }
        }
        return *this;
    }
/* // Дозволяємо доступ до приватних даних для зовнішніх операторів
    friend Byte operator&(const Byte& left, const Byte& right);
    friend Byte operator|(const Byte& left, const Byte& right);
    friend Byte operator^(const Byte& left, const Byte& right);
    friend Byte operator<<(const Byte& b, int offset);
    friend Byte operator>>(const Byte& b, int offset);  */
};

/* Byte operator&(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++) 
    {
        result.bits[i] = lhs.bits[i] & rhs.bits[i];
    }
    return result;
}

Byte operator|(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++) 
    {
        result.bits[i] = lhs.bits[i] | rhs.bits[i];
    }
    return result;
}

Byte operator^(const Byte& lhs, const Byte& rhs) 
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++) 
    {
        result.bits[i] = lhs.bits[i] ^ rhs.bits[i];
    }
    return result;
}

Byte operator<<(const Byte& b, int offset) 
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++) 
    {
        if (i + offset < Byte::SIZE)
            result.bits[i] = b.bits[i + offset];
        else
            result.bits[i] = 0;
    }
    return result;
}

Byte operator>>(const Byte& b, int offset) 
{
    Byte result;
    for (size_t i = 0; i < Byte::SIZE; i++) 
    {
        if (i >= static_cast<size_t>(offset))
            result.bits[i] = b.bits[i - offset];
        else
            result.bits[i] = 0;
    }
    return result;
}

//комбіновані оператори через функції:
Byte& operator&=(Byte& destinationByte, const Byte& sourceByte) 
{
    destinationByte = destinationByte & sourceByte;
    return destinationByte;
}

Byte& operator|=(Byte& destinationByte, const Byte& sourceByte) 
{
    destinationByte = destinationByte | sourceByte;
    return destinationByte;
}

Byte& operator^=(Byte& destinationByte, const Byte& sourceByte) 
{
    destinationByte = destinationByte ^ sourceByte;
    return destinationByte;
}

Byte& operator<<=(Byte& destinationByte, int offset) 
{
    destinationByte = destinationByte << offset;
    return destinationByte;
}

Byte& operator>>=(Byte& destinationByte, int offset) 
{
    destinationByte = destinationByte >> offset;
    return destinationByte;
}
 */

//--------------------------------------------------
int main()
{
    std::srand(static_cast<unsigned>(std::time (nullptr)));

// Class 'DInt':
    std::cout << "Оператор +=:\n";
    DInt num1{10}, num2{30};

    std::cout << "num1 =            " << num1.GetValue() << std::endl;
    std::cout << "num2 =            " << num2.GetValue() << std::endl;

    num1 += num2;
    std::cout << "(num1 += num2) = " << num1.GetValue() << "\n\n";

    std::cout << "Оператор -=:\n";
    DInt num3{100}, num4{23};

    std::cout << "num3 =            " << num3.GetValue() << std::endl;
    std::cout << "num4 =            " << num4.GetValue() << std::endl;

    num3 -= num4;
    std::cout << "(num3 -= num4) = " << num3.GetValue() << "\n\n";

    std::cout << "Оператор *=:\n";
    DInt num5{3}, num6{5};

    std::cout << "num5 =            " << num5.GetValue() << std::endl;
    std::cout << "num6 =            " << num6.GetValue() << std::endl;

    num5 *= num6;
    std::cout << "(num5 *= num6) = " << num5.GetValue() << "\n\n";

    std::cout << "Оператор /=:\n";
    DInt num7{20}, num8{5};

    std::cout << "num7 = " << num7.GetValue() << std::endl;
    std::cout << "num8 = " << num8.GetValue() << std::endl;

    num7 /= num8;
    std::cout << "(num7 /= num8) = " << num7.GetValue() << "\n\n";

    std::cout << "Оператор %=:\n";
    DInt num9{18}, num10{5};

    std::cout << "num9 = " << num9.GetValue() << std::endl;
    std::cout << "num10 = " << num10.GetValue() << std::endl;

    num9 %= num10;
    std::cout << "(num9 %= num10) = " << num9.GetValue() << "\n\n";
//------------------------------------------------------------------
    // Демонстрація оператора &=
    std::cout << "Оператор &=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Байт №1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Байт №2:" << std::endl;
        byte2.ShowBits();
        byte1 &= byte2;
        std::cout << "Байт №1 &= Байт №2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Демонстрація оператора |=
    std::cout << "Оператор |=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Байт №1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Байт №2:" << std::endl;
        byte2.ShowBits();
        byte1 |= byte2;
        std::cout << "Байт №1 |= Байт №2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Демонстрація оператора ^=
    std::cout << "Оператор ^=:" << std::endl;
    {
        Byte byte1, byte2;
        std::cout << "Байт №1:" << std::endl;
        byte1.ShowBits();
        std::cout << "Байт №2:" << std::endl;
        byte2.ShowBits();
        byte1 ^= byte2;
        std::cout << "Байт №1 ^= Байт №2:" << std::endl;
        byte1.ShowBits();
        std::cout << std::endl;
    }

    // Демонстрація оператора <<=
    std::cout << "Оператор <<=:" << std::endl;
    {
        Byte byte;
        std::cout << "Байт:" << std::endl;
        byte.ShowBits();
        byte <<= 2;
        std::cout << "Байт <<= 2:" << std::endl;
        byte.ShowBits();
        std::cout << std::endl;
    }

    // Демонстрація оператора >>=
    std::cout << "Оператор >>=:" << std::endl;
    {
        Byte byte;
        std::cout << "Байт:" << std::endl;
        byte.ShowBits();
        byte >>= 2;
        std::cout << "Байт >>= 2:" << std::endl;
        byte.ShowBits();
        std::cout << std::endl;
    }

    return 0;
}