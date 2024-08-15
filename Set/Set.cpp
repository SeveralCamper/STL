#include <set>
#include <iostream>

// std::set - контейнер, который хранит уникальные элементы в отсортированном порядке. Он реализован
// как самобалансирующееся двоичное дерево поиска (обычно это красно-черное дерево), что обеспечивает логарифмическое время выполнения основных операций.

// Вставка элемента в любое место: O(log N) так происходит из-за того, что set автоматически поддерживает сортировку в контейнере
// Удаление элемента из любого места: O(log N) поэтому и для вставки, и для удаления трудоемкость в любое место одинакова
// Доступ к первому/последнему элементу (begin, end): O(1)
// Если использовать std::next, то можно получить доступ к элементу по позиции, таким образом мы получи доступ до любого элемента, кроме первого и последнего
// за O(n)
// Поиск: (find): O(log N)

// multiset может просто хранить множество одинаковых значенией. Значения не уникальны.

int main()
{
    std::set<int> set_1;

    // Метод insert() добавляет элемент в множество.
    std::cout << "Method insert()" << std::endl;
    set_1.insert(3); // добавляет 3
    set_1.insert(1); // добавляет 1
    set_1.insert(4); // добавляет 4
    set_1.insert(1); // не добавляет 1, так как он уже существует

    auto it_1 = std::next(set_1.begin(), 2); // Смещение итератора на 2 позиции вперед
    std::cout << "Third element: " << *it_1 << std::endl;

    for (auto it = set_1.begin(); it != set_1.end(); ++it) {
        std::cout << *it << " "; // Выведет: 1 3 4
    }
    std::cout << std::endl << std::endl;

    // Метод find() ищет элемент в множестве.
    std::cout << "Method find()" << std::endl;
    auto it_2 = set_1.find(3); // ищет элемент 3
    if (it_2 != set_1.end()) {
        std::cout << "Element found: " << *it_2 << std::endl; // Выведет: Элемент найден: 3
    } else {
        std::cout << "Element not found" << std::endl;
    }
    std::cout << std::endl;

    // Метод erase() удаляет элемент из множества.
    std::cout << "Method erase()" << std::endl;
    set_1.erase(3); // удаляет 3

    for (auto it = set_1.begin(); it != set_1.end(); ++it) {
        std::cout << *it << " "; // Выведет: 1 4
    }
    std::cout << std::endl << std::endl;

    // Метод size() возвращает количество элементов в множестве.
    std::cout << "Method size()" << std::endl;
    std::cout << "Size: " << set_1.size() << std::endl; // Выведет: Размер множества: 2
    std::cout << std::endl;

    // Метод clear() очищает множество.
    std::cout << "Method clear()" << std::endl;
    set_1.clear(); // очищает множество

    std::cout << "Size after clear: " << set_1.size() << std::endl; // Выведет: Размер множества после clear: 0

	return 0;
}