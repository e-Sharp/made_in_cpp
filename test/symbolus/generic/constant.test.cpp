#include "symbolus/generic/all.hpp"

#include <catch.hpp>
#include <iostream>
#include <type_traits>

using namespace sym;

TEST_CASE(
	"std::integral_constant constant.",
	"[generic/constant]")
{
	constexpr auto& c = constant<std::integral_constant<int, 0>>;
	REQUIRE(std::is_same_v<
		decltype(c),
		const constant_<std::integral_constant<int, 0>>&>);
}

TEST_CASE(
	"Constant of 1-tuple.",
	"[generic/constant]")
{
	constexpr auto& c = constant<std::integral_constant<int, 0>> 
	< constant<std::integral_constant<int, 10>>;
	REQUIRE(std::is_same_v<
		decltype(c),
		const constant_<std::integral_constant<int, 0>>&>);
}

TEST_CASE(
	"Constant of 2-tuple.",
	"[generic/constant]")
{
	constexpr auto& c = constant<std::integral_constant<int, 0>> < args(
		constant<std::integral_constant<int, 10>>,
		constant<std::integral_constant<int, 11>>);
	REQUIRE(std::is_same_v<
		decltype(c),
		const constant_<std::integral_constant<int, 0>>&>);
}

TEST_CASE(
	"Sum of std::integral_constant constant and float.",
	"[generic/constant]")
{
	constexpr auto s = constant<std::integral_constant<int, 10>> + 11.f;
	REQUIRE(s == 21.f);
}