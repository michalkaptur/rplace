#include <json_serializer/pong.hpp>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>


namespace protocol::json_serializer {
    std::string serialize(const Pong & msg){
        nlohmann::json msg_json;
        msg_json["type"] = "pong";
        msg_json["greeting"] = msg.greeting;
        return msg_json.dump();
    }
}
