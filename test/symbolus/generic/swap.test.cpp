#include "symbolus/generic/all.hpp"

#include <catch.hpp>
#include <iostream>
#include <type_traits>

using namespace sym;

TEST_CASE(
	"Swap of 1st and 2nd projections.",
	"[generic/swap]")
{
	constexpr auto s = swap < args(projection<10>, projection<11>);
	REQUIRE(std::is_same_v<
		decltype(s),
		const std::tuple<const projection_<11>&, const projection_<10>&>>);
}

TEST_CASE(
	"Swap of swap.",
	"[generic/swap]")
{
	constexpr auto s = swap < expand(swap);
	REQUIRE(std::is_same_v<
		decltype(s),
		const std::tuple<
			const projection_<0>&,
			const projection_<1>&>>);
}
