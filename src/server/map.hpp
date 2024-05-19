#pragma once
#include <vector>

using Color = unsigned;
using Map = std::vector<std::vector<Color>>;

inline Map make_map(unsigned size, Color default_color = 0) {
  return Map(size, std::vector<Color>(size, default_color));
};
