#pragma once

#include "mad/meta/type/type.hpp"

template<typename> struct aunt {};
template<typename> struct cousin {};
template<typename> struct brother {};
template<typename> struct brother_in_law {};
template<typename> struct daughter {};
template<typename> struct father {};
template<typename> struct half_father {};
template<typename> struct half_mother {};
template<typename> struct maternal_grandfather {};
template<typename> struct maternal_grandmother {};
template<typename> struct me {};
template<typename> struct mother {};
template<typename> struct nephew {};
template<typename> struct niece {};
template<typename> struct paternal_grandfather {};
template<typename> struct paternal_grandmother {};
template<typename> struct sister {};
template<typename> struct sister_in_law {};
template<typename> struct son {};
template<typename> struct stepfather {};
template<typename> struct stepmother {};
template<typename> struct uncle {};

template<typename Family> constexpr
auto prerequisite(brother<Family>)
-> mad::meta::list<father<Family>, mother<Family>>;

template<typename Family> constexpr
auto prerequisite(daughter<Family>)
-> mad::meta::list<me<Family>>;

template<typename Family> constexpr
auto prerequisite(me<Family>)
-> mad::meta::list<father<Family>, mother<Family>>;

template<typename Family> constexpr
auto prerequisite(sister<Family>)
-> mad::meta::list<father<Family>, mother<Family>>;

template<typename Family> constexpr
auto prerequisite(son<Family>)
-> mad::meta::list<me<Family>>;
