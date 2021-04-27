#pragma once

#include "symbolus/generic/expand.hpp"

#include <tuple>

namespace sym {

template<std::size_t I>
struct projection_ {};

template<std::size_t I>
constexpr auto projection = projection_<I>();

template<std::size_t I, typename Tuple>
requires (I < std::tuple_size_v<std::remove_reference_t<Tuple>>)
constexpr
auto&& apply_tuple(projection_<I>, Tuple&& t) {
	return std::get<I>(std::forward<Tuple>(t));
}

template<std::size_t I, typename Tuple>
requires (I >= std::tuple_size_v<std::remove_reference_t<Tuple>>)
constexpr
const auto& apply_tuple(projection_<I>, Tuple&&) {
	return projection<I - std::tuple_size_v<std::remove_reference_t<Tuple>>>;
}

}
