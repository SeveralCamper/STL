#include <unordered_set>
#include <iostream>

// std::unordered_set - контейнер, который хранит уникальные элементы и реализован с использованием хеш-таблицы.
// В отличие от std::set, std::unordered_set не поддерживает порядок элементов, но обеспечивает постоянное время выполнения для большинства операций в среднем.

// Вставка элемента (insert): O(1) в среднем, O(N) в худшем случае.
// Удаление элемента (erase): O(1) в среднем, O(N) в худшем случае.
// Поиск элемента (find): O(1) в среднем, O(N) в худшем случае.
// Доступ к первому/последнему элементу (begin, end): O(1)

// multiset может просто хранить множество одинаковых значенией. Значения не уникальны.

int main() {
    std::unordered_set<int> my_unordered_set = {3, 1, 4, 1, 5, 9};

    // Метод insert() добавляет элемент в множество.
    std::cout << "Method insert()" << std::endl;
    my_unordered_set.insert(7); // добавляет элемент 7
    my_unordered_set.insert(2); // добавляет элемент 2

    // Печать элементов множества
    for (const auto& elem : my_unordered_set) {
        std::cout << elem << " "; // Порядок может быть произвольным
    }
    std::cout << std::endl;

    // Метод find() ищет элемент в множестве.
    std::cout << "Method find()" << std::endl;
    auto it = my_unordered_set.find(4); // ищет элемент 4
    if (it != my_unordered_set.end()) {
        std::cout << "Element found: " << *it << std::endl; // Выведет: Элемент найден: 4
    } else {
        std::cout << "Element not found" << std::endl;
    }
    std::cout << std::endl;

    // Метод erase() удаляет элемент из множества.
    std::cout << "Method erase()" << std::endl;
    my_unordered_set.erase(3); // удаляет элемент 3

    // Печать элементов множества
    for (const auto& elem : my_unordered_set) {
        std::cout << elem << " "; // Порядок может быть произвольным
    }
    std::cout << std::endl;

    // Метод size() возвращает количество элементов в множестве.
    std::cout << "Method size()" << std::endl;
    std::cout << "Size: " << my_unordered_set.size() << std::endl; // Выведет: Размер множества: 5
    std::cout << std::endl;

    // Метод clear() очищает множество.
    std::cout << "Method clear()" << std::endl;
    my_unordered_set.clear(); // очищает множество

    std::cout << "Size after clear: " << my_unordered_set.size() << std::endl; // Выведет: Размер множества после clear: 0

    return 0;
}