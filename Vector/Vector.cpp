#include <vector>
#include <iostream>

// std::vector - это шаблонный класс, предоставляемый стандартной библиотекой C++, который представляет собой динамический массив.
// Он является частью STL (Standard Template Library) и поддерживает автоматическое управление памятью, изменение размера, доступ по индексу и многое другое.
// Самые важные характеристики: динамическое изменение размера при добавлении, удалении. Последовательное хранение элементов - располагается непрерывно в памтя.
// Управление памятью происходит автоматически

// Вставка в начало: O(n), т.к. требует сдвига массива вправо (перевыделения памяти)
// Вставка в конец: O(1) - амортизированная вставка - в общем случае, когда параметр capacity > параметра size, вставка будет занимать O(1), в случае же
// когда capacity <  size произойдет перераспределение памяти с увеличением показателя capacity в 2 раза, что привед к сложности вставки в конец O(n). 
// Если мы заранее знаем примерное кол-во объектов в векторе мы можем сделать ручное резервированние для оптимизации вставки в конец с помощью reserve().
// Вставка в любое место O(n)

// Удаление сначала: O(n) - Требует сдвига всех элементов влево.
// Удаление с конца: O(1) - Удаление последнего элемента. Перераспределение памяти не требуется.
// Удаление из любого места: O(n) - требует сдвига элементов влево

// Получить любой элемент: O(1);
// Поиск: O(n). - линейный поиск.

int main()
{
	std::vector<double> vector_1;
	// Метод insert() добавляет value перед элементов, на который указывает итератор pos().
	std::cout << "Method insert()" << std::endl;
	vector_1.insert(vector_1.begin(), 1); // добавлет в начало вектора значение 1
	vector_1.insert(vector_1.begin() + 1, 1); // добавляет во второе значение вектора 1
	vector_1.insert(vector_1.begin(), 3); // добавляет во второе значение вектора 1
	
	for (auto& el : vector_1)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl << std::endl;
	// Имеет перегрузку, блягодаря которой можно вставить сразу несколько элементов - count копий value перед элементом, на который указывает итератор pos.
	vector_1.insert(vector_1.end(), 3, 5); // результат: 3 1 1 5 5 5
	for (auto& el : vector_1)
	{
		std::cout << el << std::endl;
	}
	std::cout << std::endl << std::endl;
	// важно отметить, что в данном случае вывод будет не 3 1 5 5 5 1, т.к. метод end() возвращает итератор
	// на следующий за последним элементов.

	// Метод erase() удаляет value на который указывает итератор pos().
	std::cout << "Method erase()" << std::endl;
	vector_1.erase(vector_1.begin());
	vector_1.erase(vector_1.end() - 1); // если бы вызвали erase() для end() получили бы UB
	for(auto it = vector_1.begin(); it < vector_1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Метод push_back() добавляет элемент в конец вектора.
	std::cout << "Method push_back()" << std::endl;
	vector_1.push_back(5.125);
	for(auto it = vector_1.begin(); it < vector_1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Метод push_front() и pop_front() для вектора не раелизованы  из-за невыгодной асимтотической сложности данного действия O(n). Так нам намекают, что лучше все добавлять в конец

	// Поддерживает все те же методы, что и array() их описывать не имеет смысла.
	// Поддерживает begin(), end(), cbegin(), cend(), rbegin(), rend().
	
	// Метод pop_back() удаляет элемент в конец вектора.
	std::cout << "Method pop_back()" << std::endl;
	vector_1.pop_back();
	for(auto it = vector_1.begin(); it < vector_1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Метод resize() изменяет размер на value.
	std::cout << "Method resize()" << std::endl;
	vector_1.resize(2);
	for(auto it = vector_1.begin(); it < vector_1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Метод clear() очищает вектор.
	std::cout << "Method clear()" << std::endl;
	vector_1.clear();
	for(auto it = vector_1.begin(); it < vector_1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << std::endl;

	return 0;
}