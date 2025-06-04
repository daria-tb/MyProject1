/* Двоичная куча — это полное двоичное дерево, 
которое эффективно хранит данные, обеспечивая быстрый доступ к максимальному 
или минимальному элементу в зависимости от типа кучи. 
Это может быть либо Min Heap, либо Max Heap. 
В Min Heap ключ в корне должен быть наименьшим среди всех ключей в куче, 
и это свойство должно выполняться рекурсивно для всех узлов. 
Аналогично, Max Heap следует тому же принципу, но с наибольшим ключом в корне. */
// Програма на C++ для демонстрації основних операцій над бінарною кучею (heap)
#include<iostream>
#include<climits>
using namespace std;
// Прототип допоміжної функції для обміну двох цілих чисел
void swap(int *x, int *y);
// Клас мінімальної кучи (Min Heap)
class MinHeap
{
    int *harr; // вказівник на масив елементів у кучі
    int capacity; // максимальний можливий розмір мін-кучи
    int heap_size; // поточна кількість елементів у мін-кучі
public:
    // Конструктор
    MinHeap(int capacity);

    // функція для підтримки властивості кучі піддерева з коренем у індексі i
    void MinHeapify(int i);

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }    // отримати індекс лівої дитини вузла з індексом i
    int right(int i) { return (2*i + 2); }    // отримати індекс правої дитини вузла з індексом i
    int extractMin();    // витягнути корінь, тобто мінімальний елемент
    void decreaseKey(int i, int new_val);    // зменшити значення ключа за індексом i до new_val
    int getMin() { return harr[0]; }    // повернути мінімальний ключ (ключ у корені мін-кучи)

    void deleteKey(int i);    // видалити ключ за індексом i
    void insertKey(int k);    // вставити новий ключ 'k'

};

// Конструктор: будує кучу з заданого масиву a[] та розміру
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Вставляє новий ключ k
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nПереповнення: не вдалося вставити ключ\n";
        return;
    }

    // Спочатку вставляємо новий ключ у кінець
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Виправляємо властивість мін-кучи, якщо вона порушена
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Зменшує значення ключа за індексом 'i' до new_val. Припускається, що
// new_val менше ніж harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Метод для видалення мінімального елемента (кореня) з мін-кучи
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Зберігаємо мінімальне значення і видаляємо його з кучі
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// Ця функція видаляє ключ за індексом i. Спочатку зменшує значення до мінус
// нескінченності, а потім викликає extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Рекурсивний метод для підтримки властивості кучі піддерева з коренем у заданому індексі
// Припускається, що піддерева вже мають властивість кучі
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// Допоміжна функція для обміну двох елементів
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
