#pragma once
#include <assert.h>

namespace emath
{
	namespace detail
	{
		template<size_t Rows, size_t Cols, typename T, typename Row_t>
		class mat_impl
		{
		public:
			typedef Row_t row_t;
			
			inline Row_t& operator[] (size_t i_row)
			{
				assert(i_row < Rows);
				return RawData()[i_row];
			}

			inline const Row_t& operator[] (size_t i_row) const
			{
				assert(i_row < Rows);
				return RawData()[i_row];
			}

		protected:
			mat_impl() = default;

		private:
			inline Row_t* RawData()
			{
				return (Row_t*)this;
			}

			inline const T* RawData() const
			{
				return (const T*)this;
			}
		};
	}
}