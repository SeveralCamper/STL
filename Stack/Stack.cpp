#include <stack>
#include <iostream>

// std::stack - представляет собой адаптер контейнера, который предоставляет ограниченный доступ к элементам только через вершину стека
// (LIFO — Last In, First Out). Он использует другие контейнеры в качестве базы для хранения элементов и обеспечивает только ограниченный набор операций.

// Ограничивает функционал контейнера до push, top, pop. Тем самым реализую структуру данных stack.
// Все операции с вершиной стека выполняются за O(1)

int main()
{
 	std::stack<int> stack_1;

    // Вставка элементов
    stack_1.push(1);
    stack_1.push(2);
    stack_1.push(3);

    // Доступ к элементу на вершине стека и удаление
    std::cout << "Stack top: " << stack_1.top() << std::endl; // Выведет 3
    stack_1.pop(); // Удаляем верхний элемент

    // Вставка нового элемента
    stack_1.push(4);

    // Вывод содержимого стека
    std::cout << "Stack size: " << stack_1.size() << std::endl; // Выведет 2 (так как удалили один элемент)
    std::cout << "Stack: ";
    while (!stack_1.empty()) {
        std::cout << stack_1.top() << " "; // Выведет 4 2 (последний добавленный элемент на вершине)
        stack_1.pop();
    }
    std::cout << std::endl;

	stack_1.push(4);
	stack_1.emplace(5); // emplace работает быстрее push, т.к. создает не новый объект в коллекцию, а заменят уже имеющийся.

    std::cout << "Stack top: " << stack_1.top() << std::endl << std::endl; // Выведет 5
    stack_1.pop();

	// Чтобы использовать stack как адаптер для другого контейнера, нужно передать тип контейнра вторым параметром

	std::stack<int, std::deque<int>> stack_2;

    stack_2.push(1);
    stack_2.push(2);
    stack_2.push(3);

    std::cout << "Stack top: " << stack_2.top() << std::endl; // Выведет 3
    stack_2.pop(); // Удаляем верхний элемент

    stack_2.push(4);

    std::cout << "Stack size: " << stack_2.size() << std::endl; // Выведет 3
    std::cout << "Stack: ";
    while (!stack_2.empty()) {
        std::cout << stack_2.top() << " "; // Выведет 4 2 1 (обратный порядок добавления)
        stack_2.pop();
    }
    std::cout << std::endl;
	
	return 0;
}