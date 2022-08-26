#pragma once
#include "ping.hpp"
#include "pong.hpp"
#include <variant>

namespace protocol {

using Requests = std::variant<Ping>;
using Responses = std::variant<Pong>;

} // namespace protocol