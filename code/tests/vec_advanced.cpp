#include "pch.h"
#include "emath/vec.h"
#include "emath/measure.h"

struct emathAdvancedeVec
{

};

using namespace emath;

BOOST_AUTO_TEST_SUITE(vec_advanced)

BOOST_FIXTURE_TEST_CASE(test_creation_01, emathAdvancedeVec)
{
	//vec<3, si::distance> v;
	//vec<3, si::distance> v2 = vec<3, si::distance>(si::meters(2.0f), si::kilometers(2.0f), si::meters(12.0f));

}

BOOST_FIXTURE_TEST_CASE(test_type_mult_01, emathAdvancedeVec)
{
	vec<3, si::distance> v = vec<3, si::distance>(si::meters(2.0f), si::meters(2.0f), si::meters(2.0f));
	vec<3, si::surface> result = v * si::meters(2.0f);

	for (size_t i = 0; i < 3; ++i)
	{
		BOOST_TEST_REQUIRE(result[i].get<si::meters2>() == 4.0f);
	}
}

BOOST_FIXTURE_TEST_CASE(test_type_mult_02, emathAdvancedeVec)
{
	vec<3, si::distance> v = vec<3, si::distance>(si::meters(2.0f), si::meters(2.0f), si::meters(2.0f));
	vec<3, si::surface> result = si::meters(2.0f) * v;

	for (size_t i = 0; i < 3; ++i)
	{
		BOOST_TEST_REQUIRE(result[i].get<si::meters2>() == 4.0f);
	}
}

BOOST_FIXTURE_TEST_CASE(test_type_div_01, emathAdvancedeVec)
{
	vec<3, si::distance> v = vec<3, si::distance>(si::meters(2.0f), si::meters(2.0f), si::meters(2.0f));
	vec<3, si::speed> result = v / si::seconds(2.0f);

	for (size_t i = 0; i < 3; ++i)
	{
		BOOST_TEST_REQUIRE(result[i].get<si::meters_second>() == 1.0f);
	}
}

BOOST_FIXTURE_TEST_CASE(test_type_dot_01, emathAdvancedeVec)
{
	vec<3, si::distance> v1 = vec<3, si::distance>(si::meters(2.0f), si::meters(2.0f), si::meters(2.0f));
	vec<3, si::time> v2 = vec<3, si::time>(si::seconds(2.0f), si::seconds(2.0f), si::seconds(2.0f));
	measure<float, unit::si<1, 1, 0>> dot = v1 * v2;
	float raw = dot.get<unit::specific_measure<float, std::ratio<1, 1>, unit::si<1, 1, 0>>>();
	BOOST_TEST_REQUIRE(raw == 12.0f);
}

/*
BOOST_FIXTURE_TEST_CASE(test_diff_01, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> data2;
	std::array<T, Dim> resultData;
	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		data2[i] = T(2 * i);
		resultData[i] = data1[i] - data2[i];
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);

	auto result = v1 - v2;

	for (size_t i = 0; i < Dim; ++i)
	{
		BOOST_TEST_REQUIRE(result[i] == resultData[i]);
	}
}

BOOST_FIXTURE_TEST_CASE(test_neg_01, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> resultData;
	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		resultData[i] = -data1[i];
	}

	vec<Dim, T> v1(data1);

	auto result = -v1;

	for (size_t i = 0; i < Dim; ++i)
	{
		BOOST_TEST_REQUIRE(result[i] == resultData[i]);
	}
}


BOOST_FIXTURE_TEST_CASE(test_eq_01, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> data2;
	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		data2[i] = T(i);
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);
	bool eq = v1 == v2;
	BOOST_TEST_REQUIRE(eq);
}

BOOST_FIXTURE_TEST_CASE(test_eq_02, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> data2;
	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		data2[i] = T(i + 1);
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);
	bool eq = v1 == v2;
	BOOST_TEST_REQUIRE(!eq);
}

BOOST_FIXTURE_TEST_CASE(test_eq_03, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> data2;
	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		if (i == 0)
		{
			data2[i] = T(i + 1);
		}
		else
		{
			data2[i] = T(i);
		}
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);
	bool eq = v1 == v2;
	BOOST_TEST_REQUIRE(!eq);
}

BOOST_FIXTURE_TEST_CASE(test_dot_01, Type, vector_types, emathAdvancedeVec)
{
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	std::array<T, Dim> data1;
	std::array<T, Dim> data2;

	decltype(std::declval<T>() * std::declval<T>()) result = T(0) * T(0);

	for (size_t i = 0; i < Dim; ++i)
	{
		data1[i] = T(i);
		data2[i] = T(i);

		auto simpleProd = T(i) * T(i);
		result = result + simpleProd;
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);
	auto dotProduct = v1 * v2;
	bool eq = (dotProduct == result);
	BOOST_TEST_REQUIRE(eq);
}
*/
BOOST_AUTO_TEST_SUITE_END()