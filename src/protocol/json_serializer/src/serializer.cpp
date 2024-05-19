#include "json_serializer/get_pixel.hpp"
#include "json_serializer/ping.hpp"
#include "json_serializer/set_pixel.hpp"
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
  if (json_msg.at("type") == "get_pixel") {
    return deserialize_get_pixel(json_msg);
  }
  if (json_msg.at("type") == "set_pixel") {
    return deserialize_set_pixel(json_msg);
  }
  return Requests{protocol::Ping{}};
};
} // namespace protocol::json_serializer
