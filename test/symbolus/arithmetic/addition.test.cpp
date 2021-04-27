#include "symbolus/arithmetic/addition.hpp"

#include "symbolus/generic/all.hpp"

#include <catch.hpp>

#include <iostream>
#include <type_traits>

using namespace sym;

TEST_CASE(
	"Sum of floats.",
	"[arithmetic/addition]")
{
	constexpr auto s = addition < args(10.f, 11.f);
	REQUIRE(std::is_same_v<decltype(s), const float>);
	REQUIRE(s == 21.f);
}

TEST_CASE(
	"Partial sum of floats.",
	"[arithmetic/addition]")
{
	constexpr auto ps = addition < constant<std::integral_constant<float, 10>>;
	constexpr auto s = float(ps < constant<std::integral_constant<float, 11>>);
	REQUIRE(s == 21.f);
}

TEST_CASE(
	"Sum of projections.",
	"[arithmetic/addition]")
{
	constexpr auto s = projection<10> + projection<11>;
	REQUIRE(std::is_same_v<
		decltype(s),
		const tuple_application<
			addition_,
			std::tuple<
				const projection_<10>&,
				const projection_<11>&>>>);
}


TEST_CASE(
	"Partial sum of projections.",
	"[arithmetic/addition]")
{
	constexpr auto ps = addition < projection<10>;
	REQUIRE(std::is_same_v<
		decltype(ps),
		const tuple_application<
			addition_,
			std::tuple<
				const projection_<10>&,
				const projection_<0>&>>>);
	constexpr auto s = ps < projection<11>;
	REQUIRE(std::is_same_v<
		decltype(s),
		const tuple_application<
			addition_,
			std::tuple<
				const projection_<9>&,
				const projection_<11>&>>>);
}
