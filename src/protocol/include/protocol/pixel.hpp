#pragma once
#include "position.hpp"
#include <compare>

namespace protocol {
struct Pixel {
  Position position;
  unsigned color; // TODO: figure out the representation
  auto operator<=>(const Pixel &) const = default;
};
} // namespace protocol
