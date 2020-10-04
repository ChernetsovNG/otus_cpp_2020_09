#include "include/lib.h"

#include <string>
#include <vector>
#include <algorithm>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d) {
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool is_valid_ip_address(const std::string &str) {
    auto res = split(str, '.');
    if (res.size() != 4) {
        return false;
    }
    for (const auto &element : res) {
        if (!is_number(element)) {
            return false;
        }
        // число должно быть от 0 до 255
        int i = std::stoi(element);
        if (i < 0 || i > 255) {
            return false;
        }
    }
    return true;
}

void sort_in_reverse_lexicographic_order(std::vector<std::vector<std::string>> &ip_pool) {
    std::sort(ip_pool.begin(), ip_pool.end(),
              [](const std::vector<std::string> &ip1, const std::vector<std::string> &ip2) {
                  for (int i = 0; i < 4; ++i) {
                      int ip1_elem = std::stoi(ip1[i]);
                      int ip2_elem = std::stoi(ip2[i]);
                      if (ip1_elem == ip2_elem) {
                          continue;
                      } else {
                          return ip1_elem > ip2_elem;
                      }
                  }
                  return false;
              });
}
