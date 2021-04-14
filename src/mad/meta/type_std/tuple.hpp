#pragma once

#include "mad/meta/type/type.hpp"

#include <tuple>

namespace mad::meta {

template<typename... Tu, typename Ty> constexpr
decltype(auto) get(const std::tuple<Tu...>& tu, type<Ty>) {
	return std::get<Ty>(tu);
}

template<typename... Tu, typename Ty> constexpr
decltype(auto) get(std::tuple<Tu...>& tu, type<Ty>) {
	return std::get<Ty>(tu);
}

template<typename... Tu, typename Ty> constexpr
decltype(auto) get(std::tuple<Tu...>&& tu, type<Ty>) {
	return std::get<Ty>(std::move(tu));
}

}
