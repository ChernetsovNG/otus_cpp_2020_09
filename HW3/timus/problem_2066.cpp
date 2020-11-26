#include <iostream>

int min_variant(int v1, int v2, int v3) {
    int x1 = v1 + v2 + v3;
    int x2 = v1 + v2 - v3;
    int x3 = v1 - v2 + v3;
    int x4 = v1 - v2 - v3;
    int x5 = v1 + v2 * v3;
    int x6 = v1 * v2 + v3;
    int x7 = v1 * v2 * v3;
    int x8 = v1 - v2 * v3;
    int x9 = v1 * v2 - v3;

    int min = x1;
    if (x2 < min) min = x2;
    if (x3 < min) min = x3;
    if (x4 < min) min = x4;
    if (x5 < min) min = x5;
    if (x6 < min) min = x6;
    if (x7 < min) min = x7;
    if (x8 < min) min = x8;
    if (x9 < min) min = x9;

    return min;
}

int main() {
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    int x1 = min_variant(a, b, c);
    int x2 = min_variant(a, c, b);
    int x3 = min_variant(b, a, c);
    int x4 = min_variant(b, c, a);
    int x5 = min_variant(c, a, b);
    int x6 = min_variant(c, b, a);

    int min = x1;
    if (x2 < min) min = x2;
    if (x3 < min) min = x3;
    if (x4 < min) min = x4;
    if (x5 < min) min = x5;
    if (x6 < min) min = x6;

    std::cout << min << std::endl;
}
