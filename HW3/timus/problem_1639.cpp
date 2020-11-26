#include <iostream>

int main() {
    int m, n;
    std::cin >> m >> n;
    int square = m * n;
    std::cout << (square % 2 == 0 ? "[:=[first]" : "[second]=:]") << std::endl;
}
