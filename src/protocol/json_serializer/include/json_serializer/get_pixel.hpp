#pragma once
#include "protocol/get_pixel.hpp"
#include <nlohmann/json_fwd.hpp>
#include <string>

namespace protocol::json_serializer {
protocol::GetPixel deserialize_get_pixel(const nlohmann::json &);
}
