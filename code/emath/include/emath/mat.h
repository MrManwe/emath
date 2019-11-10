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