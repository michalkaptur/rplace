#include <exception>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <json_serializer/serializer.hpp>

TEST(deserialize_ping, valid_msg) {
  auto msg = R"(
{
    "type": "ping",
    "greeting": "What's up, Doc?"
}
)";
  auto decoded = protocol::json_serializer::deserialize(msg);
  protocol::Ping expected{.greeting{"What's up, Doc?"}};
  ASSERT_THAT(decoded, testing::VariantWith<protocol::Ping>(expected));
}

TEST(deserialize_ping, empty_greeting) {
  auto msg = R"(
{
    "type": "ping",
    "greeting": ""
}
)";
  auto decoded = protocol::json_serializer::deserialize(msg);
  protocol::Ping expected{.greeting{""}};
  ASSERT_THAT(decoded, testing::VariantWith<protocol::Ping>(expected));
}

TEST(deserialize_ping, invalid_msg) {
  auto msg = R"(
{
    "type": "ping",
    "invalid_greeting": "foo"
}
)";
  ASSERT_THROW(protocol::json_serializer::deserialize(msg),
               std::exception); // TODO replace with optional
}
