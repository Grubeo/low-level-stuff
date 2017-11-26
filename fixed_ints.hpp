#ifndef _FIXED_INTS_HPP
#define _FIXED_INTS_HPP

#include <type_traits>

namespace details
{
	template<unsigned SIZE>
	struct fixed_width_signed
	{
		static constexpr unsigned byte_size = SIZE / 8;

		using type = std::conditional_t<byte_size == sizeof(signed char), char,
			std::conditional_t<byte_size == sizeof(short), short,
				std::conditional_t<byte_size == sizeof(int), int,
					std::conditional_t<byte_size == sizeof(long), long,
						long long
					>
				>
			>
		>;
	};

	template<unsigned SIZE>
	using fixed_width_signed_t = typename fixed_width_signed<SIZE>::type;

	template<unsigned SIZE>
	struct fixed_width_unsigned
	{
		using type = std::make_unsigned_t<typename fixed_width_signed<SIZE>::type>;
	};

	template<unsigned SIZE>
	using fixed_width_unsigned_t = typename fixed_width_unsigned<SIZE>::type;
}

using int8_t  = utils::fixed_width_signed_t<8>;
using int16_t = utils::fixed_width_signed_t<16>;
using int32_t = utils::fixed_width_signed_t<32>;
using int64_t = utils::fixed_width_signed_t<64>;

using uint8_t  = utils::fixed_width_unsigned_t<8>;
using uint16_t = utils::fixed_width_unsigned_t<16>;
using uint32_t = utils::fixed_width_unsigned_t<32>;
using uint64_t = utils::fixed_width_unsigned_t<64>;

#endif
