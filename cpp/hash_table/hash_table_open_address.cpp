#include <iostream>
#include <vector>
using namespace std;

// Стани комірок в хеш-таблиці
enum EntryStatus { EMPTY, OCCUPIED, DELETED };

// Структура запису в комірці хеш-таблиці
struct HashEntry {
    int key; // Ключ
    int value; // Значення
    EntryStatus status; // Стан комірки

    // При ініціалізації хеш-таблиці: вектор буде заповнений дефолтними записами
    HashEntry(): key(0), value(0), status(EMPTY){}
};

class HashTable {
private:
    vector<HashEntry> table; // Вектор, який лежить в основі хеш-таблиці
    int capacity; // Кількість комірок (розмір хеш-таблиці)
    int size; // Поточні кількість елементів в хеш-таблиці

    int hashFunction(int key) const {
        // Використовуємо обчислення залишку як хеш-функцію - O(1)
        return key % capacity;
    }

public:
    // При ініціалізації - вказуємо розмір хеш-таблиці
    HashTable(int cap): capacity(cap), size(0) {
        table.resize(capacity);
    }

    // Основні операції для роботи з хеш-таблицею
    bool insert(int key, int value);
    bool search(int key, int& valueOut);
    bool remove(int key);
};


bool HashTable::insert(int key, int value) {
    // Якщо таблиця повністю заповнена, вставка неможлива
    if (size == capacity) {
        cout << "[WARNING]: Hash table is full. Insertion failed." << endl;
        return false;
    }
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Зберігаємо індекс з якого починаємо пошук вільної комірки, щоб не зациклитись
    int start = index;

    // Якщо комірка зайнята та ключ не співпадає, виконуємо лінійне пробування
    // Найгірший випадок - O(m) - комірки зайняті усі
    // Cередній випадок при оптимальному заповненні - Θ(n/m), де n - кількість елементів, m - кількість комірок.
    while (table[index].status == OCCUPIED && table[index].key != key) {
        index = (index + 1) % capacity;
        // Повернення до початкового індексу => всі комірки зайняті => вставка неможлива
        if (index == start) return false;
    }

    // Якщо комірка зайнята, але ключі співпадають перезаписуємо значення
    if (table[index].status == OCCUPIED && table[index].key == key) {
        table[index].value = value;
        cout << "[WARNING] Key exists. Value replaced."<< endl;
        return true;
    }

    // Ключ новий, тому збільшуємо кількість елементів у таблиці
    if (table[index].status != OCCUPIED) {
        size++;
    }

    // На цьому етапі комірка незайнята, тому перезаписуємо ключ, значення та стан комірки
    table[index].key = key;
    table[index].value = value;
    table[index].status = OCCUPIED;

    return true;
}

bool HashTable::search(int key, int &valueOut) {
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Зберігаємо індекс з якого починаємо пошук вільної комірки, щоб не зациклитись
    int start = index;

    // Шукаємо, коли натрапляємо на порожню комірку, припиняємо пошук
    // Найгірший випадок - O(m)
    // Cередній випадок - Θ(1)
    while (table[index].status != EMPTY) {
        // Якщо комірка зайнята та ключ співпадає - значення знайдено, записуємо його у змінну
        if (table[index].status == OCCUPIED && table[index].key == key) {
            valueOut = table[index].value;
            return true;
        }

        // Продовжуємо лінійне пробування, якщо пройшли всю таблицю - виходимо з циклу
        index = (index + 1) % capacity;
        if (index == start) break;
    }

    return false;
}

bool HashTable::remove(int key) {
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Зберігаємо індекс з якого починаємо пошук вільної комірки, щоб не зациклитись
    int start = index;

    // Шукаємо, коли натрапляємо на порожню комірку, припиняємо пошук
    // Найгірший випадок - O(m)
    // Cередній випадок - Θ(1)
    while (table[index].status != EMPTY) {
        // Якщо комірка зайнята та ключ співпадає - значення знайдено, змінюємо стан комірки на DELETED
        if (table[index].status == OCCUPIED && table[index].key == key) {
            table[index].status = DELETED;
            size--;
            return true;
        }

        // Продовжуємо лінійне пробування, якщо пройшли всю таблицю - виходимо з циклу
        index = (index + 1) % capacity;
        if (index == start) break;
    }

    return false;
}



