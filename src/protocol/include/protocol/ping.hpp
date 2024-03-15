#pragma once
#include <compare>
#include <string>
namespace protocol {
struct Ping {
  std::string greeting;
  auto operator<=>(const Ping &) const = default;
};
} // namespace protocol
