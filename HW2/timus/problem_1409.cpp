#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int sum = a + b;

    int a1 = sum - a - 1;
    int b1 = sum - b - 1;

    std::cout << a1 << " " << b1 << std::endl;
}
