#pragma once
#include <compare>
#include <string>
namespace protocol {

struct Pong {
  std::string greeting;
  auto operator<=>(const Pong &) const = default;
};
} // namespace protocol
