#pragma once
#include <ratio>

namespace emath
{
	namespace unit
	{
		template<typename T, typename Q>
		struct sum
		{
			
		};

		template<typename T, typename Q>
		struct sub
		{

		};

		template<typename T, typename Q>
		struct mult
		{

		};

		template<typename T, typename Q>
		struct div
		{

		};

		template<int M, int S, int K>
		class si
		{
			
		};

		template<int M, int S, int K>
		struct sum<si<M,S,K>, si<M,S,K>>
		{
			using type = si<M, S, K>;
		};

		template<int M, int S, int K>
		struct sub<si<M, S, K>, si<M, S, K>>
		{
			using type = si<M, S, K>;
		};

		template<int M, int S, int K, int M2, int S2, int K2>
		struct mult<si<M, S, K>, si<M2, S2, K2>>
		{
			using type = si<M + M2, S + S2, K + K2>;
		};

		template<int M, int S, int K, int M2, int S2, int K2>
		struct div<si<M, S, K>, si<M2, S2, K2>>
		{
			using type = si<M - M2, S - S2, K - K2>;
		};

		template<typename T, typename Ratio, typename Unit>
		class specific_unit
		{
		public:
			typedef Ratio Ratio;
			typedef T underlying_t;
			typedef Unit Unit;
			specific_unit(T i_value)
				: m_value(i_value)
			{

			}

			T value() const
			{
				return m_value;
			}

		private:
			T m_value;
		};
	}

	namespace si
	{
		using scalar_def = unit::si<0, 0, 0>;
		using distance_def = unit::si<1, 0, 0>;
		using surface_def = unit::si<2, 0, 0>;

		using time_def = unit::si<0, 1, 0>;
		using speed_def = unit::si<1, -1, 0>;

		using units = unit::specific_unit<float, std::ratio<1, 1>, scalar_def>;

		using meters = unit::specific_unit<float, std::ratio<1, 1>, distance_def>;
		using kilometers = unit::specific_unit<float, std::ratio<1000, 1>, distance_def>;

		using meters2 = unit::specific_unit<float, std::ratio<1, 1>, surface_def>;
		using kilometers2 = unit::specific_unit<float, std::ratio<1000000, 1>, surface_def>;

		using seconds = unit::specific_unit<float, std::ratio<1, 1>, time_def>;
		using hours = unit::specific_unit<float, std::ratio<3600, 1>, time_def>;

		using meters_second = unit::specific_unit<float, std::ratio<1, 1>, speed_def>;
		using kilometers_hour = unit::specific_unit<float, std::ratio<1000, 3600>, speed_def>;
	}
}