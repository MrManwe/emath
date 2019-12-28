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
				const Row_t* rowArray = RawData();
				return rowArray[i_row];
			}

		protected:
			mat_impl() = default;

		private:
			inline Row_t* RawData()
			{
				return (Row_t*)this;
			}

			inline const Row_t* RawData() const
			{
				return (const Row_t*)this;
			}
		};

		template<size_t index, size_t size>
		struct multiplier
		{
			template<typename Row, typename Col>
			static inline auto multiply(const Row& i_row, const Col& i_col)
			{
				return i_row[size-index] * i_col[size-index] + multiplier<index - 1, size>::multiply(i_row, i_col);
			}
		};

		template<size_t size>
		struct multiplier<1, size>
		{
			template<typename Row, typename Col>
			static inline auto multiply(const Row& i_row, const Col& i_col)
			{
				return i_row[size - 1] * i_col[size - 1];
			}
		};
	}
}