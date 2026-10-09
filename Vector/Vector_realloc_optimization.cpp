#include <iostream>
#include <vector>
#include <utility>

// Вариант 1: Обычный объект (без конструктора перемещения)
struct OnlyCopyable {
    int id;
    OnlyCopyable(int id) : id(id) {}
    
    // Конструктор копирования
    OnlyCopyable(const OnlyCopyable& other) {
        std::cout << "[OnlyCopyable] Вызван конструктор КОПИРОВАНИЯ для id: " << other.id << "\n";
        id = other.id;
    }
};

// Вариант 2: Перемещение определено БЕЗ noexcept
struct MoveWithoutNoexcept {
    int id;
    MoveWithoutNoexcept(int id) : id(id) {}

    MoveWithoutNoexcept(const MoveWithoutNoexcept& other) {
        std::cout << "[WithoutNoexcept] Вызван конструктор КОПИРОВАНИЯ для id: " << other.id << "\n";
        id = other.id;
    }

    // Конструктор перемещения БЕЗ noexcept
    MoveWithoutNoexcept(MoveWithoutNoexcept&& other) {
        std::cout << "[WithoutNoexcept] Вызван конструктор ПЕРЕМЕЩЕНИЯ для id: " << other.id << "\n";
        id = other.id;
    }
};

// Вариант 3: Перемещение определено С noexcept
struct MoveWithNoexcept {
    int id;
    MoveWithNoexcept(int id) : id(id) {}

    MoveWithNoexcept(const MoveWithNoexcept& other) {
        std::cout << "[WithNoexcept] Вызван конструктор КОПИРОВАНИЯ для id: " << other.id << "\n";
        id = other.id;
    }

    // Конструктор перемещения С noexcept
    MoveWithNoexcept(MoveWithNoexcept&& other) noexcept {
        std::cout << "[WithNoexcept] Вызван конструктор ПЕРЕМЕЩЕНИЯ для id: " << other.id << "\n";
        id = other.id;
    }
};

template <typename T>
void test_reallocation(const char* test_name) {
    std::cout << "\n--- Тест: " << test_name << " ---\n";
    std::vector<T> vec;
    
    std::cout << "Добавляем 1-й элемент...\n";
    vec.emplace_back(1); 
    
    std::cout << "Добавляем 2-й элемент (сейчас сработает реаллокация для 1-го)...\n";
    vec.emplace_back(2); 
}

int main() {
    test_reallocation<OnlyCopyable>("Только копирование");
    test_reallocation<MoveWithoutNoexcept>("Перемещение без noexcept");
    test_reallocation<MoveWithNoexcept>("Перемещение с noexcept");
    return 0;
}

