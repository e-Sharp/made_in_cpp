#pragma once

#include "symbolus/arithmetic/division.hpp"
#include "symbolus/constant/one.hpp"
#include "symbolus/constant/zero.hpp"
#include "symbolus/composition.hpp"
#include "symbolus/variable.hpp"

namespace sym {

typename<std::size_t I, std::size_t J>
using partial_derivative_expression
= composition<
	division_,
	composition<partial_derivative_, variable_<I>>,
	composition<partial_derivative_, variable_<J>>>;

typename<std::size_t I, std::size_t J> constexpr
decltype(auto) value(const partial_derivative_expression<I, J>&) {
	return I == J ? one : zero;
}

}
