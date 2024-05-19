#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <json_serializer/serializer.hpp>
#include <protocol/set_pixel.hpp>

TEST(deserialize_get_pixel, valid_msg) {
  auto msg = R"(
{
    "type": "set_pixel",
    "color": 4,
    "position": {
        "x": 12,
        "y": 2
    }
}
)";
  auto decoded = protocol::json_serializer::deserialize(msg);
  protocol::SetPixel expected{.position{.x = 12, .y = 2}, .color = 4};
  ASSERT_THAT(decoded, testing::VariantWith<protocol::SetPixel>(expected));
}
