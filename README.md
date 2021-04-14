# Made in cpp

Release the control flow and you shall receive the benefits of declarative programming.

# Examples

## Product rule

```cpp
using namespace mad;

namespace target {
  struct derivative {};
  struct value {};

  struct lhs {};
  struct rhs {};
}

// Lhs and Rhs can be any function symbol type.
template<typename Lhs, typename Rhs>
struct sum {
  Lhs lhs;
  Rhs rhs;
};

// Declaring computation prerequisites.

template<typename L, typename R, typename... Args>
auto prerequisites(target::derivative, sum<L, R>, Args...)
-> mad::targets<lhs_target, rhs_target>;

template<typename L, typename R, typename... Args>
auto prerequisites(target::value, sum<L, R>, Args...)
-> mad::targets<lhs_target, rhs_target>;

// Defining computation in terms of dependencies.

template<mad::context C, typename L, typename R, typename... Args> constexpr
auto recipe(C c, target::derivative, const sum<L, R>& s, Args&&... as) {
  auto&& [l, ld] = get<target::value, target::derivative>(prerequisite<target::lhs>(c));
  auto&& [r, rd] = get<target::value, target::derivative>(prerequisite<target::rhs>(c));
  return l * rd + ld * r; // Here's your product rule.
}

template<mad::context C, typename L, typename R, typename... Args> constexpr
auto recipe(C c, target::value, const sum<L, R>& s, Args&&... as) {
  auto&& l = get<target::value>(prerequisite<target::lhs>(c));
  auto&& r = get<target::value>(prerequisite<target::rhs>(c));
  return l + r; // Here's your sum.
}

template<mad::context C, typename L, typename R, typename... Args> constexpr
auto recipe(C c, target::lhs, const sum<L, R>& s, Args&&... as) {
  return mad::make(targets(c), s.lhs, std::forward<Args>(as)...);
}

template<mad::context C, typename L, typename R, typename... Args> constexpr
auto recipe(C c, rhs_target, const sum<L, R>& s, Args&&... as) {
  return mad::make(targets(c), s.rhs, std::forward<Args>(as)...);
}

// Additional function symbols...

int main() {
  auto s = sum(/* any function symbol */, /* any other function symbol */);
  
  // No matter which one you use, only what's necessary will be computed;
  // and it will be computed a single time.
  
  // Compute the value and derivative of both s.lhs and s.rhs with the provided arguments.
  auto [derivative] = make<target::derivative>(s, /* whatever arguments */);
  
  // Compute the value of both s.lhs and s.rhs with the provided arguments.
  auto [value] = make<target::value>(s, /* whatever arguments */);
  
  // Compute the value and derivative of both s.lhs and s.rhs with the provided arguments.
  auto [value, derivative] = make<target::value, target::derivative>(s, /* whatever arguments */);
}

```

# Documentation

Soon.

# Compatibility

Soon.

# Tests

# Ongoing and further work

# Licence
