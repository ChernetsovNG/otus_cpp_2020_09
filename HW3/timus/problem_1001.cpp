#include <iostream>
#include <cmath>
#include <vector>

int main() {
    double n;
    std::vector<double> v;

    while (std::cin >> n) {
        v.push_back(n);
    }

    for (unsigned long long i = v.size() - 1; i >= 0; i--) {
        printf("%.4f\n", sqrt(v[i]));
    }
}
