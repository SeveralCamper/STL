#include <list>
#include <iostream>
#include <algorithm>

// std::list - это контейнер, который реализует двусвязный список. Он обеспечивает эффективные вставки и удаления элементов в произвольных позициях,
// но доступ по индексу к элементам и поиск элемента менее эффективны по сравнению с массивами и векторами.

// Вставка и удаление производяться в любом месте за константное время O(1). Связано это с тем, какую структуру данных реализует контейнер list, а именно
// двусвязный список. В памяти расположен не последовательно

// Получить любой элемент: O(n); Линейное время обращения к элементу, т.к. из-за внтуреннего устройства контейнера невозможно получить доступ к некоторому
// элементу не пройдя все предыдущие node с начала или с конца
// Поиск: O(n). - линейный поиск. Линейное время по той же причине

int main()
{
	std::list<int> list_1;
	// Метод push_back() добавляет value в конец.
	std::cout << "Method push_back()" << std::endl;
	list_1.push_back(2);
	list_1.push_back(3);
	list_1.push_back(2);

	for(auto it = list_1.begin(); it != list_1.end(); ++it) // важно отметить, что в std::list не перегружены операторы <, <=, >, >= для std::list<T>::iterator
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

 	// Метод push_front() добавляет value в начало.
	std::cout << "Method push_front()" << std::endl;
    list_1.push_front(0);
	for(auto& it : list_1)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl << std::endl;

    // Метод insert() добавляет value перед элементом, на который указывает итератор pos().
	std::cout << "Method insert()" << std::endl;
    auto it = std::next(list_1.begin(), 2);
    list_1.insert(it, 2);
	for(auto& it : list_1)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl << std::endl;

    // Метод pop_front() удаляет элемент из начала списка
	std::cout << "Method pop_front()" << std::endl;
    list_1.pop_front();
	for(auto& it : list_1)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl << std::endl;

    // Метод pop_back() удаляет элемент из конца списка
	std::cout << "Method pop_back()" << std::endl;
    list_1.pop_back();
	for(auto& it : list_1)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl << std::endl;

    // Метод erase() удаляет элемент на который указывает итератор pos().
	std::cout << "Method erase()" << std::endl;
    it = std::next(list_1.begin(), 1);
    list_1.erase(it);
	for(auto& it : list_1)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl << std::endl;

    // Доступ к элементу по индексу
	std::cout << "Accessing an element by index" << std::endl;
    it = std::next(list_1.begin(), 1);
    int value = *it;
	std::cout << value << std::endl;

    // Поиск элемента по значению
	std::cout << "Search" << std::endl;
    it = std::find(list_1.begin(), list_1.end(), 3);
    if (it != list_1.end()) { // если поиск не был завершен удачно, то функция std::find() вернет итерратор указывающий на позицию после последнего элемента - end()
        std::cout << "Элемент найден: " << *it << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

	// Метод at() и опертор [] не определены, т.к. это противоречит логике контейнера.

	// Метод sort() сортирует двусвязный список с помощью алгоритма merge sort. Соответственно, его асимптотическая сложность n log(n).
	std::cout << "Method sort()" << std::endl;
	list_1.push_front(2);
	list_1.push_front(7);
	list_1.push_front(3);
	list_1.push_front(15);

    list_1.sort();

    // Вывод отсортированного списка
    for (const auto& el : list_1) {
        std::cout << el << " ";
    }

	return 0;
}