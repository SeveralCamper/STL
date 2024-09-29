#include <iostream>
#include <bitset>

// std::bitset - контейнер, который предназначен для хранения набора битов и выполнения различных операций над ними.
// Он предоставляет удобные методы для работы с битовыми последовательностями, что может быть полезно для задач, связанных с побитовыми операциями,
// например, в криптографии, сетевом программировании или сжатии данных.

// Имеет фиксированнй размер, соответсвенно, не имеeт времени добавления и удаления
// Доступ к битам (operator[], test): O(1)
// Поиск: искать тут нечего :)

int main() {
    // Создание битового множества размером 8 бит
    std::bitset<8> bs1;
    std::bitset<8> bs2(42); // 42 в бинарном виде: 00101010
    std::bitset<8> bs3(std::string("1100")); // 00001100

    // Установка, сброс и переключение битов
    bs1.set(1); // 00000010
    bs1.set();  // 11111111
    bs1.reset(1); // 11111101
    bs1.reset();  // 00000000
    bs1.flip(0); // 00000001
    bs1.flip();  // 11111110

    // Доступ к битам и проверка состояния
    bool bit = bs1.test(1); // true
    std::cout << "Bit at position 1: " << bit << std::endl;

    bool all_bits = bs1.all(); // false
    bool any_bit = bs1.any();  // true
    bool no_bits = bs1.none(); // false
    std::size_t count = bs1.count(); // 7

    std::cout << "All bits set: " << all_bits << std::endl;
    std::cout << "Any bit set: " << any_bit << std::endl;
    std::cout << "No bits set: " << no_bits << std::endl;
    std::cout << "Count of bits set to 1: " << count << std::endl;

    // Конвертация
    std::string bit_string = bs1.to_string(); // "11111110"
    unsigned long bit_ulong = bs1.to_ulong(); // 254

    std::cout << "Bitset as string: " << bit_string << std::endl;
    std::cout << "Bitset as unsigned long: " << bit_ulong << std::endl;

    return 0;
}