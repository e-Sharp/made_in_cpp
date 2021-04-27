#pragma once

namespace sym {

struct one_ {
	template<typename Type> constexpr
	operator Type() {
		return Type(1);
	}
} constexpr one;

}
