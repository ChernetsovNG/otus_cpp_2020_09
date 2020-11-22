#include <iostream>
#include <map>
#include <vector>

#include "allocator.cpp"
#include "vector.cpp"

constexpr int factorial(const int n) {
    if (n < 0) {
        throw std::invalid_argument("bad factorial argument: " + std::to_string(n));
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void part1() {
    std::cout << "--- Part1 start ---" << std::endl;

    // создание экземпляра std::map<int, int>
    std::map<int, int> map;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        map.emplace(i, factorial(i));
    }

    // вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    std::cout << "Print map key value pairs" << std::endl;
    for (const auto&[key, value] : map) {
        std::cout << key << " " << value << std::endl;
    }

    std::cout << "--- Part1 end ---" << std::endl;
}

void part2() {
    std::cout << "--- Part2 start ---" << std::endl;

    std::vector<int, Allocator<int, 10>> v;

    // создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<>, Allocator<std::pair<const int, int>, 10>> map;

    // заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i <= 9; ++i) {
        map.emplace(i, factorial(i));
    }

    // вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    std::cout << "Print map key value pairs" << std::endl;
    for (const auto&[key, value] : map) {
        std::cout << key << " " << value << std::endl;
    }

    std::cout << "--- Part2 end ---" << std::endl;
}

void part3() {
    std::cout << "--- Part3 start ---" << std::endl;

    // создание экземпляра своего контейнера для хранения значений типа int
    MyVector<int> vector;

    // заполнение 10 элементами от 0 до 9
    for (int i = 0; i <= 9; ++i) {
        vector.push_back(i);
    }

    // вывод на экран всех значений, хранящихся в контейнере
    std::cout << "Print vector values" << std::endl;
    for (auto it = std::begin(vector); it != std::end(vector); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "--- Part3 end ---" << std::endl;
}

void part4() {
    std::cout << "--- Part4 start ---" << std::endl;

    // создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором, ограниченным 10 элементами
    // (за счёт расширения массива в векторе в 2 раза нужно аллоцировать бОльший блок памяти, иначе её не хватит для расширения)
    MyVector<int, Allocator<int, 24>> vector;

    // заполнение 10 элементами от 0 до 9
    for (int i = 0; i <= 9; ++i) {
        vector.push_back(i);
    }

    // вывод на экран всех значений, хранящихся в контейнере
    std::cout << "Print vector values" << std::endl;
    for (auto it = std::begin(vector); it != std::end(vector); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "--- Part4 end ---" << std::endl;
}

int main() {
    std::cout << "--- HW2 START ---" << std::endl;

    // 1. std::map со стандартным аллокатором
    part1();

    // 2. std::map с custom аллокатором
    part2();

    // 3. свой контейнер со стандартным аллокатором
    part3();

    // 4. свой контейнер с custom аллокатором
    part4();

    std::cout << "--- HW2 END ---" << std::endl;
}
