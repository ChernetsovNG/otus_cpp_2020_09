#include <iostream>
#include <string>

int get_count(std::string &line) {
    if (line.find("+one") != std::string::npos) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    int n;

    std::string line;

    std::getline(std::cin, line);
    n = std::stoi(line);

    int count = 2;  // Маршалл и Лили
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        count += get_count(line);
    }

    int sum;
    if (count == 13) {
        sum = 1400;
    } else {
        sum = 100 * count;
    }

    std::cout << sum << std::endl;
}
