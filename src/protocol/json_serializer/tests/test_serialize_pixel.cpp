
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <json_serializer/pixel.hpp>
#include <nlohmann/json.hpp>

TEST(serialize_pixel, valid_msg)
{
    auto expected =
        R"(
          {
            "type" : "pixel",
            "position" : {
               "x": 123,
               "y": 567
             },
            "color": 33
          }
          )"_json;
    auto encoded = protocol::json_serializer::serialize(
        protocol::Pixel{.position = {.x = 123, .y = 567}, .color = 33});
    ASSERT_EQ(expected, nlohmann::json::parse(encoded));
}
