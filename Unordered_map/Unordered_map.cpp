#include <unordered_map>
#include <iostream>

// std::unordered_map - контейнер, который хранит пары ключ-значение и реализован с использованием хеш-таблицы.
// В отличие от std::map, std::unordered_map не поддерживает порядок элементов, но обеспечивает постоянное время выполнения для большинства операций в среднем.

// Вставка элемента (insert, operator[]): O(1) в среднем, O(N) в худшем случае.
// Удаление элемента (erase): O(1) в среднем, O(N) в худшем случае.
// Поиск элемента (find): O(1) в среднем, O(N) в худшем случае.
// Доступ к элементам по ключу (operator[]): O(1) в среднем, O(N) в худшем случае.
// Доступ к первому/последнему элементу (begin, end): O(1)

int main() {
    std::unordered_map<std::string, int> my_unordered_map = {
        {"Alice", 23},
        {"Bob", 34},
        {"Charlie", 29}
    };

    // Метод insert() добавляет элемент в unordered_map.
    std::cout << "Method insert()" << std::endl;
    my_unordered_map.insert({"Dave", 40});
    my_unordered_map.insert({"Eve", 25});

    // Печать элементов unordered_map
    for (const auto& pair : my_unordered_map) {
        std::cout << pair.first << ": " << pair.second << " "; // Порядок может быть произвольным
    }
    std::cout << std::endl;

    // Метод find() ищет элемент в unordered_map.
    std::cout << "Method find()" << std::endl;
    auto it = my_unordered_map.find("Charlie");
    if (it != my_unordered_map.end()) {
        std::cout << "Element found: " << it->first << " -> " << it->second << std::endl; // Выведет: Элемент найден: Charlie -> 29
    } else {
        std::cout << "Element not found:" << std::endl;
    }
    std::cout << std::endl;

    // Метод erase() удаляет элемент из unordered_map.
    std::cout << "Method erase()" << std::endl;
    my_unordered_map.erase("Alice");

    // Печать элементов unordered_map
    for (const auto& pair : my_unordered_map) {
        std::cout << pair.first << ": " << pair.second << " "; // Порядок может быть произвольным
    }
    std::cout << std::endl;

    // Метод operator[] для доступа и изменения значений по ключу.
    std::cout << "Method operator[]" << std::endl;
    my_unordered_map["Frank"] = 27;
    std::cout << "Frank: " << my_unordered_map["Frank"] << std::endl; // Выведет: Frank: 27
    std::cout << std::endl;

    // Метод size() возвращает количество элементов в unordered_map.
    std::cout << "Method size()" << std::endl;
    std::cout << "Size: " << my_unordered_map.size() << std::endl; // Выведет: Размер unordered_map: 5
    std::cout << std::endl;

    // Метод clear() очищает .
    std::cout << "Method clear()" << std::endl;
    my_unordered_map.clear(); // очищает unordered_map

    std::cout << "Size after clear: " << my_unordered_map.size() << std::endl; // Выведет: Размер unordered_map после clear: 0

    return 0;
}