#pragma once

#include "symbolus2/generic/application.hpp"
#include "symbolus2/generic/tuple.hpp"

#include <tuple>

namespace sym {

template<typename Type>
struct function {
	template<typename Type_> constexpr
	function(Type_&& t)
		: object(std::forward<Type_>(t))
	{}
	
	template<typename... Args>  requires
	requires(function f) { f.object(std::declval<Args>()...); }
	constexpr auto operator()(Args&&... as) const {
		return object(std::forward<Args>(as)...);
	}

	template<typename... Args> constexpr
	auto operator()(Args&&... as) const {
		return application(
			*this, 
			tuple_of(
				std::forward<Args>(as)...));
	}

	template<typename Tuple> constexpr
	auto operator[](Tuple&& t) const {
		return std::apply(
			[this](auto&&... as) {
				return operator()(std::forward<decltype(as)>(as)...); },
			t);
	}

	Type object;
};

template<typename Type>
function(Type) -> function<Type>;

}
