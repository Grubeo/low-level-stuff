#pragma once

namespace llstd
{
	template<auto V>
	struct constant
	{
		constexpr static auto value = V;
		using value_type = decltype(V);
		
		operator value_type() { return V; }
		value_type operator()() { return V; }
	};
}

#define LLSTD_CONSTANT_BINOP(OP) \
	template<auto V1, auto V2> \
	auto operator OP (const constant<V1>&, const constant<V2>&) -> constant<V1 OP V2> { return {}; }

LLSTD_CONSTANT_BINOP(+)
LLSTD_CONSTANT_BINOP(-)
LLSTD_CONSTANT_BINOP(*)
LLSTD_CONSTANT_BINOP(/)
LLSTD_CONSTANT_BINOP(%)

LLSTD_CONSTANT_BINOP(&)
LLSTD_CONSTANT_BINOP(|)
LLSTD_CONSTANT_BINOP(^)

LLSTD_CONSTANT_BINOP(||)
LLSTD_CONSTANT_BINOP(&&)
LLSTD_CONSTANT_BINOP(==)
LLSTD_CONSTANT_BINOP(!=)
LLSTD_CONSTANT_BINOP(>=)
LLSTD_CONSTANT_BINOP(<=)
LLSTD_CONSTANT_BINOP(<)
LLSTD_CONSTANT_BINOP(>)
