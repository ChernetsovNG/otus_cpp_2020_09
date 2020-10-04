#pragma once

#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char d);

bool check_is_ip(const std::string &str);

void sort_in_reverse_lexicographic_order(std::vector<std::vector<std::string>> &ip_pool);
