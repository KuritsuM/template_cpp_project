#define BOOST_TEST_MODULE test_nothing_func

#include "EmptyLibrary.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_nothing_func)

BOOST_AUTO_TEST_CASE(test_nothing) {
    BOOST_CHECK( Library::EmptyLibrary::do_nothing() == 0 );
}

BOOST_AUTO_TEST_SUITE_END()
