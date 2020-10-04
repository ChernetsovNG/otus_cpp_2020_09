#include "lib.h"

#include <iostream>
#include <algorithm>

void print_ips(const std::vector<std::vector<std::string>> &ip_pool);

int main() {
    try {
        std::vector<std::vector<std::string>> ip_pool;

        for (std::string line; std::getline(std::cin, line);) {
            std::vector<std::string> v = split(line, '\t');
            auto elem = v.at(0);
            if (check_is_ip(elem)) {
                ip_pool.push_back(split(v.at(0), '.'));
            }
        }

        // сортируем адреса в обратном лексикографическом порядке
        sort_in_reverse_lexicographic_order(ip_pool);

        // выводим полный список адресов после сортировки
        print_ips(ip_pool);

        // Выводим список адресов, первый байт которых равен 1. Порядок сортировки не меняется
        std::vector<std::vector<std::string>> ip_pool_start_with_1;
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_start_with_1),
                     [](const std::vector<std::string> &i) { return std::stoi(i[0]) == 1; });
        print_ips(ip_pool_start_with_1);

        // Выводим список адресов, первый байт которых равен 46, а второй 70
        std::vector<std::vector<std::string>> ip_pool_start_with_46_and_70;
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_start_with_46_and_70),
                     [](const std::vector<std::string> &i) { return std::stoi(i[0]) == 46 && std::stoi(i[1]) == 70; });
        print_ips(ip_pool_start_with_46_and_70);

        // Выводим список адресов, любой байт которых равен 46
        std::vector<std::vector<std::string>> ip_pool_any_46;
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(ip_pool_any_46),
                     [](const std::vector<std::string> &i) {
                         return std::stoi(i[0]) == 46 || std::stoi(i[1]) == 46 || std::stoi(i[2]) == 46 ||
                                std::stoi(i[3]) == 46;
                     });
        print_ips(ip_pool_any_46);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

void print_ips(const std::vector<std::vector<std::string>> &ip_pool) {
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
