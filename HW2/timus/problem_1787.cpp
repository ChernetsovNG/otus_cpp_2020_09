#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line1;
    std::string line2;

    int k, n, an;

    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    std::istringstream iss1(line1), iss2(line2);
    iss1 >> k >> n;

    std::vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        iss2 >> an;
        a.push_back(an);
    }

    int buf = a[0];
    for (int i = 1; i < n; ++i) {
        buf -= std::min(buf, k);
        buf += a[i];
    }
    buf -= k;
    if (buf < 0) buf = 0;

    std::cout << buf << std::endl;
}
