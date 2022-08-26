#include <exception>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <json_serializer/pong.hpp>
#include <nlohmann/json.hpp>

// lazily assuming that json lib works properly, don't really want to compare
// json messages as strings
// Component test validates that additionally

TEST(serialize_pong, valid_msg) {
  auto expected =
      R"({"type" : "pong", "greeting" : "Hello darkness, my old friend"})"_json;
  auto encoded = protocol::json_serializer::serialize(
      protocol::Pong{.greeting{"Hello darkness, my old friend"}});
  ASSERT_EQ(expected, nlohmann::json::parse(encoded));
}

TEST(serialize_pong, empty_greeting) {
  auto expected = R"({"type" : "pong", "greeting" : ""})"_json;
  auto encoded = protocol::json_serializer::serialize(protocol::Pong{});
  ASSERT_EQ(expected, nlohmann::json::parse(encoded));
}
