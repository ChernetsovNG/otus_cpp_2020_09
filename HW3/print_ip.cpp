#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_ip(T ip) {
    /*
      Адрес может быть представлен в виде произвольного целочисленного типа. Представление не зависит от знака типа.
      Выводить побайтово, начиная со старшего байта, с символом `.` (символ точки) в качестве разделителя
     */
    unsigned char b1, b2, b3, b4;
    b1 = (ip & 0xFF);
    b2 = ((ip >> 8) & 0xFF);
    b3 = ((ip >> 16) & 0xFF);
    b4 = ((ip >> 24) & 0xFF);
    std::cout << (int) b4 << "." << (int) b3 << "." << (int) b2 << "." << (int) b1 << std::endl;
}

template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
print_ip(T ip) {
    /*
      Адрес может быть представлен в виде строки. Выводится как есть
     */
    std::cout << ip << std::endl;
}
