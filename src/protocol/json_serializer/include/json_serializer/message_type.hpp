#pragma once
#include <protocol/types.hpp>
#include <string>

namespace protocol::json_serializer {
protocol::MessageType deserialize_message_type(const std::string &); //TODO: optional
}