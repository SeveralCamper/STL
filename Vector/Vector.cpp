#include <vector>
#include <iostream>
#include <algorithm>

// std::vector - это шаблонный класс, предоставляемый стандартной библиотекой C++, который представляет собой динамический массив.
// Он является частью STL (Standard Template Library) и поддерживает автоматическое управление памятью, изменение размера, доступ по индексу и многое другое.
// Самые важные характеристики: динамическое изменение размера при добавлении, удалении.
// Последовательное хранение элементов - располагается непрерывно в памтя -> по контейнеру можно итерироваться не тольско с помощью итераторов, но и с помощью
// смещения указателя на размер элемента массива (за исключением std::vector<bool> - единственная специализация std::vector)
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
	vector_1.insert(vector_1.begin(), 3); // добавляет в начало значение вектора 3
	
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

	// Метод push_front() и pop_front() для вектора не раелизованы  из-за невыгодной асимтотической сложности данного действия O(n).
	// Так нам намекают, что лучше все добавлять в конец

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

	int value_to_find = 3;

	for (int i = 0; i < 5; i++)
	{
		vector_1.push_back(i);
	}

	std::cout << "Vector: ";
	for (auto& item : vector_1)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;

	// С помощью метода std::find можно найти элемент в std::vector за линейное время
	auto it = std::find(vector_1.begin(), vector_1.end(), value_to_find);
	if (it != vector_1.end())
	{
		std::cout << "Element found at index: " << std::distance(vector_1.begin(), it) << std::endl;
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}

	// С помощью std::binary_search - за логорифмическое. Бинарный поиск требует отсортированного массива
	bool found = std::binary_search(vector_1.begin(), vector_1.end(), value_to_find);

	if (found)
	{
		std::cout << "Element found" << std::endl;
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}
	std::cout << std::endl;

	// Итераторы
	// Итераторы вектора являются итераторами произвольного доступа - тип итераторов, который
	// поддерживает большинство операций и всю арифметику (инкремент, декремент, свдиг на n, все типы сравнения).
	// У вектора есть 4 типа итерраторов: обычный, реверсный, константный обычный, константный реверсный

	std::cout << "Vector iterators" << std::endl;
	auto iterVec = vector_1.begin(); // обычный итератор вектора. Позволяет изменять и считывать данные. Перемещаться по конетйнеру в любую сторону
	auto constIterVec = vector_1.cbegin(); // константный итератор вектора. Не позволяет изменять объект и позволяет работать с const объектами
	auto revIterVec = vector_1.rbegin(); // реверсивный итератор вектора. Возвращает реверсивное начало = конец
	auto constRevIterVec = vector_1.crbegin(); // константный реверсивный итератор вектора. Возвращает реверсивное начало = конец

	auto iterVecEnd = vector_1.end(); // обычный конец вектора.
	auto constIterVecEnd = vector_1.cend(); // константный конец вектора.
	auto revIterVecEnd = vector_1.rend(); // реверсивный конец вектора. Возвращает реверсивный конец = начало
	auto constRevIterVecEnd = vector_1.crend(); // константный реверсивный конец вектора. Возвращает реверсивный конец = начало

	// Т.к. у нас иетратор свободного досутпа, мы можем декрементироваться от begin() или инрементироваться от end() и получить UB. Но нам это не нужно

	// 1. Классический обход с помощью итераторов
	std::cout << "Forward iteration:" << std::endl;
	for (auto it = iterVec; it != iterVecEnd; ++it)
	{
		std::cout << *it << " "; // Разымменовываем итератор для получения значения
	}
	std::cout << std::endl << std::endl;

	// 2. Использование константных итераторов (если не планируется менять данные)
	std::cout << "Const iteration:" << std::endl;
	for (auto cit = constIterVec; cit != constIterVecEnd; ++cit)
	{
		// *cit = 100; // Ошибка компиляции: cit является const_iterator
		std::cout << *cit << " ";
	}
	std::cout << std::endl << std::endl;

	// 3. Обратный обход с помощью реверсных итераторов
	std::cout << "Reverse iteration:" << std::endl;
	for (auto rit = revIterVec; rit != revIterVecEnd; ++rit)
	{
		std::cout << *rit << " "; // Будет: 4 3 2 1 0
	}
	std::cout << std::endl << std::endl;

	// 4. Обратный обход с помощью константных реверсных итераторов
	std::cout << "Reverse iteration:" << std::endl;
	for (auto crit = constRevIterVec; crit != constRevIterVecEnd; ++crit)
	{
		// *crit = 100; // Ошибка компиляции: cit является const_iterator
		std::cout << *crit << " "; // Будет: 4 3 2 1 0
	}
	std::cout << std::endl;

	return 0;
}