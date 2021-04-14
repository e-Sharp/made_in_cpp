#pragma once

#include "command.hpp"

#include "mad/make/unevaluated_context/unevaluated_context.hpp"
#include "mad/meta/list/list.hpp"
#include "mad/meta/type/type.hpp"

#include <utility>

namespace mad::make {

template<typename Context, typename Target, typename... Args> constexpr
auto recipe(Context c, meta::type<Target>, meta::list<Args...>) {
	return recipe(c, Target(), std::declval<Args>()...);
}

template<typename... C, typename Target> constexpr
auto recipe(command<C...> c, meta::type<Target> t) {
	constexpr auto uc = unevaluated_context(c, t);
	return recipe(uc, t, c.args);
}

}
