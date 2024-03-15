#pragma once
#include <protocol/pong.hpp>
#include <string>

namespace protocol::json_serializer {
std::string serialize(const Pong &);
}
