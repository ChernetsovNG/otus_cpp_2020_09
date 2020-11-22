#include <vector>
#include <tuple>

#include "print_ip.cpp"

int main() {
    long integer_ip = 3221226219;
    print_ip(integer_ip);

    std::string string{"127.0.0.1"};
    print_ip(string);

    std::vector<int> vector{225, 121, 15, 8};
    print_ip(vector);

    std::list<int> list{192, 15, 0, 4};
    print_ip(list);

    std::tuple<int> t2{10};

    //print_ip(t2);

    return 0;
}
