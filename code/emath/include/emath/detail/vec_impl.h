#pragma once
#include <assert.h>

namespace emath
{
	namespace detail
	{
		template<size_t Dim, typename T>
		class vec_impl
		{
		public:
			
			inline T& operator[] (size_t i_component)
			{
				assert(i_component < Dim);
				return RawData()[i_component];
			}

			inline const T& operator[] (size_t i_component) const
			{
				assert(i_component < Dim);
				return RawData()[i_component];
			}

		protected:
			vec_impl() = default;

		private:
			inline T* RawData()
			{
				return (T*)this;
			}

			inline const T* RawData() const
			{
				return (const T*)this;
			}
		};

	
		template<typename T1, typename T2, size_t Dim, size_t Component>
		struct dot
		{
			inline auto operator()(const vec_impl<Dim, T1>& i_v1, const vec_impl<Dim, T2>& i_v2)
			{
				static_assert(Dim > Component);
				dot<T1, T2, Dim, Component - 1> dotter;
				return i_v1[Component] * i_v2[Component] + dotter(i_v1, i_v2);
			}
		};

		template<typename T1, typename T2, size_t Dim>
		struct dot<T1, T2, Dim, 0>
		{
			inline auto operator()(const vec_impl<Dim, T1>& i_v1, const vec_impl<Dim, T2>& i_v2)
			{
				static_assert(Dim > 0);
				return i_v1[0] * i_v2[0];
			}
		};
	}
}