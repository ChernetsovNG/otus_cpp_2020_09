#include <iostream>
#include <vector>

int squares_count(std::string &pos) {
    char letter = pos[0];
    char digit = pos[1];
    if (letter >= 'c' && letter <= 'f' && digit >= '3' && digit <= '6') {
        return 8;
    } else if (
            (letter >= 'c' && letter <= 'f' && digit == '2') ||
            (letter >= 'c' && letter <= 'f' && digit == '7') ||
            (letter == 'b' && digit >= '3' && digit <= '6') ||
            (letter == 'g' && digit >= '3' && digit <= '6')) {
        return 6;
    } else if (
            (letter >= 'c' && letter <= 'f' && digit == '1') ||
            (letter >= 'c' && letter <= 'f' && digit == '8') ||
            (letter == 'a' && digit >= '3' && digit <= '6') ||
            (letter == 'h' && digit >= '3' && digit <= '6') ||
            (letter == 'b' && digit == '2') ||
            (letter == 'g' && digit == '2') ||
            (letter == 'b' && digit == '7') ||
            (letter == 'g' && digit == '7')) {
        return 4;
    } else if (
            (letter == 'b' && digit == '1') ||
            (letter == 'g' && digit == '1') ||
            (letter == 'a' && digit == '2') ||
            (letter == 'h' && digit == '2') ||
            (letter == 'a' && digit == '7') ||
            (letter == 'h' && digit == '7') ||
            (letter == 'b' && digit == '8') ||
            (letter == 'g' && digit == '8')) {
        return 3;
    } else if (
            (letter == 'a' && digit == '1') ||
            (letter == 'h' && digit == '1') ||
            (letter == 'a' && digit == '8') ||
            (letter == 'h' && digit == '8')) {
        return 2;
    }
    return 0;
}

int main() {
    int N;
    std::vector<int> v;

    std::string line;

    std::getline(std::cin, line);
    N = std::stoi(line);

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        v.push_back(squares_count(line));
    }

    for (auto element : v) {
        std::cout << element << std::endl;
    }
}
