#pragma once

#include "mad/make/command/command.hpp"
#include "mad/make/prerequisite/prerequisites.hpp"
#include "mad/meta/all.hpp"

namespace mad::make {

template<typename...>
struct unevaluated_context;

template<typename... C, typename Target>
struct unevaluated_context<command<C...>, meta::type<Target>> {
	static constexpr auto command = make::command<C...>();
	static constexpr auto target = meta::type<Target>();

	consteval unevaluated_context() = default;
	consteval unevaluated_context(make::command<C...>, meta::type<Target>) {}
};

template<typename... C, typename Target>
unevaluated_context(make::command<C...>, meta::type<Target>)
-> unevaluated_context<command<C...>, meta::type<Target>>;

}
