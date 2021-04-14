#pragma once

#include "control_flow_node.hpp"

#include "mad/meta/list/union.hpp"

#include <type_traits>

namespace mad::make {

template<typename N> consteval
auto targets(control_flow_node<N> n) {
	if constexpr(std::is_void_v<N::parent>) {
		return N::targets();
	} else {
		return union_(N::targets(), targets(N::parent()));
	}
}

}
