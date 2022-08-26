#pragma once
#include <protocol/types.hpp>
#include <string>


namespace protocol::json_serializer{
    protocol::Requests deserialize(const std::string&);
}
