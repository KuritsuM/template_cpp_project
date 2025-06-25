//
// Created by kuritsumplus on 25.06.2025.
//

#include <boost/test/unit_test.hpp>

#include "../ip_filter.hpp"

BOOST_AUTO_TEST_SUITE(sort_ip)

BOOST_AUTO_TEST_CASE(test_sort_ip_CASE1_that_ip_sorted_decreasing) {
    const std::vector<std::string> init{ "192.168.0.1", "192.168.1.1", "192.168.2.1", "192.168.10.1", "225.0.0.1", "1.1.1.1"};

    const std::vector<std::string> expected{ "225.0.0.1", "192.168.10.1", "192.168.2.1", "192.168.1.1", "192.168.0.1", "1.1.1.11" };
    const std::vector<std::string> result = sort_ip_addresses(init);

    BOOST_CHECK_EQUAL_COLLECTIONS(
        expected.cbegin(), expected.cend(),
        result.cbegin(), result.cend()
    );
}

BOOST_AUTO_TEST_SUITE_END()
