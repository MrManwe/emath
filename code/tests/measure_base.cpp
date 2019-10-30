#include "pch.h"
#include "emath/measure.h"

struct emathUnitFixture
{
	
};

using namespace emath;



typedef boost::mpl::list <int, float, double>::type Types;


BOOST_AUTO_TEST_SUITE(unit_base)

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_static_structure, Type, Types, emathUnitFixture)
{ 
	
}

BOOST_FIXTURE_TEST_CASE(test_creation_01, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	float meters = dist1.get<si::meters>();
	BOOST_TEST_REQUIRE(meters == 4000.0f);
}

BOOST_FIXTURE_TEST_CASE(test_sum_01, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	si::distance dist2 = si::meters(400.0f);
	si::distance dist3 = dist1 + dist2;
	float meters = dist3.get<si::meters>();
	BOOST_TEST_REQUIRE(meters == 4400.0f);
}

BOOST_FIXTURE_TEST_CASE(test_diff_01, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	si::distance dist2 = si::meters(400.0f);
	si::distance dist3 = dist1 - dist2;
	float meters = dist3.get<si::meters>();
	BOOST_TEST_REQUIRE(meters == 3600.0f);
}

BOOST_FIXTURE_TEST_CASE(test_mult_01, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	si::distance dist2 = si::meters(400.0f);
	si::surface surf1 = dist1 * dist2;
	float meters2 = surf1.get<si::kilometers2>();
	BOOST_TEST_REQUIRE(meters2 == 4000.f * 400.f / 1000000.f);
}

BOOST_FIXTURE_TEST_CASE(test_mult_02, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	si::surface surf1 = dist1 * si::meters(400.0f);
	float meters2 = surf1.get<si::kilometers2>();
	BOOST_TEST_REQUIRE(meters2 == 4000.f * 400.f / 1000000.f);
}

BOOST_FIXTURE_TEST_CASE(test_mult_03, emathUnitFixture)
{
	si::distance dist2 = si::meters(400.0f);
	si::surface surf1 = si::kilometers(4.0f) * dist2;
	float meters2 = surf1.get<si::kilometers2>();
	BOOST_TEST_REQUIRE(meters2 == 4000.f * 400.f / 1000000.f);
}

BOOST_FIXTURE_TEST_CASE(test_mult_04, emathUnitFixture)
{
	si::surface surf1 = si::kilometers(4.0f) * si::meters(400.0f);
	float meters2 = surf1.get<si::kilometers2>();
	BOOST_TEST_REQUIRE(meters2 == 4000.f * 400.f / 1000000.f);
}

BOOST_FIXTURE_TEST_CASE(test_div_01, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(4.0f);
	si::distance dist2 = si::meters(400.0f);
	si::scalar scalar = dist1 / dist2;
	float meters2 = scalar.get<si::units>();
	BOOST_TEST_REQUIRE(meters2 == (4000.f / 400.f));
}

BOOST_FIXTURE_TEST_CASE(test_div_02, emathUnitFixture)
{
	si::distance dist1 = si::kilometers(180.0f);
	si::time dist2 = si::hours(2.0f);
	si::speed scalar = dist1 / dist2;
	float meters2 = scalar.get<si::kilometers_hour>();
	BOOST_TEST_REQUIRE(meters2 == 90.f);
}

BOOST_FIXTURE_TEST_CASE(test_div_03, emathUnitFixture)
{
	si::distance dist1 = si::meters(8.0f);
	si::speed surf1 = dist1 / si::seconds(2.0f);
	float meters2 = surf1.get<si::meters_second>();
	BOOST_TEST_REQUIRE(meters2 == 4.f);
}

BOOST_FIXTURE_TEST_CASE(test_div_04, emathUnitFixture)
{
	si::time time = si::seconds(2);
	si::speed surf1 = si::meters(8.0f) / time;
	float meters2 = surf1.get<si::meters_second>();
	BOOST_TEST_REQUIRE(meters2 == 4.0f);
}

BOOST_FIXTURE_TEST_CASE(test_div_05, emathUnitFixture)
{
	si::speed surf1 = si::meters(8.0f) / si::seconds(2.0f);
	float meters2 = surf1.get<si::meters_second>();
	BOOST_TEST_REQUIRE(meters2 == 4.0f);
}

BOOST_AUTO_TEST_SUITE_END()