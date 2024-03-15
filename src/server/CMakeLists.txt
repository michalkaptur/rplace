add_executable(rplace_server main.cpp udp_server.cpp)
target_link_libraries(
    rplace_server
    PRIVATE Boost::system json_serializer spdlog::spdlog
)
