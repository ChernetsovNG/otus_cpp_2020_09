#include "include/lib.h"

#include <iostream>
#include <algorithm>

std::vector <std::vector<int>> read_ips();

void print_ips_start_from_1(std::vector <std::vector<int>> &ip_pool);

void print_ips_start_from_46_and_70(std::vector <std::vector<int>> &ip_pool);

void print_ips_any_byte_46(std::vector <std::vector<int>> &ip_pool);

void print_ips(const std::vector <std::vector<int>> &ip_pool);

int main() {
    try {
        // читаем список ip-адресов из потока ввода
        std::vector <std::vector<int>> ip_pool = read_ips();

        // сортируем адреса в обратном лексикографическом порядке
        sort_in_reverse_lexicographic_order(ip_pool);

        // выводим полный список адресов после сортировки
        print_ips(ip_pool);

        // Выводим список адресов, первый байт которых равен 1. Порядок сортировки не меняется
        print_ips_start_from_1(ip_pool);

        // Выводим список адресов, первый байт которых равен 46, а второй 70
        print_ips_start_from_46_and_70(ip_pool);

        // Выводим список адресов, любой байт которых равен 46
        print_ips_any_byte_46(ip_pool);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

std::vector <std::vector<int>> read_ips() {
    std::vector <std::vector<int>> ip_pool;
    for (std::string line; std::getline(std::cin, line);) {
        std::vector <std::string> v = split(line, '\t');
        auto elem = v.at(0);
        if (is_valid_ip_address(elem)) {
            auto ip = convert_to_ip(split(elem, '.'));
            ip_pool.push_back(ip);
        }
    }
    return ip_pool;
}

void print_ips_start_from_1(std::vector <std::vector<int>> &ip_pool) {
    std::vector <std::vector<int>> ip_pool_start_from_1;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_start_from_1),
                 [](const std::vector<int> &i) { return i[0] == 1; });
    print_ips(ip_pool_start_from_1);
}

void print_ips_start_from_46_and_70(std::vector <std::vector<int>> &ip_pool) {
    std::vector <std::vector<int>> ip_pool_start_from_46_and_70;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_start_from_46_and_70),
                 [](const std::vector<int> &i) { return i[0] == 46 && i[1] == 70; });
    print_ips(ip_pool_start_from_46_and_70);
}

void print_ips_any_byte_46(std::vector <std::vector<int>> &ip_pool) {
    std::vector <std::vector<int>> ip_pool_any_46;
    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_any_46),
                 [](const std::vector<int> &i) {
                     return i[0] == 46 || i[1] == 46 || i[2] == 46 || i[3] == 46;
                 });
    print_ips(ip_pool_any_46);
}

void print_ips(const std::vector <std::vector<int>> &ip_pool) {
    for (const auto &ip : ip_pool) {
        for (auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part) {
            if (ip_part != ip.cbegin()) {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}
