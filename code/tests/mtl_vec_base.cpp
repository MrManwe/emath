#include "pch.h"
#include "emath/vec.h"

struct emathCoreFixture
{
	
};

using namespace emath;




template<size_t D>
struct _Dim
{
	static const size_t Dim = D;
};

typedef boost::mpl::list <int, float, double>::type Types;
typedef boost::mpl::list <_Dim<1>,_Dim<2>,_Dim<3>,_Dim<4>>::type Dimensions;
typedef combine_lists<Types, Dimensions>::type vector_types;


BOOST_AUTO_TEST_SUITE(vec_base)

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_static_structure, Type, vector_types, emathCoreFixture)
{ 
	using T = typename Type::first_type;
	const size_t Dim = Type::second_type::Dim;
	static_assert(sizeof(vec<Dim, T>) == Dim * sizeof(T), "Incorrect Vector size");
	//BOOST_TEST_REQUIRE(true);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_sum_01, Type, vector_types, emathCoreFixture)
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
		resultData[i] = data1[i] + data2[i];
	}

	vec<Dim, T> v1(data1);
	vec<Dim, T> v2(data2);

	auto result = v1 + v2;

	for (size_t i = 0; i < Dim; ++i)
	{
		BOOST_TEST_REQUIRE(result[i] == resultData[i]);
	}
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_diff_01, Type, vector_types, emathCoreFixture)
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

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_neg_01, Type, vector_types, emathCoreFixture)
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


BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_eq_01, Type, vector_types, emathCoreFixture)
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

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_eq_02, Type, vector_types, emathCoreFixture)
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

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_eq_03, Type, vector_types, emathCoreFixture)
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
			data2[i] = T(i+1);
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

BOOST_AUTO_TEST_SUITE_END()