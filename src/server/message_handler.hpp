#pragma once
#include <json_serializer/pong.hpp>
#include <json_serializer/serializer.hpp>
#include <memory>
#include <protocol/ping.hpp>
#include <protocol/get_pixel.hpp>

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
    printf("Received get_pixel request x:%d, y:%d", msg.position.x, msg.position.y);
  }

private:
  Callable send;
};
