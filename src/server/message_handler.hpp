#pragma once
#include <json_serializer/pong.hpp>
#include <json_serializer/pixel.hpp>
#include <json_serializer/serializer.hpp>
#include <memory>
#include <protocol/ping.hpp>
#include <protocol/get_pixel.hpp>
#include <protocol/pixel.hpp>

template <class Callable>
requires requires(Callable f) { f(std::shared_ptr<std::string>()); }
struct message_handler {
  explicit message_handler(Callable send) : send(send){};

  void operator()(const protocol::Ping &msg) {
    auto resp = protocol::json_serializer::serialize(
        protocol::Pong{.greeting = msg.greeting});
    send(std::make_shared<std::string>(resp));
  }
  void operator()(const protocol::GetPixel& msg) { 
    // TODO: return valid color
    // TODO: boundary check
    auto resp = protocol::json_serializer::serialize(
        protocol::Pixel{.position = msg.position, .color=0});
    send(std::make_shared<std::string>(resp));
  }

private:
  Callable send;
};
