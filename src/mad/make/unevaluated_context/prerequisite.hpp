#pragma once

#include "unevaluated_context.hpp"

#include "mad/make/command/prerequisite.hpp"

namespace mad::make {

// Unevaluated.
template<typename... C, typename Prerequisite> constexpr
const auto& prerequisite(
	unevaluated_context<C...> c, meta::type<Prerequisite> p)
{
	return prerequisite(c.command, p);
}

}
