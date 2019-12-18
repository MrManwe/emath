#pragma once
#include <utility>
#include "detail/vec_impl.h"

namespace emath
{
	template<size_t Dim, typename T>
	class vec: public detail::vec_impl<Dim, T>
	{
	public:
		vec() = default;

		vec(const std::array<T, Dim>& i_data)
			: m_data(i_data)
		{
		}
	private:
		std::array<T, Dim> m_data;
	};

	template<typename T>
	class vec<1, T> : public detail::vec_impl<1, T>
	{
	public:
		vec() = default;

		vec(const std::array<T, 1>& i_data)
			: x(i_data[0])
		{
		}

		explicit vec(const T& i_x)
			: x(i_x)
		{

		}

		T x;
		
	private:
	};

	template<typename T>
	class vec<2,T> : public detail::vec_impl<2, T>
	{
	public:
		vec() = default;

		vec(const std::array<T, 2>& i_data)
			: x(i_data[0])
			, y(i_data[1])
		{
		}

		explicit vec(const T& i_x, const T& i_y)
			: x(i_x)
			, y(i_y)
		{

		}

		T x;
		T y;
	private:
	};

	template<typename T>
	class vec<3, T> : public detail::vec_impl<3, T>
	{
	public:
		vec() = default;

		vec(const std::array<T, 3>& i_data)
			: x(i_data[0])
			, y(i_data[1])
			, z(i_data[2])
		{
		}

		explicit vec(const T& i_x, const T& i_y, const T& i_z)
			: x(i_x)
			, y(i_y)
			, z(i_z)
		{

		}

		T x;
		T y;
		T z;
	private:
	};

	template<typename T>
	class vec<4, T> : public detail::vec_impl<4, T>
	{
	public:
		vec() = default;

		vec(const std::array<T, 4>& i_data)
			: x(i_data[0])
			, y(i_data[1])
			, z(i_data[2])
			, w(i_data[3])
		{
		}

		explicit vec(const T& i_x, const T& i_y, const T& i_z, const T& i_w)
			: x(i_x)
			, y(i_y)
			, z(i_z)
			, w(i_w)
		{

		}

		T x;
		T y;
		T z;
		T w;
	private:
	};
}

template<size_t Dim, typename T1, typename T2, typename R = decltype(std::declval<T1>() + std::declval<T2>())>
inline emath::vec<Dim, R> operator+ (const emath::vec<Dim, T1>& i_v1, const emath::vec<Dim, T2>& i_v2)
{
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = i_v1[i] + i_v2[i];
	}
	return result;
}

template<size_t Dim, typename T1, typename T2, typename R = decltype(std::declval<T1>() - std::declval<T2>())>
inline emath::vec<Dim, R> operator- (const emath::vec<Dim, T1> & i_v1, const emath::vec<Dim, T2> & i_v2)
{
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = i_v1[i] - i_v2[i];
	}
	return result;
}

template<size_t Dim, typename T, typename R = decltype(-std::declval<T>())>
inline emath::vec<Dim, R> operator- (const emath::vec<Dim, T> & i_v1)
{
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = -i_v1[i];
	}
	return result;
}

template<size_t Dim, typename T1, typename T2>
inline bool operator== (const emath::vec<Dim, T1> & i_v1, const emath::vec<Dim, T2> & i_v2)
{
	bool equal = true;
	for (size_t i = 0; i < Dim; ++i)
	{
		equal = equal &&  (i_v1[i] == i_v2[i]);
	}
	return equal;
}

template<size_t Dim, typename T1, typename T2>
inline bool operator!= (const emath::vec<Dim, T1>& i_v1, const emath::vec<Dim, T2>& i_v2)
{
	return !(i_v1 == i_v2);
}

template<typename T1, typename T2>
inline auto operator* (const emath::vec<1, T1> & i_v1, const emath::vec<1, T2> & i_v2)
{
	return i_v1.x * i_v2.x;
}

template<size_t Dim, typename T1, typename T2>
inline auto operator* (const emath::vec<Dim, T1> & i_v1, const emath::vec<Dim, T2> & i_v2)
{
	emath::detail::dot<T1, T2, Dim, Dim - 1> dotter;
	return dotter(i_v1, i_v2);
}

template<size_t Dim, typename T1, typename T2>
inline auto operator* (const emath::vec <Dim,T1>& i_v, const T2& i_scalar)
{
	using R = decltype(std::declval<T1>() * std::declval<T2>());
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = i_v[i] * i_scalar;
	}
	return result;
}

template<size_t Dim, typename T1, typename T2>
inline auto operator* (const T2& i_scalar, const emath::vec <Dim, T1>& i_v)
{
	using R = decltype(std::declval<T2>() * std::declval<T1>());
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = i_scalar * i_v[i];
	}
	return result;
}

template<size_t Dim, typename T1, typename T2>
inline auto operator/ (const emath::vec <Dim, T1>& i_v, const T2& i_scalar)
{
	using R = decltype(std::declval<T1>() / std::declval<T2>());
	emath::vec<Dim, R> result;
	for (size_t i = 0; i < Dim; ++i)
	{
		result[i] = i_v[i] / i_scalar;
	}
	return result;
}