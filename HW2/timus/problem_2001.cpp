#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line1, line2, line3;
    int a1, a2, a3, b1, b2, b3, p1, p2, m1, m2;

    std::getline(std::cin, line1);
    std::getline(std::cin, line2);
    std::getline(std::cin, line3);

    std::istringstream iss1(line1), iss2(line2), iss3(line3);
    iss1 >> a1 >> b1;
    iss2 >> a2 >> b2;
    iss3 >> a3 >> b3;

    // веса корзин
    p1 = a3;
    p2 = b2;

    // веса ягод
    m1 = a1 - p1;
    m2 = b1 - p2;

    std::cout << m1 << " " << m2 << std::endl;
}
