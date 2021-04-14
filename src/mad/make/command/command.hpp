#pragma once

#include "mad/meta/list/list.hpp"

namespace mad::make {

template<typename...>
struct command {};

template<typename... Targets, typename... Args>
struct command<meta::list<Targets...>, meta::list<Args...>> {
	static constexpr auto args = meta::list<Args...>();
	static constexpr auto targets = meta::list<Targets...>();

	consteval command() = default;
	consteval command(meta::list<Targets...>, meta::list<Args...>) {}
};

template<typename... Targets, typename... Args>
command(meta::list<Targets...>, meta::list<Args...>)
-> command<meta::list<Targets...>, meta::list<Args...>>;

}
