#include "json_serializer/get_pixel.hpp"
#include <nlohmann/json.hpp>

namespace protocol::json_serializer {
protocol::GetPixel deserialize_get_pixel(const nlohmann::json &msg) {
  const auto& pos = msg.at("position");
  return protocol::GetPixel{.position={.x=pos.at("x"), .y=pos.at("y")}};
};
} // namespace protocol::json_serializer
