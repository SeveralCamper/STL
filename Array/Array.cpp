#include <array>
#include <iostream>
#include <algorithm>

// std::array - контейнер библиотеки STL, который является оберткой для статического массива. Т.к. это обертка для статического массива
// то и ограничения мы имеем такие же как для статического массива. Для инициализации данного контейнера нужно указать его тип и кол-во эл.
// std::array наследует от своего предка все сложности поиска и получения досутпа до элемента:
// Вставка не поддерживается, удаленине не поддерживается;
// Получить любой элемент: O(1);
// Поиск: O(n).

int main()
{
	std::array<int, 5> array = {0}; // инициализация по умолчанию.
	std::array<int, 5> array_1 {1, 2, 3, 4, 5};
	// Метод at() являеться аналогом оператора [], но имеет важную особенность, в отличии от оператор [] в случае обращения по неверному индексу
	// не вызывает UB, а выбрасывает исключение, то есть проверяет границы обращения к элементу. Возвращет элемент по индексу.
	std::cout << "Method At()" << std::endl;
	std::cout << array_1.at(1) << std::endl; // нет ошибки, все было верно
	try
	{
		std::cout << array_1.at(5) << std::endl;
	}
	catch(const std::exception& e) // std::out_of_range
	{
		std::cout << "Execption access by index" << std::endl;
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	// Метод Size() возвращает кол-во элементов в массиве, таким образом можно использовать его в ограничителе для циклов:
	std::cout << "Method Size()" << std::endl;
	std::cout << array_1.size() << std::endl;
	for (int i = 0; i < array_1.size(); i++)
	{
		std::cout << array_1[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	// Метод fill() заполняет все элементы некоторого массива указанным значением в передаваемом параметре.
	std::cout << "Method Fill()" << std::endl;
	array_1.fill(-5);

	for (auto& el : array_1)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl << std::endl;
	
	// Методы front() и метод back() позволяют получить доступ до первого и последнего элемента массива, соответсвенно. Эти два методы имеют спецификатор constexpr

	// constexpr — спецификатор типа, введённый в стандарт программирования языка C++11 для обозначения константных выражений,
	// которые могут быть вычислены во время компиляции кода. Фактически переносит затраты на вычисления со времени выполнения программы
	// на время компиляции. Таким образаом, при многоразовом запуске бинарного файла мы выйграем немного времени, т.к. затратили его во время компиляции.
	std::cout << "Methods Front() & Back():" << std::endl;
	array_1[0] = 99; array_1[4] = 1;
	std::cout << "Front: " << array_1.front() << " Back: " << array_1.back() << std::endl;
	std::cout << std::endl;

	// Метод empty() проверяет, пуст ли массив (всегда возвращает false, так как размер фиксированный).
	std::cout << "Method Empty()" << std::endl;
	std::cout << "Is array empty? " << (array_1.empty() ? "Yes" : "No") << std::endl;
	// Массивы нулевого размера допустимы, но их не следует разыменовывать (члены front , back и data ).
	std::array<int, 0> array_2;
	std::cout << "Is array empty? " << (array_1.empty() ? "Yes" : "No") << std::endl; // ? :)
	std::cout << std::endl;

	// Метод data() возвращает указатель на внутренний буфер данных массива.
	std::cout << "Method data()" << std::endl;
	int* p = array_1.data();
	std::cout << *(p + 4) << std::endl; // выводим последний элемент массива
	std::cout << std::endl;

	// std::array поддерживает итерриование и методы: begin(), end(), cbegin(), cend(), rbegin(), rend()
	// Метод swap() обменивает содержимое двух массивов одного типа и размера.
	std::cout << "Method swap()" << std::endl;
	std::array<int, 5> array_3 = {1, 2, 3, 4, 5};
	array_1.swap(array_3);

	for (auto& el : array_1)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl ;


	for (auto& el : array_3)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;

    int value_to_find = 3;

	// С помощью метода std::find можно найти элемент в std::array за линейное время
    auto it = std::find(array_1.begin(), array_1.end(), value_to_find);
    if (it != array_1.end()) {
        std::cout << "Element found at index: " << std::distance(array_1.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // С помощью std::binary_search - за логорифмическое. Бинарный поиск требует отсортированного массива
    bool found = std::binary_search(array_1.begin(), array_1.end(), value_to_find);

    if (found) {
        std::cout << "Element found" << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

	return 0;
}