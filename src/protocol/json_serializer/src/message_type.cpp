#include "protocol/types.hpp"
#include <json_serializer/message_type.hpp>

namespace protocol::json_serializer {
protocol::MessageType deserialize_message_type(const std::string &){
    return protocol::MessageType::ping;
};
}