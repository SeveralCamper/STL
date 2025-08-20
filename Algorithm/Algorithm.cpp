#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

// Алгоритмы STL библиотеки работают с любыми контейнерами через итераторы.
// Все алгоритмы делятся на несколько категорий:
// 1) Немодифицирующие последовательности
// 2) Изменение последовательности
// 3) Операции по разделению
// 4) Сортировочные операции
// 5) Операции двоичного поиска (в отсортированных диапазонах)
// 6) Другие операции над отсортированными диапазонами
// 7) Операции над множествами (в отсортированных диапазонах)
// 8) Операции с кучей
// 9) Минимальные/максимальные операции
// 10) Операции сравнения
// 11) Операции перестановки

int main()
{
	std::list<int> lst = {5, 4, 3, 2, 1};
	std::vector<int> vec = {5, 4, 3, 2, 1};
	std::map<int, int> map = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

	std::pair<const int, int> pairToFind = {3, 3};

	// Для любого контейнера используется одна и та же функция
	auto vec_it = std::find(vec.begin(), vec.end(), 3);
	auto lst_it = std::find(lst.begin(), lst.end(), 3);
	auto map_it = std::find(map.begin(), map.end(), pairToFind);

	std::cout << "Find" << std::endl;
	if (lst_it != lst.end())
	{
		std::cout << "lst_it: " << *lst_it << std::endl;
	}

	if (vec_it != vec.end())
	{
		std::cout << "vec_it: " << *vec_it << std::endl;
	}

	if (map_it != map.end())
	{
		std::cout << "map_it: " << map_it->second << std::endl;
	}
	std::cout << std::endl;

	// Изначальный вектор
	std::cout << "Initial vector" << std::endl;
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// Немодифицирующие алгоритмы

	// Упомянутый ранее find

	// Count - подсчет элементов
	std::cout << "Count" << std::endl;
	int count = std::count(vec.begin(), vec.end(), 2);
	std::cout << "Number of tows: " << count << std::endl;;
	std::cout << std::endl;

	// all_of / any_of / none_of - проверка условий
	std::cout << "All of" << std::endl;
	bool allEven = std::all_of(vec.begin(), vec.end(), [](int x)
	{ 
		return x % 2 == 0; 
	});
	std::cout << "Is all even? " << allEven << std::endl;
	std::cout << std::endl;

	// for_each - применение немодифицирующей функции к каждому элементу
	std::cout << "For each with printing" << std::endl;
	std::for_each(vec.begin(), vec.end(), [](int x)
	{
		std::cout << x * 2 << " ";
	});
	std::cout << std::endl << std::endl;

	// Модифицирующие функции

	// std::copy - копирует элементы из одного контейнера в другой
	std::cout << "Copy" << std::endl;
	std::vector<int> dest(5);
	std::copy(vec.begin(), vec.end(), dest.begin());
	for (int item : dest)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::fill - запоняет значениями контейнер
	std::cout << "Fill" << std::endl;
	std::vector<int> v(5);
	std::fill(v.begin(), v.end(), 42);
	for (int item : v)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::rotate - меняет элементы в диапазоне[первый, последний) таким образом, что элементы в[первый, середина)
	// размещаются после элементов в[середина, последний)при этом порядки элементов в обоих диапазонах сохраняются.
	// похоже на свдиг в право, но, если передать параметр сдвига больше, чем размер контейнера будет segfault
	std::cout << "Rotate" << std::endl;
	std::rotate(vec.begin(), vec.begin() + 2, vec.end());
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;
	
	// std::transform - берет элементы из заданного диапзаона и записывает их начиная с dest итерарота
	std::cout << "Transform" << std::endl;
	std::transform(vec.begin(), vec.end(), dest.begin(),
			[](int x) { return x * x; });
	for (int item : dest)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::remove и std::remove_if - Удаление осуществляется путем смещения элементов в диапазоне таким образом
	// , чтобы элементы, которые не подлежат удалению, оказались в начале диапазона.
	std::cout << "Remove" << std::endl;
	vec.push_back(2); // добавляем двоечку в конец
	auto new_end = std::remove(vec.begin(), vec.end(), 2); // переместит все элементы, не удовлетворяющие == 2, до new_end
	
	std::cout << "After remove:" << std::endl;
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
	
	// Теперь нужно реально удалить элементы
	vec.erase(new_end, vec.end());

	std::cout << "After erasing:" << std::endl;
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Remove if" << std::endl;
	// std::remove_if перемещает объекты, не удовлетворяющие функции: std::function/лямбда-выражению.
	auto newEnd = std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
	std::cout << "After remove:" << std::endl;
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;

	// Теперь нужно реально удалить элементы
	vec.erase(newEnd, vec.end());

	std::cout << "After erasing with if:" << std::endl;
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// replace - замена элементов
	std::cout << "Replace:" << std::endl;
	v.push_back(2); // добавили двоечку
	std::replace(v.begin(), v.end(), 2, 99);
	for (int item : v)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// unique - перемещает все дубли, чтобы потом удалить их от new_end до end
	std::cout << "Unique:" << std::endl;
	std::vector<int> v2 = {1, 2, 2, 3, 3, 3, 4};
	newEnd = std::unique(v2.begin(), v2.end());
	v2.erase(newEnd, v2.end()); // v = {1, 2, 3, 4}
	for (int item : v2)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::reverse - меняет порядок данных в контейнере
	std::cout << "Reverse:" << std::endl;
	std::reverse(v2.begin(), v2.end());
	for (int item : v2)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::rotate - цикл
	std::cout << "Rotate:" << std::endl;
	std::rotate(v2.begin(), v2.begin() + 2, v2.end());
	for (int item : v2)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// Алгоритмы сортировки и поиска

	// std::sort можно использовать только с контейнерами с произовльным дсотупом - array/vector/deque.
	std::cout << "Sort" << std::endl;
	std::sort(vec.begin(), vec.end());
	for (int item : vec)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	// std::sort бинарный поиск. Массив должен быть отсортирован.
	std::cout << "Binary search" << std::endl;
	bool found = std::binary_search(vec.begin(), vec.end(), 3);
	std::cout << "Is 3 appear in vector? " << found;
	std::cout << std::endl << std::endl;

	// std::merge - слияние отсортированных массивов
	std::cout << "Merge" << std::endl;
	std::vector<int> v3 = {1, 3, 5};
	std::vector<int> v4 = {2, 4, 6};
	std::vector<int> result(6);
	std::merge(v3.begin(), v3.end(), v4.begin(), v4.end(), result.begin());
	for (int item : result)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl << std::endl;

	return 0;
}