#include <iostream>
#include <string>

int main() {
    std::string code1, code2;
    int c1, c2;

    std::getline(std::cin, code1);
    std::getline(std::cin, code2);

    c1 = std::stoi(code1);
    c2 = std::stoi(code2);

    std::string result = "no";
    for (int i = 0; i < 10000; ++i) {
        // i - код, пробуемый вором, и номер дня; чётные дни - первый замок, нечётные дни - второй замок
        if ((i % 2 == 0 && i == c1) || (i == c2)) {
            result = "yes";
            break;
        }
    }

    std::cout << result << std::endl;
}
