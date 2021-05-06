#pragma once

#include "addition.hpp"

#include <ostream>

namespace sym {

template<typename S> constexpr
auto& operator<<(std::ostream& os, const sum<S>& s) {
	return os
	<< "("
	<< get<0>(s.args)
	<< " + "
	<< get<1>(s.args)
	<< ")";
}

}
