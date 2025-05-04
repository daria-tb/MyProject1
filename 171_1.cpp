// 1. Поняття потоків вводу / виводу в C++
// 2. Ієрархія потоків вводу / виводу в C++
// 3. Файл fstream
// 4. Як поламати потік ?
// 5. Режими відкриття файлу
// 6. Позиція у файлі та EOF
// 7. Як зчитати текст з файлу ?
// 8. Як записати текст у файл ?
// 9. Як записати НЕ текст у файл ?
// 10. Як зчитати НЕ текст з файлу ?
// 11. Як закрити файловий потік ?
// 12. Як дізнатися позицію файлу та змінити її ?
#include <ios>
#include <ostream>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Hello World" << std::endl;

    {
        std::cout << "Enter a number: ";
        int number;
        std::cin >> number;

        if (std::cin.good())
            std::cout << "Your number = " << number << std::endl;
        else
        {
            std::cout << "Oops. Something went wrong.\n";
            if (std::cin.bad())
                std::cout << "cin.bad() == true.\n";
            if (std::cin.fail())
                std::cout << "cin.fail() == true.\n";
            if (std::cin.eof())
                std::cout << "cin.eof() == true.\n";
        }
    }

    {
        std::cout << "Enter a number: ";
        int number;
        std::cin >> number;

        while (!std::cin.good() && std::cin.fail())
        {
            std::cin.clear();
            std::cout << "You entered incorrect value. Enter only one integer number.\n";
            std::cin.ignore(LLONG_MAX, '\n');
            std::cout << "Enter a number: ";
            std::cin >> number;
        }
    }

    std::ios::in;

    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        char character;
        while (fileStream.get(character))
        {
            std::cout << character;
        }

        if (fileStream.eof())
        {
            std::cout << "\n\nWe reached the end of the file.\n";
        }
    }

    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line;
        while (std::getline(fileStream, line, '\r'))
            std::cout << line;

        if (fileStream.eof())
            std::cout << "\n\nWe reached the end of the file.\n";
    }

    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        fileStream.seekg(0, std::ios::end);
        size_t fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        size_t bufferLength = fileSize + 1;
        char* buffer = new char[bufferLength];
        fileStream.read(buffer, fileSize);
        buffer[fileSize] = '\0';

        if (fileStream.gcount() != fileSize)
        {
            std::cerr << "Error reading file. :( \n";
            return 1;
        }

        std::cout << buffer;

        delete[] buffer;
    }

    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string word;
        while (fileStream >> word)
            std::cout << word;
    }

    {
        std::string filename = "MyTextFile1.txt";
        std::ofstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::cout << "Enter some text: ";
        std::string text;
        std::getline(std::cin, text);

        size_t textLength = text.length();
        for (size_t i = 0; i < textLength; i++)
        {
            fileStream.put(text[i]);
        }
    }

    {
        std::string filename = "MyTextFile2.txt";
        std::ofstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line1 = "Today is a good day!";
        std::string line2 = "Because I am recording a lesson!";

        fileStream << line1 << '\n' << line2 << '\n';
    }

    {
        std::string filename = "MyTextFile3.txt";
        std::ofstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line = "Some line of text.";
        fileStream.write(line.c_str(), line.length());
    }

    {
        int variable = 10;
        double array[3] = { 1.123, 2.456, 3.789 };

        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            {}

            float X() const { return x; }
            float Y() const { return y; }
        };

        Point myPoint(12.3f, 54.6f);

        std::vector<int> myVector = { 1, 2, 3, 4, 5 };

        std::string filename = "MyData.bin";
        std::ofstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        fileStream.write(reinterpret_cast<const char*>(&variable), sizeof(variable));
        fileStream.write(reinterpret_cast<const char*>(&array), sizeof(double) * 3);
    }

    {
        int variable;
        double array[3];

        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            {}
            float X() const { return x; }
            float Y() const { return y; }
        };

        Point myPoint;

        std::vector<int> myVector(5);

        std::string filename = "MyData.bin";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));
        fileStream.read(reinterpret_cast<char*>(&array), sizeof(double) * 3);
        fileStream.read(reinterpret_cast<char*>(&myPoint), sizeof(Point));
        fileStream.read(reinterpret_cast<char*>(myVector.data()), sizeof(int) * myVector.size());

        std::cout << "variable = " << variable << std::endl;

        std::cout << "array = ";
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Point: [x = " << myPoint.X() << ", y = " << myPoint.Y() << "]\n";

        std::cout << "vector = ";
        for (size_t i = 0; i < myVector.size(); i++)
        {
            std::cout << myVector[i] << " ";
        }
        std::cout << std::endl;
    }


{

        std::string filename = "SomeFile";
        std::ifstream fileStream(filename);

        fileStream.close();

    }

    {
        std::string filename = "Numbers.bin";
        std::ifstream fileStream(filename, std::ios::binary);
        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        int size;
        fileStream.read(reinterpret_cast<char*>(&size), sizeof(int));

        std::vector<int> numbers(size);

        for (size_t i = 0; i < size; i++)
        {
            int number;
            fileStream.read(reinterpret_cast<char*>(&number), sizeof(int));
            numbers[i] = number;
        }

        fileStream.close();

        bool isNumberFound = false;
        size_t findIndex;
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 20)
            {
                isNumberFound = true;
                findIndex = i;
                break;
            }
        }

        if (isNumberFound)
        {
            std::ofstream fileStream(filename, std::ios::app | std::ios::binary);
            if (!fileStream.is_open())
            {
                std::cerr << "Couldn't open the file. :( \n";
                return 1;
            }

            {
                fileStream.seekp(std::ios::beg); 
                fileStream.seekp(std::ios::cur); 
                fileStream.seekp(std::ios::end); 

                fileStream.seekp(std::ios::beg, 5); 
                fileStream.seekp(std::ios::cur, -3); 
                fileStream.seekp(std::ios::end, -10); 
            }
            size_t value20Position = sizeof(int) + sizeof(int) * findIndex;
            fileStream.seekp(std::ios::beg, value20Position);
            int newNumber = 40;
            fileStream.write(reinterpret_cast<const char*>(&newNumber), sizeof(int));

            fileStream.close();

        }

    }
    
    return 0;
}