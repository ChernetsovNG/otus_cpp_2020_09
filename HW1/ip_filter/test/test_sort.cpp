#define BOOST_TEST_MODULE test_sort

#include "../src/include/lib.h"

#include <string>
#include <vector>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_sort)

BOOST_AUTO_TEST_CASE(sort_ips_1) {
        std::vector < std::vector < int >> ip_pool;
        ip_pool.push_back(convert_to_ip(split("1.1.1.1", '.')));
        ip_pool.push_back(convert_to_ip(split("1.2.1.1", '.')));
        ip_pool.push_back(convert_to_ip(split("1.10.1.1", '.')));

        sort_in_reverse_lexicographic_order(ip_pool);

        std::vector<std::vector<int>> expected;
        expected.push_back(convert_to_ip(split("1.10.1.1", '.')));
        expected.push_back(convert_to_ip(split("1.2.1.1", '.')));
        expected.push_back(convert_to_ip(split("1.1.1.1", '.')));

        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[0].begin(), ip_pool[0].end(),
        expected[0].begin(), expected[0].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[1].begin(), ip_pool[1].end(),
        expected[1].begin(), expected[1].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[2].begin(), ip_pool[2].end(),
        expected[2].begin(), expected[2].end());
}

BOOST_AUTO_TEST_CASE(sort_ips_2) {
        std::vector < std::vector < int >> ip_pool;
        ip_pool.push_back(convert_to_ip(split("1.1.1.1", '.')));
        ip_pool.push_back(convert_to_ip(split("2.1.1.1", '.')));
        ip_pool.push_back(convert_to_ip(split("10.1.1.1", '.')));

        sort_in_reverse_lexicographic_order(ip_pool);

        std::vector<std::vector<int>> expected;
        expected.push_back(convert_to_ip(split("10.1.1.1", '.')));
        expected.push_back(convert_to_ip(split("2.1.1.1", '.')));
        expected.push_back(convert_to_ip(split("1.1.1.1", '.')));

        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[0].begin(), ip_pool[0].end(),
        expected[0].begin(), expected[0].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[1].begin(), ip_pool[1].end(),
        expected[1].begin(), expected[1].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[2].begin(), ip_pool[2].end(),
        expected[2].begin(), expected[2].end());
}

BOOST_AUTO_TEST_CASE(sort_ips_3) {
        std::vector < std::vector < int >> ip_pool;
        ip_pool.push_back(convert_to_ip(split("113.162.145.156", '.')));
        ip_pool.push_back(convert_to_ip(split("157.39.22.224", '.')));
        ip_pool.push_back(convert_to_ip(split("79.180.73.190", '.')));

        sort_in_reverse_lexicographic_order(ip_pool);

        std::vector<std::vector<int>> expected;
        expected.push_back(convert_to_ip(split("157.39.22.224", '.')));
        expected.push_back(convert_to_ip(split("113.162.145.156", '.')));
        expected.push_back(convert_to_ip(split("79.180.73.190", '.')));

        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[0].begin(), ip_pool[0].end(),
        expected[0].begin(), expected[0].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[1].begin(), ip_pool[1].end(),
        expected[1].begin(), expected[1].end());
        BOOST_CHECK_EQUAL_COLLECTIONS(ip_pool[2].begin(), ip_pool[2].end(),
        expected[2].begin(), expected[2].end());
}

BOOST_AUTO_TEST_SUITE_END()
