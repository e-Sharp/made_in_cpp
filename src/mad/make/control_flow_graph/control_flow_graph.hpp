#pragma once

#include "control_flow_node.hpp"
#include "targets.hpp"

#include "mad/make/prerequisite/prerequisites.hpp"
#include "mad/meta/list/all.hpp"

namespace mad::make {

template<
	typename... Targets,
	typename... Args>
consteval
auto control_flow_graph(
	meta::list<Targets...> ts,
	meta::list<Args...> as)
{
	constexpr auto ps = prerequisites(ts, as);
	if constexpr(empty(ps)) {
		struct traits {
			using parent = void;
			using targets = decltype(ts);
		};
		return control_flow_node<traits>();
	} else {
		struct traits {
			using parent = decltype(control_flow_graph(ps, as));
			using targets = decltype(
				difference(ts, targets(parent())));
		};
		return control_flow_node<traits>();
	}
}

}
