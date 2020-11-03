#include <iostream>
#include <map>

template<typename T>
struct Allocator {

    using value_type = T;

    Allocator() = default;

    ~Allocator() = default;

    T *allocate(std::size_t n) {
        std::cout << "allocate: [n = " << n << "]" << std::endl;
        auto p = std::malloc(n * sizeof(T));
        if (!p) throw std::bad_alloc();
        return reinterpret_cast<T *>(p);
    }

    void deallocate(T *p, std::size_t n) {
        std::cout << "deallocate: [n = " << n << "] " << std::endl;
        std::free(p);
    }
};

constexpr int factorial(const int n) {
    if (n < 0) {
        throw std::invalid_argument("bad factorial argument: " + std::to_string(n));
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    std::cout << "--- HW2 START ---" << std::endl;

    // создание экземпляра std::map<int, int>
    std::map<int, int> m1;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        m1.emplace(i, factorial(i));
    }

    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<>, Allocator<std::pair<const int, int>>> m2;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        m2.emplace(i, factorial(i));
    }

    std::cout << "--- HW2 END ---" << std::endl;
}
