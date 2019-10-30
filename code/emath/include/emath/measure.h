#pragma once
#include "unit.h"

namespace emath
{
	

	template<typename T, typename Unit>
	class measure
	{
	public:

		measure() = default;

		template<std::intmax_t Num, std::intmax_t Denom>
		measure(const unit::specific_measure<T, std::ratio<Num, Denom>, Unit>& i_specific)
			: m_value((i_specific.value() * Num) / Denom)
		{

		}

		template<class SpecificUnit>
		T get() const
		{
			static_assert(std::is_same<SpecificUnit::underlying_t, T>::value && std::is_same<SpecificUnit::Unit, Unit>::value, "You are requesting an invalid unit conversion");
			return (m_value * SpecificUnit::Ratio::den) / SpecificUnit::Ratio::num;
		}
		

	private:
		measure(T i_value)
			: m_value(i_value)
		{

		}

		T m_value;

		template<typename T, typename U1, typename U2> friend measure<T, typename unit::sum<U1, U2>::type> operator+ (const measure<T, U1>& i_left, const measure<T, U2>& i_right);
		template<typename T, typename U1, typename U2> friend measure<T, typename unit::sub<U1, U2>::type> operator- (const measure<T, U1>& i_left, const measure<T, U2>& i_right);
		template<typename T, typename U1, typename U2> friend measure<T, typename unit::mult<U1, U2>::type> operator* (const measure<T, U1>& i_left, const measure<T, U2>& i_right);
		template<typename T, typename U1, typename U2> friend measure<T, typename unit::div<U1, U2>::type> operator/ (const measure<T, U1>& i_left, const measure<T, U2>& i_right);
	};

	template<typename T, typename U1, typename U2>
	measure<T, typename unit::sum<U1, U2>::type> operator+ (const measure<T, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, typename unit::sum<U1, U2>::type>(i_left.m_value + i_right.m_value);
	}

	template<typename T, typename U1, typename U2>
	measure<T, typename unit::sub<U1, U2>::type> operator- (const measure<T, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, typename unit::sub<U1, U2>::type>(i_left.m_value - i_right.m_value);
	}

	template<typename T, typename U1, typename U2>
	measure<T, typename unit::mult<U1, U2>::type> operator* (const measure<T, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, typename unit::mult<U1, U2>::type>(i_left.m_value * i_right.m_value);
	}

	template<typename T, typename U1, typename U2>
	measure<T, typename unit::div<U1, U2>::type> operator/ (const measure<T, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, typename unit::div<U1, U2>::type>(i_left.m_value / i_right.m_value);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T, typename U1, typename U2, typename Ratio>
	measure<T, typename unit::mult<U1, U2>::type> operator* (const measure<T, U1>& i_left, const unit::specific_measure<T, Ratio, U2>& i_right)
	{
		return i_left * measure<T, U2>(i_right);
	}

	template<typename T, typename U1, typename U2, typename Ratio>
	measure<T, typename unit::mult<U1, U2>::type> operator* (const unit::specific_measure<T, Ratio, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, U1>(i_left) * i_right;
	}

	template<typename T, typename U1, typename U2, typename Ratio1, typename Ratio2>
	measure<T, typename unit::mult<U1, U2>::type> operator* (const unit::specific_measure<T, Ratio1, U1>& i_left, const unit::specific_measure<T, Ratio2, U2>& i_right)
	{
		return measure<T, U1>(i_left) * measure<T, U2>(i_right);
	}

	template<typename T, typename U1, typename U2, typename Ratio>
	measure<T, typename unit::div<U1, U2>::type> operator/ (const measure<T, U1>& i_left, const unit::specific_measure<T, Ratio, U2>& i_right)
	{
		return i_left / measure<T, U2>(i_right);
	}

	template<typename T, typename U1, typename U2, typename Ratio>
	measure<T, typename unit::div<U1, U2>::type> operator/ (const unit::specific_measure<T, Ratio, U1>& i_left, const measure<T, U2>& i_right)
	{
		return measure<T, U1>(i_left) / i_right;
	}

	template<typename T, typename U1, typename U2, typename Ratio1, typename Ratio2>
	measure<T, typename unit::div<U1, U2>::type> operator/ (const unit::specific_measure<T, Ratio1, U1>& i_left, const unit::specific_measure<T, Ratio2, U2>& i_right)
	{
		return measure<T, U1>(i_left) / measure<T, U2>(i_right);
	}

	namespace si
	{
		using scalar = measure<float, scalar_def>;

		using distance = measure<float, distance_def>;
		using surface = measure<float, surface_def>;

		using time = measure<float, time_def>;


		using speed = measure<float, speed_def>;


	}
}