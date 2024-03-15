// TODO: separate messages from internal data structures?
#pragma once
#include <compare>
namespace protocol
{
    struct Position
    {
        unsigned x;
        unsigned y;
        auto operator<=>(const Position &) const = default;
    };

}
