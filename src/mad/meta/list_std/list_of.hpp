#pragma once

#include "mad/meta/list/list.hpp"

#include <tuple>

namespace mad::meta {

template<typename... T> consteval
auto list_of(const std::tuple<T...>&&) {
	return list<T...>();
}

}
