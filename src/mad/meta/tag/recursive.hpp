#pragma once

namespace mad::meta {

struct recursive_tag {};

constexpr auto recursive = recursive_tag();

}
