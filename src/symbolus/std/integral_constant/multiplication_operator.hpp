#pragma once

#include <type_traits>

namespace sym {

template<typename T0, T0 V0, typename T1, T1 V1> constexpr
auto operator*(
	std::integral_constant<T0, V0>,
	std::integral_constant<T1, V1>)
{
	return std::integral_constant<decltype(V0 * V1), V0 * V1>();
}

}
