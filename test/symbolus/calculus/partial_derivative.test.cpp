#include "symbolus/calculus/all.hpp"

#include <catch.hpp>

#include <iostream>
#include <type_traits>

using namespace sym;

// Generic functions.

TEST_CASE(
	"Partial derivative of constant.",
	"[calculus/partial_derivative]")
{
	constexpr auto d = partial_derivative<0> < constant<std::true_type>;
	REQUIRE(std::is_same_v<decltype(d), const zero_>);
}

TEST_CASE(
	"Partial derivative of first projection with respect it.",
	"[calculus/partial_derivative]")
{
	constexpr auto d = partial_derivative<0> < projection<0>;
	REQUIRE(std::is_same_v<decltype(d), const one_>);
}

TEST_CASE(
	"Partial derivative of first projection without respect it.",
	"[calculus/partial_derivative]")
{
	constexpr auto d = partial_derivative<0> < projection<1>;
	REQUIRE(std::is_same_v<decltype(d), const zero_>);
}

// Arithmetic functions.

TEST_CASE(
	"Partial derivative of the sum of the first and second projections with respect to the first projection.",
	"[calculus/partial_derivative]"
	"[arithmetic/addition]")
{
	constexpr auto d = partial_derivative<0>  < projection<0> + projection<1>;
	REQUIRE(std::is_same_v<decltype(d), const one_>);
}

TEST_CASE(
	"Partial derivative of the sum of the first and second projections with respect to the second projection.",
	"[calculus/partial_derivative]"
	"[arithmetic/addition]")
{
	constexpr auto d = partial_derivative<1>  < projection<0> + projection<1>;
	REQUIRE(std::is_same_v<decltype(d), const one_>);
}

TEST_CASE(
	"Partial derivative of the product of the first and second projections with respect to the first projection.",
	"[calculus/partial_derivative]"
	"[arithmetic/multiplication]")
{
	constexpr auto d = partial_derivative<0>  < projection<0> * projection<1>;
	REQUIRE(std::is_same_v<decltype(d), const projection_<1>>);
}

TEST_CASE(
	"Partial derivative of the product of the first and second projections with respect to the second projection.",
	"[calculus/partial_derivative]"
	"[arithmetic/multiplication]")
{
	constexpr auto d = partial_derivative<1>  < projection<0> * projection<1>;
	REQUIRE(std::is_same_v<decltype(d), const projection_<0>>);
}
