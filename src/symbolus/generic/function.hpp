#pragma once

#include "symbolus/generic/tuple_application.hpp"

#include <tuple>
#include <utility>

namespace sym {

template<typename Type>
struct function {
	template<typename Type_> constexpr
	function(Type_&& o)
		: object(std::forward<Type_>(o))
	{}

	Type object;
};

template<typename Type>
function(Type) -> function<Type>;

template<typename F, typename... Args> constexpr
auto apply(const function<F>& f, Args&&... as) {
	return tuple_application(
		f, std::tuple<Args>(std::forward<Args>(as)...));
}

template<typename F, typename... Args> requires
requires(F f) { f(std::declval<Args>()...); }
constexpr
decltype(auto) apply(const function<F>& f, Args&&...) {
	return f.object(std::forward<Args>()...);
}

template<typename F, typename Tuple> constexpr
decltype(auto) apply_tuple(const function<F>& f, Tuple&& t) {
	return std::apply(
		[&f](auto&&... as) {
			return sym::apply(
				f, std::forward<decltype(as)>(as)...);
		},
		std::forward<Tuple>(t));
}

}
