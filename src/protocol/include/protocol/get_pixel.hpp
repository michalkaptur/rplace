
#pragma once
#include <compare>
#include "position.hpp"

namespace protocol
{

    struct GetPixel
    {
        Position position;
        auto operator<=>(const GetPixel &) const = default;
    };
} // namespace protocol