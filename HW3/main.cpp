#include <vector>
#include <tuple>

#include "print_ip.cpp"

void print_line(const char *line = "") {
    std::cout << line << std::endl;
}

int main() {
    // Печать адреса как `char(-1)`
    char char_ip = -1;
    print_line("char");
    print_ip(char_ip);
    print_line();

    // Печать адреса как `short(0)`
    short short_ip = 0;
    print_line("short");
    print_ip(short_ip);
    print_line();

    // Печать адреса как `int(2130706433)`
    int int_ip = 2130706433;
    print_line("int");
    print_ip(int_ip);
    print_line();

    // Печать адреса как `long(8875824491850138409)`
    auto long_ip = 8875824491850138409;
    print_line("long");
    print_ip(long_ip);
    print_line();

    // Печать адреса как `std::string`
    std::string string{"127.1.2.3"};
    print_line("string");
    print_ip(string);
    print_line();

    // Печать адреса как `std::vector`
    std::vector<int> vector{225, 121, 15, 8};
    print_line("vector");
    print_ip(vector);
    print_line();

    // Печать адреса как `std::list`
    std::list<int> list{192, 15, 0, 4};
    print_line("list");
    print_ip(list);
    print_line();

    // Опционально. Печать адреса как `std::tuple`
    std::tuple<int, int, int, int> t2{117, 218, 33, 10};
    print_line("tuple");
    print_ip(t2);
    print_line();

    return 0;
}
