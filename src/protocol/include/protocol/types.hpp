#pragma once
#include "ping.hpp"
#include "pong.hpp"
#include <variant>

namespace protocol {

enum class MessageType {
  ping,
};

using Requests = std::variant<Ping>;
using Responses = std::variant<Pong>;

} // namespace protocol