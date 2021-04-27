#include "symbolus/generic/all.hpp"

#include <catch.hpp>
#include <iostream>
#include <tuple>
#include <type_traits>

using namespace sym;

TEST_CASE(
	"1st projection of 1-tuple.",
	"[generic/projection]")
{
	constexpr auto& p = projection<0> < projection<10>;
	REQUIRE(std::is_same_v<
		decltype(p),
		const projection_<10>&>);
}

TEST_CASE(
	"1st projection of 2-tuple.",
	"[generic/projection]")
{
	constexpr auto& p = projection<0> < args(projection<10>, projection<11>);
	REQUIRE(std::is_same_v<
		decltype(p),
		const projection_<10>&>);
}

TEST_CASE(
	"2nd projection of 1-tuple.",
	"[generic/projection]")
{
	constexpr auto& p = projection<1> < projection<10>;
	REQUIRE(std::is_same_v<
		decltype(p),
		const projection_<0>&>);
}

TEST_CASE(
	"2nd projection of 2-tuple.",
	"[generic/projection]")
{
	constexpr auto& p = projection<1> < args(projection<10>, projection<11>);
	REQUIRE(
		std::is_same_v<decltype(p),
		const projection_<11>&>);
}

TEST_CASE(
	"1st projection of float.",
	"[generic/projection]")
{
	constexpr auto p = projection<0> < 10.f;
	REQUIRE(std::is_same_v<decltype(p), const float>);
	REQUIRE(p == 10.f);
}
