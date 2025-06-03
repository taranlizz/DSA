#include <iostream>
#include <string>
#include <list>
using namespace std;


class HashTable {
private:
    static const int hashGroups = 10; // початкова кількість комірок
    list<pair<int, string>> table[hashGroups]; //масив, кожна комірка якого, буде посилатися на список з пар формату - {int, string}

    int hashFunction(int key) const {
        // Використовуємо обчислення залишку як хеш-функцію - O(1)
        return key % hashGroups;
    };

public: // основні операції для роботи з хеш-таблицею
    void insert(int key, string value);
    void remove(int key);
    string search(int key);
};


void HashTable::insert(int key, string value) {
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Отримуємо референс на список - O(1)
    auto& cell = table[index];

    // Ітеруємо масив референсів на пари значень в поточному списку для пошуку вже існуючої пари з таким ключем
    // O(n) - найгірший випадок,
    // але якщо елементи розподілені рівномірно (середній випадок) - Θ(n/b), де n - кіл-ть елементів, а b - кіл-ть блоків в масиві.
    for (auto& pair : cell) {
        // Якщо знайдено - перезаписуємо - O(1)
        if (pair.first == key) {
            pair.second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            return;
        }
    }
    // Якщо не знайдено - записуємо нову пару в кінець - O(1)
    cell.emplace_back(key,value);
}

void HashTable::remove(int key) {
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Отримуємо референс на список - O(1)
    auto& cell = table[index];

    // Ітеруємо масив референсів на пари значень в поточному списку для пошуку вже існуючої пари з таким ключем.
    // Найгірший - О(n),
    // Ceредній - Θ(n/b), b - кіл-ть блоків в масиві.
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        // Якщо знайдено - видаляємо
        if (it->first == key) {
            cell.erase(it);
            cout << "[INFO] Item removed." << endl;
            return;
        }
    }
    // Якщо не знайдено - виводимо повідомлення
    cout << "[WARNING] Key not found. Pair not removed." << endl;
}



string HashTable::search(int key) {
    // Отримуємо значення індекса після хешування ключа- O(1)
    int index = hashFunction(key);
    // Отримуємо референс на список - O(1)
    auto& cell = table[index];

    // Ітеруємо масив референсів на пари значень в поточному списку для пошуку необхідної пари.
    // Найгірший випадок О(n),
    // Ceредній - Θ(n/b), b - кіл-ть блоків в масиві.
    for (const auto& pair : cell) {
        // Якщо знайдено - виводимо повідомлення
        if (pair.first == key) {
            cout << "[INFO] Key: " << pair.first << " Value: " << pair.second << endl;
            return pair.second;  // Повертаємо шукане значення
        }
    }

    // Якщо не знайдено - виводимо відповідне повідомлення, повертаємо пустий рядок
    cout << "[WARNING] Key not found." << endl;
    return "";
}


int main() {

}

