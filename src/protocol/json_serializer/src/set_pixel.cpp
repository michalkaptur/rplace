#include "json_serializer/set_pixel.hpp"
#include <nlohmann/json.hpp>

namespace protocol::json_serializer {
protocol::SetPixel deserialize_set_pixel(const nlohmann::json &msg) {
  const auto &pos = msg.at("position");
  return protocol::SetPixel{.position = {.x = pos.at("x"), .y = pos.at("y")},
                            .color = msg.at("color")};
};
} // namespace protocol::json_serializer
