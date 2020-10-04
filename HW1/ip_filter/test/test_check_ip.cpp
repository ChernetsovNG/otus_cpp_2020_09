#define BOOST_TEST_MODULE test_check_ip

#include "../ip_filter.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_check_ip)

    BOOST_AUTO_TEST_CASE(good_ip_1) {
        bool res = check_ip("119.42.115.97");
        BOOST_CHECK(res == true);
    }

BOOST_AUTO_TEST_SUITE_END()
