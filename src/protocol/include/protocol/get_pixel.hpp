
#pragma once
#include <compare>
#include <string>
namespace protocol
{

    struct Position
    {
        unsigned x;
        unsigned y;
        auto operator<=>(const Position &) const = default;
    };

    struct GetPixel
    {
        Position position;
        auto operator<=>(const GetPixel &) const = default;
    };
} // namespace protocol