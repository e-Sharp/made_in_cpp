#pragma once

namespace sym {

struct zero_ {
	template<typename Type> constexpr
	operator Type() {
		return Type(0);
	}
} constexpr zero;

}
