#include "pch.h"
#include <string>

#define BOOST_TEST_MODULE OclTool
#include <boost/test/included/unit_test.hpp>

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	return 0;
}


int main(int argc, char** argv)
{
	int result = boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
	return result;
}
