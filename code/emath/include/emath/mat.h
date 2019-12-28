#pragma once
#include <utility>
#include "detail/mat_impl.h"

namespace emath
{
	template<size_t Rows, size_t Cols, typename T>
	class mat: public detail::mat_impl<Rows, Cols, T, std::array<T, Cols>>
	{
	public:
		mat() = default;

		mat(std::array<std::array<T, Cols>, Rows> i_data)
			: m_data(i_data)
		{
		}
	private:
		std::array<std::array<T, Cols>, Rows> m_data;
	};
}

template<size_t Rows, size_t Cols, typename T1, typename T2, typename R = decltype(std::declval<T1>() + std::declval<T2>())>
inline emath::mat<Rows, Cols, R> operator+ (const emath::mat<Rows, Cols, T1>& i_m1, const emath::mat<Rows, Cols, T2>& i_m2)
{
	emath::mat<Rows, Cols, R> result;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			result[i][j] = i_m1[i][j] + i_m2[i][j];
		}
	}
	return result;
}

template<size_t Rows, size_t Cols, typename T1, typename T2, typename R = decltype(std::declval<T1>() - std::declval<T2>())>
inline emath::mat<Rows, Cols, R> operator- (const emath::mat<Rows, Cols, T1>& i_m1, const emath::mat<Rows, Cols, T2>& i_m2)
{
	emath::mat<Rows, Cols, R> result;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			result[i][j] = i_m1[i][j] - i_m2[i][j];
		}
	}
	return result;
}

template<size_t Rows, size_t Cols, typename T1>
inline emath::mat<Cols, Rows, T1> transpose (const emath::mat<Rows, Cols, T1>& i_m1)
{
	emath::mat<Cols, Rows, T1> result;
	for (size_t i = 0; i < Rows; ++i)
	{
		for (size_t j = 0; j < Cols; ++j)
		{
			result[j][i] = i_m1[i][j];
		}
	}
	return result;
}

template<size_t Rows1, size_t Cols1, typename T1, size_t Cols2, typename T2>
inline auto operator* (const emath::mat<Rows1, Cols1, T1>& i_m1, const emath::mat<Cols1, Cols2, T2>& i_m2)
{
	emath::mat<Cols2, Cols1, T2> transposedM2 = transpose(i_m2);
	using R1 = typename emath::mat<Rows1, Cols1, T1>::row_t;
	using R2 = typename emath::mat<Cols2, Cols1, T2>::row_t;
	using R = decltype(emath::detail::multiplier<Cols1, Cols1>::multiply(std::declval<R1>(), std::declval<R2>()));
	emath::mat<Rows1, Cols2, R> result;
	for (size_t i = 0; i < Rows1; ++i)
	{
		for (size_t j = 0; j < Cols2; ++j)
		{
			result[i][j] = emath::detail::multiplier<Cols1, Cols1>::multiply(i_m1[i], transposedM2[j]);
		}
	}
	return result;
}