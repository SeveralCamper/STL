#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <array>
#include <vector>
#include <limits>
#include <cstring>
#include <iterator> 
#include <forward_list>

// std::iterator - структура, обеспечивающая доступ к элементам контенера. Дает возможность использовать единый подход для
// обращения к элементам разных типов контейнеров. Итераторы имеют только контейнеры, адаптеры контейнеров, такие как
// std::stack, std::queue и std::priority_queue итераторов не имеют.

// Итераторы ввода (input iterators)
// Итераторы вывода (output iterators)
// Однонаправленные итераторы (forward iterators)
// Двунаправленные итераторы (bidirectional iterators)
// Итераторы произвольного доступа (random access iterators)

int main()
{
	std::array<int, 5> array_1 {1, 2, 3, 4, 5};
	std::array<int, 5>::iterator array_1_iter_begin = array_1.begin(); // получаем итерратор, который указывает на первый элемент контейнера
	std::array<int, 5>::iterator array_1_iter_end = array_1.end(); // последний элемент контейнера
	std::cout << "Array iters:" << std::endl;
	// Поочередно выведем все элементы контейнера:
	for (array_1_iter_begin; array_1_iter_begin != array_1_iter_end; ++array_1_iter_begin)
	{
		std::cout << *array_1_iter_begin << " ";
	}
	std::cout << std::endl << std::endl;
	// Более локоничный вариант прохождения по контейниру с использованием итератора:
	for (auto& it : array_1)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl << std::endl;
	// Если нужно пройти по определенным элементам с ограничением снизу и/или  сверху
	for (auto it = array_1.begin() + 2; it != array_1.end() - 1; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	// К итераторам можно применять следующие операции:
	// *iter - получение элемента, на который указывает контейнер.
	// ++iter: перемещение итератора вперед для обращения к следующему элементу
	// --iter: перемещение итератора назад для обращения к предыдущему элементу. Итераторы контейнера forward_list не поддерживают операцию декремента.
	// iter1 == iter2: два итератора равны, если они указывают на один и тот же элемент
	// iter1 != iter2: два итератора не равны, если они указывают на разные элементы
	// iter + n: возвращает итератор, который смещен от итератора iter на n позиций вперед
	// iter - n: возвращает итератор, который смещен от итератора iter на n позиций назад
	// iter += n: перемещает итератор на n позиций вперед
	// iter -= n: перемещает итератор на n позиций назад
	// iter1 - iter2: возвращает количество позиций между итераторами iter1 и iter2
	// >, >=, <, <=: операции сравнения. Один итератор больше другого, если указывает на элемент, который ближе к концу

	// Есть контейнеры, которые не поддерживают некоторые типы операций: например итератор для std::array поддерживает операции --, -= и -:
	int i = 0;
	array_1_iter_begin = array_1.begin();
	array_1_iter_end = array_1.end();
	while (array_1_iter_begin != array_1_iter_end)
	{
		std::cout << i << std::endl;
		if (array_1_iter_begin == array_1_iter_end)
		{
			std::cout << "Это не выведеться, указатели уже равны :)" << std::endl;
		}
		else
		{
			std::cout << array_1_iter_begin << " != " << (array_1_iter_end) << std::endl;
		}
		--array_1_iter_end;
		i++;
	}
	std::cout << std::endl;
	// Но итераторы таких контейнеров как std::forward_list, std::unordered_set и std::unordered_map не поддерживают эти операторы:
	// forward_list не поддерживает как --, -= и -, так и операторы +, +=;
	std::forward_list<int> forward_list_1 {1, 2, 3, 4, 5};
	std::forward_list<int>::iterator forward_list_1_iter_begin = forward_list_1.begin();
	std::forward_list<int>::iterator forward_list_1_iter_end = forward_list_1.end();
	std::cout << "Forward list iters:" << std::endl;

	for (auto it = forward_list_1.begin(); it != forward_list_1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	// Отсутствие этих операторов легко объясняется логикой того, какой тип данных реализован этим контейнером - односвязный список. Соответсвнно, по нему
	// нельзя проходиться от конца в начало и нельзя перескакивать "ноды" списка. Таким образом мы получаем возможность использовать только инкремент;

	// Итераторы для типа std::list поддерживают операции инкремента и декремента, но не поддерживаются операции +=, -=, + и -. 
	// Те же ограничения имеют итераторы контейнеров std::map и std::set.

	// Операции +=, -=, +, -, <, <=, >, >= и <=> поддерживаются только итераторами произвольного доступа (итераторы контейнеров std::vector, array и deque)

	// Также есть возможность производить изменение данных с помощью итератора, т.к. по сути это указатель на какой-то элемент контейнера, 
	// но это невсегда допустимо:

	*forward_list_1_iter_begin = 6; // этот код отработает корректно
	// *forward_list_1_iter_end = 7; // данная же запись приведет к ошибке сегментирования памяти, т.к. методы end() у всех контейнеров возвращают не
	// указатель на последний элемент, а указатель на элемент следующий за последним. Это так называемая "позиция за концом" или "за пределами конца" списка.
	//  end() не может быть использован для доступа к содержимому списка напрямую, также как и у любого другого контейнера.
	for (auto& it : forward_list_1)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl << std::endl;

	std::vector<double> vector_1 {1.0, 2.0, 3.0, 4.0, 5.0};
	std::vector<double>::iterator vector_1_iter_begin = vector_1.begin();
	std::vector<double>::iterator vector_1_iter_end = vector_1.end();
	std::cout << "Vector iters:" << std::endl;

	// Для вектора эту запись можно обыграть подругому, т.к. iterator для контейнера std::vector поддерживает декремент:
	*(--vector_1_iter_end) = 10;
	std::cout << vector_1[4] << std::endl;
	std::cout << std::endl;

	// При добавлении или удалении элементов контейнера следует учитывать тот момент, что все текущие итераторы,
	// ссылки и указатели на его элементы станут недоступными. Когда вы добавляете или удаляете элементы из контейнера, это может привести к изменению
	// расположения элементов в памяти и даже к перераспределению всего внутреннего представления контейнера. В результате старые итераторы могут стать
	// недействительными, потому что они могут указывать на элементы, которые уже не существуют в новом внутреннем представлении контейнера.

    auto it = vector_1.begin() + 1;
    vector_1.push_back(6);
    // std::cout << *it << std::endl; // При попытке доступа к элементу через сохраненный итерратор, мы можем вызвать недопустимый доступ или непредсказуемое поведение

	// Если контейнер пресдавтялет константу, то обращться к его элементам можно только с помощью константного итератора (тип const_iterator).
	// Такой итератор позволяет считывать элементы, но не изменять их:

	const std::vector<int> vector_2 = {10, 9, 8, 7, 6, 5};
	for (auto& it : vector_2) // const_iterator
	{
		std::cout << it << " "; // допустимая работа с итератором
		// it = it + 1; // недопустимая работа с итератором
	}
	std::cout << std::endl << std::endl;

	// Также для получения константного итератора можно использовать cbegin() и cend()

	for (auto it = vector_2.cbegin(); it != vector_2.cend(); ++it)
	{
		std::cout << *it << " "; // допустимая работа с итератором
		// *it = *it + 1; // недопустимая работа с итератором
	}
	std::cout << std::endl << std::endl;

	// Стоит отметить, что для типов std::set (множество) и std::map (словарь) доступны только константные итераторы.

	// Реверсивные итераторы позволяют перебирать элементы контейнера в обратном направлении.
	// Для получения реверсивного итератора применяются функции rbegin() и rend(), а сам итератор представляет тип reverse_iterator:

    for (auto iter { vector_2.rbegin() }; iter != vector_2.rend(); ++iter) // код отрабатывает, т.к. реверсивный указатель создался автоматически
    {																	 // с квалификатором const
        std::cout << *iter << " ";
		// *iter += 2; // все еще не допустимое действие
    }
    std::cout << std::endl << std::endl;

	// Итераторы можно использовать и на обычных массивах:
	int data[]{4, 5, 6, 7, 8};
	auto iter = std::begin(data);
	auto end = std::end(data);
	std::cout << "Default array iters:" << std::endl;

	for (auto it { iter }; it != end; it++)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl << std::endl;


	// Теперь стоит поговорить о типах итерраторов, которые я описал в самом начале:
	// Итераторы ввода (input iterators)

	// Ввод. Входной итераторX может выполнять итерацию по последовательности с помощью ++ оператора и читать элемент в любое количество раз
	// с помощью * оператора. Вы можете сравнить входные итераторы с помощью == операторов и != операторов. После увеличения любой копии входного
	// итератора ни одна из других копий не может быть безопасно сравниваема, разыменовывается или увеличивается после этого.

	// Используем итератор ввода, например, для чтения значений из std::cin:

	std::cout << "Input iterators" << std::endl;
    std::cout << "Enter integers separated by spaces (enter any non-numeric character to complete): ";
    std::istream_iterator<int> input_begin(std::cin);
    std::istream_iterator<int> input_end;

    std::cout << "Numbers you entered: ";
    while (input_begin != input_end) {
        std::cout << *input_begin++ << " ";
    }
    std::cout << std::endl << std::endl;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Итераторы вывода (output iterators)

	// Вывод. Выходной итераторX может выполнять итерацию по последовательности с помощью ++ оператора и может записывать элемент только
	// один раз с помощью * оператора. 

	// С помощью итератора вывода выведем наш массив в std::cout:

	std::cout << "Output iterators" << std::endl;
    std::ostream_iterator<int> output_iterator(std::cout, " ");
	for (auto it { iter }; it != end; it++)
    {
        *output_iterator++ = *it;
    }
    std::cout << std::endl << std::endl;

	// Однонаправленные итераторы (forward iterators)

	// Однонаправленные итераторы представляют собой комбинацию итераторов ввода и вывода. Они позволяют нам как получать доступ к значениям,
	// так и изменять их. Например, такие итераторы используются в std::replace. Однонаправленные итераторы являются DefaultConstructible и могут
	// обращаться/разыменовывать одни и те же позиции несколько раз.

	std::cout << "Forward iterators" << std::endl;

    std::cout << "Original list: ";
    for (auto& val : forward_list_1) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    for (auto it = forward_list_1_iter_begin; it != forward_list_1_iter_end; ++it) {
        *it += 10;
    }

    std::cout << "Changed list: ";
    for (auto& val : forward_list_1) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

	// Фактически обычный вызов итерартора.

	// Двунаправленные итераторы (bidirectional iterators)

	// Двунаправленные итераторы подобны однонаправленным итераторам, но они могут быть еще и декрементированы, поэтому могут двигаться как вперед,
	// так и назад. std::reverse_copy использует такие итераторы, поскольку ему нужно и обращать значения контейнера (декрементировать),
	// и помещать результаты в новый контейнер один за другим (инкрементировать).

	std::cout << "Bidirectional iterators" << std::endl;

    std::list<int> list_1 = {1, 2, 3, 4, 5};

    std::cout << "Original list: ";
    for (auto& val : list_1) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    // Уменьшим каждый элемент на 1, начиная с конца списка
    auto it_list = --list_1.end(); // Перемещаем итератор на последний элемент
    while (it_list != list_1.begin()) {
        *it_list -= 1;
        --it_list;
    }
    *it_list -= 1; // Уменьшаем значение первого элемента

    std::cout << "Changed list: ";
    for (auto& val : list_1) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;	

	// Итераторы произвольного доступа (random access iterators)

	// Итераторы произвольного доступа могут делать все то же, что и двунаправленные итераторы. Кроме того, они могут не только инкрементироваться 
	// или декрементироваться, но и изменять свою позицию на любое значение. Другими словами, они поддерживают операторы + и -. Различные итераторы
	// произвольного доступа можно также сравнивать с помощью различных операторов сравнения (а не только с помощью равенства/неравенства).
	// Произвольный доступ означает, что к контейнерам, принимающим такие итераторы, можно просто обращаться с помощью оператора сдвига.

	std::cout << "Random access iterators" << std::endl;

    std::cout << "Original vector: ";
    for (auto& val : vector_1) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    auto it_vector = vector_1.begin() + 2; // свободно проходим на n по итератору
    for (; it_vector != vector_1.end(); ++it_vector) {
        *it_vector += 100;
    }

    std::cout << "Changed vector: ";
    for (auto& val : vector_1) {
        std::cout << val << " ";
    }
	std::cout << std::endl;

	return 0;
}