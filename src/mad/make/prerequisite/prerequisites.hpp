#pragma once

#include "mad/meta/all.hpp"

#include <utility>

namespace mad::make {

template<typename... Args> consteval
meta::list<> prerequisites(Args...) {
	return {};
}

template<typename Target, typename... Args> consteval
auto prerequisites(meta::type<Target>, meta::list<Args...>) {
	return decltype(
		prerequisites(
			std::declval<Target>(),
			std::declval<Args>()...))();
}

template<typename... Targets, typename... Args> consteval
auto prerequisites(meta::list<Targets...> ts, meta::list<Args...> as) {
	if constexpr(empty(ts)) {
		return meta::list();
	} else {
		return union_(
			prerequisites(
				meta::type<Targets>(), as)...);
	}
}

template<typename... Targets, typename... Args> consteval
auto prerequisites(
	meta::list<Targets...> ts,
	meta::list<Args...> as,
	meta::recursive_tag)
{
	constexpr auto ps = prerequisites(ts, as);
	return union_(ps, prerequisites(ps, as, meta::recursive)...);
}

}
