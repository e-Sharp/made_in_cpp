#include "symbolus/generic/all.hpp"

#include <catch.hpp>
#include <iostream>
#include <type_traits>

using namespace sym;

TEST_CASE(
	"Function that do nothing.",
	"[generic/function]")
{
	constexpr auto f = function([](){});
}