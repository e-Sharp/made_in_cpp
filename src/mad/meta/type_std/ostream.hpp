#pragma once

#include "mad/meta/type/type.hpp"

#include <ostream>

namespace mad::meta {

template<typename T>
std::ostream& operator<<(std::ostream& os, type<T>) {
	return os << typeid(T).name();
}

}
