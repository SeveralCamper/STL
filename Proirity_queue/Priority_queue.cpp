#include <queue>
#include <iostream>

// std::priority_queue - является адаптером контейнера, который предоставляет интерфейс для работы с приоритетной очередью, где элементы хранятся в порядке убывания их приоритета.
// Контейнер использует один из контейнеров из стандартной библиотеки для хранения элементов и обеспечивает ограниченный набор операций.

// Вставка элемента: O(log n) Добавление элемента в приоритетную очередь выполняется за время, необходимое для поддержания порядка элементов . push()
// Удаление элемента: O(log n) Удаление элемента с наивысшим приоритетом также выполняется за время, необходимое для поддержания порядка . pop()
// Доступ к элементу с наивысшим приоритетом : O(1) Получение элемента с наивысшим приоритетом (верхнего элемента) выполняется за константное время. top()
// Поиска как такового нет. Доступ идет через элемент с наивысшим приоритетом

// В отличие от queue и stack не может использовать list в качестве базового контейнера

// Приоритет в очереи определеятся следующим образом: если число больше, оно уходи наверх, если меньше - вниз. Таким образом, вне зависимости от того, как мы
// добавляем элементы, они отсортируются от большего к меньшему.

int main() {
    // Создаем приоритетную очередь целых чисел (по убыванию)
    std::priority_queue<int> priority_queue_1;

    // Вставляем элементы в приоритетную очередь
    priority_queue_1.push(3);
    priority_queue_1.push(1);
    priority_queue_1.push(4);
    priority_queue_1.push(2);

    // Выводим текущий максимальный элемент (4)
    std::cout << "Max element: " << priority_queue_1.top() << std::endl;

    // Удаляем максимальный элемент
    priority_queue_1.pop();

    // Вставляем новый элемент
    priority_queue_1.push(5);

    // Выводим размер приоритетной очереди
    std::cout << "Priority queue size: " << priority_queue_1.size() << std::endl; // Выведет 3

    // Выводим содержимое приоритетной очереди (по убыванию)
    std::cout << "Priority queue: ";
    while (!priority_queue_1.empty()) {
        std::cout << priority_queue_1.top() << " "; // Выведет 5 3 2 (по убыванию)
        priority_queue_1.pop();
    }
    std::cout << std::endl << std::endl;

	// Чтобы использовать priority_queue как адаптер для другого контейнера, нужно передать тип контейнра вторым параметром

    std::priority_queue<int, std::vector<int>> priority_queue_2;

    priority_queue_2.push(3);
    priority_queue_2.push(1);
    priority_queue_2.push(4);

    std::cout << "Max element: " << priority_queue_2.top() << std::endl; // Выведет 4
    priority_queue_2.pop(); // Удаляем максимальный элемент

    priority_queue_2.push(2);

    std::cout << "Priority queue size: " << priority_queue_2.size() << std::endl; // Выведет 3
    std::cout << "Priority queue: ";
    while (!priority_queue_2.empty()) {
        std::cout << priority_queue_2.top() << " "; // Выведет 3 2 1 (по убыванию)
        priority_queue_2.pop();
    }
    std::cout << std::endl;

    return 0;
}