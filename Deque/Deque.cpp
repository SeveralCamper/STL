#include <deque>
#include <iostream>

// std::deque - double-ended queue, двусторонняя очередь) контейнер, который обеспечивает эффективное
// добавление и удаление элементов как с начала, так и с конца. 

// Вставка и удаление в любое место за константное время O(1).
// Получить любой элемент: O(1);
// Поиск: O(n). - линейный поиск.

int main() {
    std::deque<double> deque_1;

    // Метод push_front() добавляет элемент в начало дека.
    std::cout << "Method push_front()" << std::endl;
    deque_1.push_front(1.5);
    deque_1.push_front(2.5);
    deque_1.push_front(3.5);

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Метод push_back() добавляет элемент в конец дека.
    std::cout << "Method push_back()" << std::endl;
    deque_1.push_back(4.5); // добавляет в конец дека значение 4.5

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Метод pop_front() удаляет элемент из начала дека.
    std::cout << "Method pop_front()" << std::endl;
    deque_1.pop_front();

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Метод pop_back() удаляет элемент из конца дека.
    std::cout << "Method pop_back()" << std::endl;
    deque_1.pop_back();

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Метод resize() изменяет размер дека.
    std::cout << "Method resize()" << std::endl;
    deque_1.resize(2);

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Метод clear() очищает дек.
    std::cout << "Method clear()" << std::endl;
    deque_1.clear();

    for(auto it = deque_1.begin(); it < deque_1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

	// Для deque также определен оператор []:
	std::cout << deque_1[0] << std::endl;

    return 0;
}