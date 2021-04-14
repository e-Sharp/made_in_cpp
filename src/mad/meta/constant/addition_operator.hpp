#pragma once

#include "constant.hpp"

namespace mad::meta {

template<typename T, T LV, T RV> consteval
auto operator+(constant<T, LV>, constant<T, RV>)
-> constant<T, LV + RV> {
	return {};
}

}
