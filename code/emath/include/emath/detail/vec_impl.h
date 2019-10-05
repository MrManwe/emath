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
	}
}