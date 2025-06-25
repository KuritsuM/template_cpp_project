#define BOOST_TEST_MODULE TemplateProjectTests

#include "../EmptyLibrary.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_nothing_func)

BOOST_AUTO_TEST_CASE(test_nothing) {
    BOOST_CHECK( Library::EmptyLibrary::do_nothing() == 1 );
}

BOOST_AUTO_TEST_SUITE_END()
