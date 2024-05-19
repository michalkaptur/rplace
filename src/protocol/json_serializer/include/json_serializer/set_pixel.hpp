#pragma once
#include "protocol/set_pixel.hpp"
#include <nlohmann/json_fwd.hpp>

namespace protocol::json_serializer {
protocol::SetPixel deserialize_set_pixel(const nlohmann::json &);
}
