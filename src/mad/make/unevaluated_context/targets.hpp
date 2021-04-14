#pragma once

#include "unevaluated_context.hpp"

#include "mad/make/prerequisite/targets_with_prerequisite.hpp"

namespace mad::make {

template<typename O> consteval
auto targets(unevaluated_context_object<O> o) {
	return targets_with_prerequisite(O::targets(), O::args());
}

}
