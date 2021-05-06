#pragma once

#include <cstdlib>
#include <tuple>

namespace sym {

template<std::size_t I>
struct projection {};

template<std::size_t I, typename Tuple> constexpr
decltype(auto) apply_tuple(projection<I>, Tuple&& t) {
	constexpr auto n = std::tuple_size_v<std::remove_reference_t<Tuple>>;
	if constexpr(I < n) {
		return get<I>(std::forward<Tuple>(t));
	} else {
		return projection<I - n>();
	}
}

template<std::size_t I, typename... Types> constexpr
decltype(auto) apply(projection<I> p, Types&&... ts) {
	return apply_tuple(
		p,
		std::forward_as_tuple(
			std::forward<Types>(ts)...));
}

}
