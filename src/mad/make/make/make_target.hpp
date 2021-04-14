#pragma once

#include "mad/make/storage_context/storage_context_of.hpp"
#include "mad/meta/list/list.hpp"
#include "mad/meta/type/type.hpp"

#include <tuple>

namespace mad::make {

template<
	typename Target,
	typename... Targets,
	typename... Prerequisites,
	typename... Args>
constexpr
auto make_target(
	meta::type<Target> t,
	storage<Targets...>& ts,
	storage<Prerequisites...>& ps,
	const std::tuple<Args...>& as)
{
	auto sc = storage_context_of(ps, t, meta::list);
	return recipe(Target(), )
}

}
