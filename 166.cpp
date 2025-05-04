#include <iostream>
#include <string>
#include <direct.h> // for _mkdir()

void ShowErrnoMessage()
{
    std::cout << "Error code: " << errno << std::endl;
    std::cout << "Message: ";
    if (errno == EEXIST)
        std::cout << "Folder already exists.\n";
    else if (errno == ENOENT)
        std::cout << "Path is incorrect.\n";
    std::cout << std::endl;
}

struct Person
{
    char name[50]{};
    int age;
};

void CreateFolder()
{
    const char* folder1Name = "MyFolder";
    const wchar_t* folder2Name = L"Моя папка";
    int creationResult;
    creationResult = _mkdir(folder1Name);
    if (creationResult != 0)
    {
        std::cout << "Error! Could not create folder.\n";
        ShowErrnoMessage();
    }
    creationResult = _wmkdir(folder2Name);
    if (creationResult != 0)
    {
        std::cout << "Error! Could not create folder.\n";
        ShowErrnoMessage();
    }
}

void RenameFolder()
{
    const char* oldName = "Filder";
    const char* newName = "Folder";
    int renamingResult = rename(oldName, newName);
    if (renamingResult != 0)
        std::cout << "Folder could not be renamed.\n";
}

void DeleteFolder()
{
    const char* folderPath = "Empty";
    std::string removeCommand = "rmdir ";
    removeCommand += folderPath;
    int removingResult = system(removeCommand.c_str());
    if (removingResult != 0)
        std::cout << "Folder could not be removed.\n";
}

void CreateFile()
{
    // use fopen or fopen_s to create a file
    // modes: "w", "a", "r+" etc.
}

void RenameFile()
{
    const char* oldName = "OldFileName";
    const char* newName = "NewFileName";
    int renamingResult = rename(oldName, newName);
    if (renamingResult != 0)
        std::cout << "File could not be renamed.\n";
}

void DeleteFile()
{
    const char* filename = "MyFileForDelete.txt";
    int deletionResult = remove(filename);
    if (deletionResult != 0)
        std::cout << "File could not be removed.\n";
}

void CloseFile()
{
    const char* filename = "SomeFile.txt";
    FILE* file;
    fopen_s(&file, filename, "w");
    while (true) { }
    fclose(file);
}

void ReadFromFile()
{
    {
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if (fileStream == nullptr)
        {
            std::cout << "Could not open the file.\n";
            return;
        }
        int character = fgetc(fileStream);
        while (character != EOF)
        {
            std::cout << static_cast<char>(character);
            character = fgetc(fileStream);
        }
        fclose(fileStream);
    }

    {
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if (fileStream == nullptr)
        {
            std::cout << "Could not open the file.\n";
            return;
        }

        const size_t SIZE = 100;
        char string[SIZE]{};

        while (fgets(string, SIZE, fileStream) != nullptr)
        {
            std::cout << string;
        }

        fclose(fileStream);
    }

    {
        int intVariable = 10;
        const size_t SIZE = 3;
        char charArray[SIZE] = { 'A', 'B', 'C' };
        Person demian{ "Demian", 25 };

        FILE* fileStream{};
        const char* filename = "Data.bin";
        fopen_s(&fileStream, filename, "wb");
        if (fileStream != nullptr)
        {
            fwrite(&intVariable, sizeof(int), 1, fileStream);
            fwrite(charArray, sizeof(char), SIZE, fileStream);
            fwrite(&demian, sizeof(Person), 1, fileStream);
            fclose(fileStream);
        }

        intVariable = 0;
        charArray[0] = '\0';
        demian.age = 0;
        demian.name[0] = '\0';

        fopen_s(&fileStream, filename, "rb");
        if (fileStream != nullptr)
        {
            fread(&intVariable, sizeof(int), 1, fileStream);
            fread(charArray, sizeof(char), SIZE, fileStream);
            fread(&demian, sizeof(Person), 1, fileStream);
            fclose(fileStream);
        }

        std::cout << "intVariable = " << intVariable << std::endl;
        std::cout << "charArray = [";
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cout << charArray[i];
        }
        std::cout << "]\n";
        std::cout << "demian.name: " << demian.name << std::endl;
        std::cout << "demian.age: " << demian.age << std::endl;
    }
}

void WriteIntoFile()
{
    {
        FILE* fileStream = nullptr;
        const char* filename = "Characters.txt";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            fputc('!', fileStream);
            fputc('@', fileStream);
            fputc('#', fileStream);
            fclose(fileStream);
        }
    }

    {
        FILE* fileStream = nullptr;
        const char* filename = "Strings.txt";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            fputs("My name is ", fileStream);
            fputs("Demian\n", fileStream);
            fputs("And I am trying to put some strings into file", fileStream);
            fclose(fileStream);
        }
    }

    {
        FILE* fileStream = nullptr;
        const char* filename = "Numbers.bin";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            const size_t SIZE = 4;
            int numbers[SIZE] = { 1, 2, 10, 20 };

            fwrite(numbers, sizeof(int), SIZE, fileStream);
            fclose(fileStream);
        }
    }
}

void FilePositioning()
{
    {
        FILE* fileStream = nullptr;
        const char* filename = "Good text.txt";

        fopen_s(&fileStream, filename, "r+");
        if (fileStream != nullptr)
        {
            int character;
            while ((character = fgetc(fileStream)) != EOF)
            {
                if (character == 'a')
                {
                    fseek(fileStream, -1, SEEK_CUR);
                    fputc('A', fileStream);
                    fseek(fileStream, 1, SEEK_CUR);
                }
            }
            fclose(fileStream);
        }
    }
}

int main()
{
    CreateFolder();
    RenameFolder();
    DeleteFolder();
    CreateFile();
    RenameFile();
    DeleteFile();
    CloseFile();
    ReadFromFile();
    WriteIntoFile();
    FilePositioning();
}
