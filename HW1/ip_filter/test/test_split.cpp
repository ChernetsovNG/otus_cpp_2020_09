#define BOOST_TEST_MODULE test_split

#include "../src/include/lib.h"

#include <string>
#include <vector>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_split)

    // ("",  '.') -> [""]
    BOOST_AUTO_TEST_CASE(split_empty_string) {
        std::vector<std::string> res = split("", '.');
        std::vector<std::string> expected{""};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

    // ("11", '.') -> ["11"]
    BOOST_AUTO_TEST_CASE(split_one_element_string) {
        std::vector<std::string> res = split("11", '.');
        std::vector<std::string> expected{"11"};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

    // ("..", '.') -> ["", "", ""]
    BOOST_AUTO_TEST_CASE(split_points_string) {
        std::vector<std::string> res = split("..", '.');
        std::vector<std::string> expected{"", "", ""};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

    // ("11.", '.') -> ["11", ""]
    BOOST_AUTO_TEST_CASE(split_one_element_with_next_point_string) {
        std::vector<std::string> res = split("11.", '.');
        std::vector<std::string> expected{"11", ""};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

    // (".11", '.') -> ["", "11"]
    BOOST_AUTO_TEST_CASE(split_one_element_with_previous_point_string) {
        std::vector<std::string> res = split(".11", '.');
        std::vector<std::string> expected{"", "11"};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

    // ("11.22", '.') -> ["11", "22"]
    BOOST_AUTO_TEST_CASE(split_two_elements_string) {
        std::vector<std::string> res = split("11.22", '.');
        std::vector<std::string> expected{"11", "22"};

        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      expected.begin(), expected.end());
    }

BOOST_AUTO_TEST_SUITE_END()
