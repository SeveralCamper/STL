#include <deque>
#include <iostream>

// std::deque - double-ended queue (двусторонняя очередь) - контейнер, который обеспечивает эффективное
// добавление и удаление элементов как с начала, так и с конца. Реализован с использованием набора буферов фиксированного размера.
// Основная структура представляет собой таблицу указателей на эти буферы, называемую картой или индиректным вектором. Каждый
// буфер хранит фиксированное количество элементов, и буферы распределяются по мере необходимости, когда контейнер растет или сокращается.

// Благодаря такой структуре позволяет эффективно управлять памятью: Поскольку элементы хранятся в отдельных буферах,
// std::deque не требует выделения и освобождения больших блоков памяти, как это делает std::vector. Это позволяет std::deque более
// эффективно справляться с частыми вставками и удалениями элементов в начале и конце контейнера. Эффективность вставки и удаления на концах
// O(1), сложность вставки/удаления в другом месте O(n)

// Вставка и удаление в концах за константное время O(1), любое место O(n)
// Получить любой элемент: O(n);
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

	// Часто интересуются разницой между std::deque и std::vector. А также что и в каких случаях эффективнее использовать:

	// Размещение памяти: std::vector хранит свои элементы в одном непрерывном блоке памяти, что гарантирует, что все элементы
	// располагаются рядом друг с другом в памяти. std::deque же хранит свои элементы в нескольких буферах, что позволяет
	// эффективно управлять вставками и удалениями в начале и конце.

	// std::vector имеет сложность вставки в конце O(1), а в начале O(n), когда для std::map сложность вставки и в начале и в конце O(1).

    return 0;
}