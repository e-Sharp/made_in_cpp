#pragma once

#include "mad/make/prerequisites/prerequisites.hpp"
#include "mad/meta/list/difference.hpp"
#include "mad/meta/list/list.hpp"
#include "mad/meta/list_std/tuple.hpp"
#include "mad/meta/tag/recursive.hpp"

#include <tuple>

namespace mad::make {

template<typename...>
struct storage;

template<template... Targets, template... Args>
struct storage<
	meta::list<Targets...>,
	meta::list<Args...>>
{
	using args = meta::list<Args...>;

	using targets = meta::list<Targets...>;
	using targets_types = void;

	using prerequisites = meta::difference(
		prerequisites(targets(), args()),
		targets());
	using prerequisites_types = void;
}

}
