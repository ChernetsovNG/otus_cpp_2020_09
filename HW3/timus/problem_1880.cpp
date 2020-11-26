#include <iostream>
#include <sstream>
#include <unordered_set>

int main() {
    std::string line;
    int i;

    // 1 участник
    std::getline(std::cin, line);
    int n1 = std::stoi(line);
    std::unordered_set<int> set1;
    set1.reserve(n1);

    std::getline(std::cin, line);
    std::stringstream ss1(line);
    while (ss1 >> i) {
        set1.insert(i);
    }

    // 2 участник
    std::getline(std::cin, line);
    int n2 = std::stoi(line);
    std::unordered_set<int> set2;
    set2.reserve(n2);

    std::getline(std::cin, line);
    std::stringstream ss2(line);
    while (ss2 >> i) {
        set2.insert(i);
    }

    // 3 участник
    std::getline(std::cin, line);
    int n3 = std::stoi(line);
    std::unordered_set<int> set3;
    set2.reserve(n3);

    std::getline(std::cin, line);
    std::stringstream ss3(line);
    while (ss3 >> i) {
        set3.insert(i);
    }

    // вычисляем ответ
    int count = 0;
    for (const auto &elem: set1) {
        if (set2.count(elem) > 0 && set3.count(elem) > 0) {
            count++;
        }
    }

    std::cout << count << std::endl;
}
