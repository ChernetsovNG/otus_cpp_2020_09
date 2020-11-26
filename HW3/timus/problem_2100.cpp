#include <iostream>
#include <cmath>

int main() {
    int n, k, ans;
    std::cin >> n >> k;

    if (n <= k) ans = 2;
    else ans = ceil(2.0 * n / k);

    std::cout << ans << std::endl;
}
