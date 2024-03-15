
#pragma once
#include "position.hpp"
#include <compare>

namespace protocol {

struct GetPixel {
  Position position;
  auto operator<=>(const GetPixel &) const = default;
};
} // namespace protocol
