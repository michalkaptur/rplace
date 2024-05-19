#pragma once
#include "map.hpp"
#include <json_serializer/pixel.hpp>
#include <json_serializer/pong.hpp>
#include <json_serializer/serializer.hpp>
#include <memory>
#include <protocol/get_pixel.hpp>
#include <protocol/ping.hpp>
#include <protocol/pixel.hpp>
#include <protocol/set_pixel.hpp>
#include <spdlog/spdlog.h>

template <class Callable>
  requires requires(Callable f) { f(std::shared_ptr<std::string>()); }
struct message_handler {
  explicit message_handler(Callable send, Map &map) : send(send), map(map){};

  void operator()(const protocol::Ping &msg) {
    auto resp = protocol::json_serializer::serialize(
        protocol::Pong{.greeting = msg.greeting});
    send(std::make_shared<std::string>(resp));
  }
  void operator()(const protocol::GetPixel &msg) {
    // TODO: boundary check
    const auto color = map[msg.position.x][msg.position.y];
    const auto resp = protocol::json_serializer::serialize(
        protocol::Pixel{.position = msg.position, .color = color});
    send(std::make_shared<std::string>(resp));
  }
  void operator()(const protocol::SetPixel &msg) {
    // TODO: boundary check
    spdlog::debug("Setting [{}][{}] to {}", msg.position.x, msg.position.y,
                  msg.color);
    map[msg.position.x][msg.position.y] = msg.color;
    const auto resp = protocol::json_serializer::serialize(
        protocol::Pixel{.position = msg.position, .color = msg.color});
    send(std::make_shared<std::string>(resp));
  }

private:
  Callable send;
  Map &map;
};
