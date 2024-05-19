#pragma once
#include "protocol/get_pixel.hpp"
#include "protocol/ping.hpp"
#include "protocol/pong.hpp"
#include "protocol/set_pixel.hpp"
#include <variant>

namespace protocol {

using Requests = std::variant<Ping, GetPixel, SetPixel>;
using Responses = std::variant<Pong>;

} // namespace protocol
