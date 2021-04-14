#pragma once

#include "command.hpp"
#include "recipe.hpp"

#include "mad/meta/type/type.hpp"

namespace mad::make {

template<typename Target, typename... C> constexpr
decltype(auto) prerequisite(command<C...> c, meta::type<Target> t) {
	return recipe(c, t);
}

}
