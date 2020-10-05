#pragma once

#include <string>
#include <vector>

std::vector<int> convert_to_ip(std::vector <std::string> ip_string);

std::vector <std::string> split(const std::string &str, char d);

bool is_valid_ip_address(const std::string &str);

void sort_in_reverse_lexicographic_order(std::vector <std::vector<int>> &ip_pool);
