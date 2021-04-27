#pragma once

#include "partial_derivative.hpp"

#include "symbolus/composition.hpp"
#include "symbolus/variable.hpp"

namespace sym {

template<std::size_t I> constexpr
auto function_call_operator(
	const partial_derivative_&,
	const variable_<I>&) 
{
	return composition<partial_derivative_, variable_<I>>();
}

}
