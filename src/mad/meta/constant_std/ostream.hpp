#pragma once

#include "mad/meta/constant/constant.hpp"

#include <ostream>

namespace mad::meta {

template<typename Type, Type Value>
decltype(auto) operator<<(std::ostream& os, constant<Type, Value> c) {
	return os << typeid(Type).name() << "(" << Value << ")";
}

}
