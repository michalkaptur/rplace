#pragma once
#include <nlohmann/json_fwd.hpp>
#include <protocol/ping.hpp>
#include <string>

namespace protocol::json_serializer {
protocol::Ping deserialize_ping(const nlohmann::json &);
}
