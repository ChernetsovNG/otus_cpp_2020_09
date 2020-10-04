#define BOOST_TEST_MODULE test_check_ip

#include "../src/include/lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_check_ip)

    BOOST_AUTO_TEST_CASE(good_ip_1) {
        bool res = is_valid_ip_address("119.42.115.97");
        BOOST_CHECK(res == true);
    }

    BOOST_AUTO_TEST_CASE(bad_ip_1) {
        bool res = is_valid_ip_address("119.42.115");
        BOOST_CHECK(res == false);
    }

    BOOST_AUTO_TEST_CASE(bad_ip_2) {
        bool res = is_valid_ip_address("abcdef");
        BOOST_CHECK(res == false);
    }

    BOOST_AUTO_TEST_CASE(bad_ip_3) {
        bool res = is_valid_ip_address("127.16.32.not");
        BOOST_CHECK(res == false);
    }

    BOOST_AUTO_TEST_CASE(bad_ip_4) {
        bool res = is_valid_ip_address("127.16.32.722");
        BOOST_CHECK(res == false);
    }

BOOST_AUTO_TEST_SUITE_END()
