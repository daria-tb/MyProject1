#include <iostream>
// 1-value (left value) 
//це об'єкт, який займає певне місце в пам'яті, яке можна ідентифікувати (наприклад за адресою). //

// r-value (right value) 
// це вираз, який не являється об'єктом, який можна ідентифікувати
//l-val -> r-val
//r-v + r-v

void Swap(int& a, int& b);
int& Min(int arr[], int size);

int main()
{
   /*  int a = 7; //l-value
    int b = 4; //l-value
    int c = a + b; //r-value
//----
    int arr[3];//r-value
    int arr[4]; //r-value

// але
    int arr1[] = {1,2};
    int* p = &arr1[0];
    *(p+1) = 10;
    // * (розіменуваннч) приймає r-value і повертає l-value
    // & (отримання адреси) приймає l-value і повертає r-value
     */
//------------
// Посилання - це константний() прихований (не можемо істати адресу самого посилання) специфічний вказівник, який в собі зберігає адресу обʼєкту
// Синтаксис створення посилання:
// Тип_Даних& Ім'я_Посилання = Значення; 
// Тип_Даних&& Ім'я_Посилання = Значення; 

    int variable = 10; 
    const int CONST = 20;

    int* ptr1 = &variable;
    int& ref1 = variable; //в опер. памяті cтворюється обʼєкт і його значення буде адреса цієї змінної

    std::cout << "&variable = " << &variable << std::endl;
    std::cout << "&ptr1 = " << &ptr1 << std::endl;
    std::cout << "&ref1 = " << &ref1 << std::endl;

        //ref1 = const; //просто variable прирівняли до конст

    const int* ptr2 = &CONST;
    const int& ref2 = CONST;

    variable = 50;
    *ptr1 = 100;
    ref1 = 200; //variable = 20; ref = псевдонім

    std::cout << CONST << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << &ptr2 << std::endl;
//
/*     int a = 10;
    const int b = 10;

    int& ref2 = a;
    const int& ref3 = a; */
//------------- на літерал на л-валуе
    int a = 10;
    const int b = 10;

    int& ref_1 = a; // modifiable 1-value reference
    const int& ref_2 = b; // const 1-value reference

    const int& ref = 200;

    int&& ref_3 = 200; //вважається за р-велʼю тому можна змінити
    ref_3 = 500; //

    std::cout << ref_3 << std::endl;
//--------- посилання на вказівник

    int a1 = 10;
    int* p = &a;

    int*& ref_a1 = p;

    std::cout << ref_a1 << " = " << p << std::endl;
    std::cout << &ref_a1 << " = " << &p << std::endl;
//--------- посилання на масив

    int arr[5] = {1, 2, 3, 4, 5};

    int* p1 = arr;

    int (&ref_arr) [5] = arr;//реф це посилання яке посилається на масив з 5 елементівв

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << ref_arr[i] << std::endl;
    }
// відправлення данних через посилання у функцію
    
    int a2 = 10, b2 = 20;
    Swap(a2, b2);
// повернення посилась з функцію
    int arr_1[] = { 1, 2, 3 };
    int size = 3;

    /* int& minElement = Min(arr, size);
    minElement = 50; */
    //або просто:
    Min(arr_1, size) = 50;
    return 0;
}

void Swap(int& a2, int& b2)
{
    int temp = a2;
    a2 = b2;
    b2 = temp;
}

    int& Min(int arr_1[], int size)
    {
        int min = arr_1[0];
        int minIndex = 0;
        for (int i = 1; i < size; i++)
        {
            if (min > arr_1[i])
            {
                min = arr_1[i];
                minIndex = i;
            }
        } 
        return arr_1[minIndex]; 
    }

