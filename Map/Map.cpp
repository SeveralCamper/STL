#include <map>
#include <iostream>

// std::map - представляет собой ассоциативный контейнер, который хранит пары ключ-значение, где каждый ключ уникален.
// Внутренне std::map реализован как самобалансирующееся двоичное дерево поиска (обычно это красно-черное дерево),
// что обеспечивает логарифмическое время выполнения основных операций.

// Вставка элемента (insert или operator[]): O(log N)
// Удаление элемента (erase): O(log N)
// Доступ к элементу по ключу (operator[]): O(log N)
// Доступ к первому/последнему элементу (begin, end): O(1)
// Поиск элемента (find): O(log N)

// multimap может просто хранить множество одинаковых ключей. Ключи не уникальны.

int main()
{
	std::map<int, std::string> my_map;

    // Метод insert() добавляет пару ключ-значение в map.
    std::cout << "Method insert()" << std::endl;
    my_map.insert({3, "three"}); // добавляет пару (3, "three")
    my_map.insert({1, "one"});   // добавляет пару (1, "one")
    my_map.insert({4, "four"});  // добавляет пару (4, "four")
    my_map.insert({1, "one"});   // не добавляет, так как ключ 1 уже существует

    for (const auto& pair : my_map) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Выведет: 1: one, 3: three, 4: four
    }
    std::cout << std::endl;

    // Метод find() ищет элемент по ключу в ,ap.
    std::cout << "Method find()" << std::endl;
    auto it = my_map.find(3); // ищет ключ 3
    if (it != my_map.end()) {
        std::cout << "Element found: " << it->first << ": " << it->second << std::endl; // Выведет: Элемент найден: 3: three
    } else {
        std::cout << "Element not found" << std::endl;
    }
    std::cout << std::endl;

    // Метод erase() удаляет элемент по ключу из map.
    std::cout << "Method erase()" << std::endl;
    my_map.erase(3); // удаляет пару с ключом 3

    for (const auto& pair : my_map) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Выведет: 1: one, 4: four
    }
    std::cout << std::endl;

    // Метод operator[] используется для доступа к элементу по ключу.
    std::cout << "Method operator[]" << std::endl;
    my_map[2] = "two"; // добавляет пару (2, "two")
    std::cout << "Elemant with key 2: " << my_map[2] << std::endl; // Выведет: Элемент с ключом 2: two
    std::cout << std::endl;

    // Метод size() возвращает количество элементов в map.
    std::cout << "Method size()" << std::endl;
    std::cout << "Size: " << my_map.size() << std::endl; // Выведет: Размер карты: 3
    std::cout << std::endl;

    // Метод clear() очищает map.
    std::cout << "Method clear()" << std::endl;
    my_map.clear();

    std::cout << "Size after clear: " << my_map.size() << std::endl; // Выведет: Размер карты после clear: 0

	return 0;
}