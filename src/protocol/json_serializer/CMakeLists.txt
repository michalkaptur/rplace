add_library(
    json_serializer
    src/ping.cpp
    src/pong.cpp
    src/serializer.cpp
    src/get_pixel.cpp
    src/set_pixel.cpp
    src/pixel.cpp
)
target_include_directories(json_serializer PUBLIC include)
target_link_libraries(
    json_serializer
    PUBLIC protocol nlohmann_json::nlohmann_json
)
add_subdirectory(tests)
