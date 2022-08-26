#include "json_serializer/ping.hpp"
#include "protocol/types.hpp"
#include <json_serializer/serializer.hpp>
#include <nlohmann/json.hpp>

namespace protocol::json_serializer {
Requests deserialize(const std::string &msg) {
  auto json_msg =
      nlohmann::json::parse(msg); // TODO return std::nullopt, catch exceptions
  if (json_msg.at("type") == "ping") {
    return deserialize_ping(json_msg);
  }
  return Requests{protocol::Ping{}};
};
} // namespace protocol::json_serializer