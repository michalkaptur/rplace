#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <json_serializer/serializer.hpp>
#include <protocol/get_pixel.hpp>

TEST(deserialize_get_pixel, valid_msg) {
  auto msg = R"(
{
    "type": "get_pixel",
    "position": {
        "x": 3,
        "y": 44
    }
}
)";
  auto decoded = protocol::json_serializer::deserialize(msg);
  protocol::GetPixel expected{.position{.x=3, .y=44}};
  ASSERT_THAT(decoded, testing::VariantWith<protocol::GetPixel>(expected));
}
