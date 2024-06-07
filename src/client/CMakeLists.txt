add_executable(rplace_client main.cpp)
target_link_libraries(
    rplace_client
    PRIVATE Boost::system json_serializer spdlog::spdlog
)
