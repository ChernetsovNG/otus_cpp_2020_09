#include <iostream>

int main() {
    int x = 100, y = 200;

    auto closure = [x = 101](int a, int b) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return a + b + x;
    };
    std::cout << closure(13, 15) << std::endl;

    auto closure2 = [=](int a, int b) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return a + b + x + y;
    };
    std::cout << closure2(13, 15) << std::endl;
}
