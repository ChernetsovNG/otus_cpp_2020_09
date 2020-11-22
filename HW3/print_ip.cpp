#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

/*
  Адрес может быть представлен в виде произвольного целочисленного типа. Представление не зависит от знака типа.
  Выводить побайтово, начиная со старшего байта, с символом `.` (символ точки) в качестве разделителя
 */
template<typename T>
typename std::enable_if_t<std::is_integral_v<T>, void>
print_ip(T ip) {
    unsigned char b1, b2, b3, b4;
    b1 = (ip & 0xFF);
    b2 = ((ip >> 8) & 0xFF);
    b3 = ((ip >> 16) & 0xFF);
    b4 = ((ip >> 24) & 0xFF);
    std::cout << (int) b4 << "." << (int) b3 << "." << (int) b2 << "." << (int) b1 << std::endl;
}

/*
  Адрес может быть представлен в виде строки. Выводится как есть
 */
template<typename T>
typename std::enable_if_t<std::is_same_v<T, std::string>, void>
print_ip(T ip) {
    std::cout << ip << std::endl;
}

/*
  Адрес может быть представлен в виде контейнеров `std::list`, `std::vector`. Выводится содержимое контейнера
  поэлементно и разделяется `.` (одним символом точка)
 */
template<typename T>
void print_ip(std::vector<T> ip) {
    for (int i = 0; i < 3; ++i) {
        std::cout << ip[i] << ".";
    }
    std::cout << ip[3] << std::endl;
}

template<typename T>
void print_ip(std::list<T> ip) {
    auto it = std::begin(ip);
    if (it != std::end(ip))
        do {
            std::cout << *it;
            if (++it == std::end(ip)) break;
            std::cout << ".";
        } while (true);
    std::cout << std::endl;
}

/*
  Опционально адрес может быть представлен в виде `std::tuple` при условии, что все типы одинаковы. Выводится
  содержимое поэлементно и разделяется `.` (одним символом точка)
 */
/*template<typename T, typename... U>
typename std::enable_if_t<std::is_same_v<T, std::tuple<U...>> && std::is_integral_v<U>, void>
print_ip(T ip) {
    std::cout << "tuple" << std::endl;
}*/
