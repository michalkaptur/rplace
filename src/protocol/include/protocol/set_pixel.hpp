#pragma once
#include "position.hpp"
#include <compare>

namespace protocol {
struct SetPixel {
  Position position;
  unsigned color; // TODO: figure out the representation
  auto operator<=>(const SetPixel &) const = default;
};
} // namespace protocol
