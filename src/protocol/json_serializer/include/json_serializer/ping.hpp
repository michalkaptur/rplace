#pragma once
#include <string>
#include <protocol/ping.hpp>
#include <nlohmann/json_fwd.hpp>

namespace protocol::json_serializer{
    protocol::Ping deserialize_ping(const nlohmann::json&);
}
