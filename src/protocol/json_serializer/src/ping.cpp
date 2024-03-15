#include "json_serializer/ping.hpp"
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

namespace protocol::json_serializer {
protocol::Ping deserialize_ping(const nlohmann::json &ping) {
  return protocol::Ping{.greeting{ping.at("greeting")}};
};
} // namespace protocol::json_serializer
