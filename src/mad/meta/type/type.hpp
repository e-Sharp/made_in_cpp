#pragma once

namespace mad::meta {

template<typename = void>
struct type {
    constexpr operator bool() const {
        return true;
    }
};

template<>
struct type<void> {
    constexpr operator bool() const {
        return false;
    }
};

}
