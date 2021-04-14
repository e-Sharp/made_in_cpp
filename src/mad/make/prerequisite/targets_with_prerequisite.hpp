#pragma once

#include "prerequisites.hpp"

#include "mad/meta/list/contains.hpp"
#include "mad/meta/list/list.hpp"
#include "mad/meta/list/union.hpp"
#include "mad/meta/type/type.hpp"

namespace mad::make {

template<
	typename Target, 
	typename Prerequisite, 
	typename... Args>
consteval
auto targets_with_prerequisite(
	meta::type<Target> t,
	meta::type<Prerequisite> p,
	meta::list<Args...> as);

template<
	typename... Targets,
	typename Prerequisite,
	typename...Args>
consteval
auto targets_with_prerequisite(
	meta::list<Targets...> ts,
	meta::type<Prerequisite> p,
	meta::list<Args...> as)
{
	return union_(
		targets_with_prerequisite(
			meta::type<Targets>(), p, as)...);
}

template<
	typename Target, 
	typename Prerequisite, 
	typename... Args>
consteval
auto targets_with_prerequisite(
	meta::type<Target> t,
	meta::type<Prerequisite> p,
	meta::list<Args...> as)
{
	constexpr auto ps = prerequisites(t, as);
	if constexpr(empty(ps)) {
		return meta::list();
	} else if constexpr(contains(ps, p)) {
		return meta::list<Target>();
	} else {
		return targets_with_prerequisite(ps, p, as);
	}
}

}
