#pragma once

#include "symbolus/detail/tuple_like.hpp"

#include <tuple>
#include <utility>

namespace sym {

template<typename Function, tuple_like Args> constexpr
decltype(auto) value(Function&& f, Args&& as) {
	return std::forward<Function>(f);
}

template<typename Function> constexpr
decltype(auto) value(Function&& f) {
	return value(std::forward<Function>(f), std::tuple());
}

template<tuple_like Functions, tuple_like Args> constexpr
auto value(Functions&& fs, Args&& as) {
	auto f = [&as](auto&&... fs) {
		return std::forward_as_tuple(value(std::forward<decltype(fs)>(fs), as)...);
	};
	return std::apply(f, std::forward<Functions>(fs));
}

template<tuple_like Functions> constexpr
auto value(Functions&& fs) {
	return value(std::forward<Functions>(fs), std::tuple());
}

}
