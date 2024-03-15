#include "json_serializer/pixel.hpp"
#include <nlohmann/json.hpp>

namespace protocol::json_serializer {
std::string serialize(const Pixel &msg) {
  nlohmann::json msg_json;
  msg_json["type"] = "pixel";
  msg_json["position"]["x"] = msg.position.x;
  msg_json["position"]["y"] = msg.position.y;
  msg_json["color"] = msg.color; // TODO: some actual encoding
  return msg_json.dump();
}
} // namespace protocol::json_serializer
