#include "pch.h"
#include "emath/mat.h"

struct emathCoreFixture
{
	
};

using namespace emath;




template<size_t D>
struct _Dim
{
	static const size_t Dim = D;
};

typedef boost::mpl::list <int, float, double>::type Types2;
typedef boost::mpl::list <
	std::pair<_Dim<1>, _Dim<1>>
	, std::pair<_Dim<2>, _Dim<2>>
	, std::pair<_Dim<1>, _Dim<2>>
	, std::pair<_Dim<2>, _Dim<1>>
	, std::pair<_Dim<3>, _Dim<3>>
	, std::pair<_Dim<4>, _Dim<4>>
	, std::pair<_Dim<3>, _Dim<4>>
	, std::pair<_Dim<4>, _Dim<3>>

>::type Dimensions2;
//typedef boost::mpl::list <_Dim<1>, _Dim<2>, _Dim<3>, _Dim<4>>::type Dimensions;
//typedef combine_lists<Dimensions, Dimensions>::type Dimensions2;
typedef combine_lists<Types2, Dimensions2>::type mat_types;


BOOST_AUTO_TEST_SUITE(mat_base)

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_static_structure, Type, mat_types, emathCoreFixture)
{ 
	using T = typename Type::first_type;
	const size_t Rows = Type::second_type::first_type::Dim;
	const size_t Cols = Type::second_type::second_type::Dim;
	static_assert(sizeof(mat<Rows, Cols, T>) == Rows * Cols * sizeof(T), "Incorrect Matrix size");
	//BOOST_TEST_REQUIRE(true);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_assignment, Type, mat_types, emathCoreFixture)
{
	using T = typename Type::first_type;
	const size_t Rows = Type::second_type::first_type::Dim;
	const size_t Cols = Type::second_type::second_type::Dim;
	mat<Rows, Cols, T> m;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			m[i][j] = T(i) * T(Cols) + T(j);
		}
	}

	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			BOOST_TEST_REQUIRE(m[i][j] == T(i) * T(Cols) + T(j));
		}
	}
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_sum, Type, mat_types, emathCoreFixture)
{
	using T = typename Type::first_type;
	const size_t Rows = Type::second_type::first_type::Dim;
	const size_t Cols = Type::second_type::second_type::Dim;
	mat<Rows, Cols, T> m1;
	mat<Rows, Cols, T> m2;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			m1[i][j] = T(i) * T(Cols) + T(j);
			m2[i][j] = T(i) * T(Cols * 2) + T(j);
		}
	}

	auto result = m1 + m2;

	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			BOOST_TEST_REQUIRE(result[i][j] == T(i) * T(Cols) + T(j) + T(i) * T(Cols * 2) + T(j));
		}
	}
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_diff, Type, mat_types, emathCoreFixture)
{
	using T = typename Type::first_type;
	const size_t Rows = Type::second_type::first_type::Dim;
	const size_t Cols = Type::second_type::second_type::Dim;
	mat<Rows, Cols, T> m1;
	mat<Rows, Cols, T> m2;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			m1[i][j] = T(i) * T(Cols) + T(j);
			m2[i][j] = T(i) * T(Cols * 2) + T(j);
		}
	}

	auto result = m1 - m2;

	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			BOOST_TEST_REQUIRE(result[i][j] == (T(i) * T(Cols) + T(j)) - (T(i) * T(Cols * 2) + T(j)));
		}
	}
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(test_mult, Type, mat_types, emathCoreFixture)
{
	using T = typename Type::first_type;
	const size_t Rows = Type::second_type::first_type::Dim;
	const size_t Cols = Type::second_type::second_type::Dim;
	mat<Rows, Cols, T> m1;
	mat<Cols, Rows, T> m2;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			m1[i][j] = T(i);
			m2[j][i] = T(i*2);
		}
	}

	auto result = m1 * m2;

	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Rows; ++j)
		{
			BOOST_TEST_REQUIRE(result[i][j] == T(i) * T(j*2) * Cols);
		}
	}
}
BOOST_AUTO_TEST_SUITE_END()