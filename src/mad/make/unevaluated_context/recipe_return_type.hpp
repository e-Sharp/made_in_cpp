#pragma once

#include "unevaluated_context.hpp"

namespace mad::make {

template<
	typename... C,
	typename Target,
	typename... Args>
consteval
auto recipe_return_type(
	unevaluated_context,
	meta::type<Target> t)
{
	return meta::type<decltype(
		recipe(
			o,
			std::declval<Target>(),
			std::declval<Args>()...))>();
}

}
