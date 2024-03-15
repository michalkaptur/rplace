add_executable(
    json_serializer_tests
    test_deserialize_ping.cpp
    test_serialize_pong.cpp
    test_deserialize_get_pixel.cpp
    test_serialize_pixel.cpp
)
target_link_libraries(
    json_serializer_tests
    PRIVATE GTest::gtest GTest::gtest_main json_serializer
)
add_test(NAME json_serializer_tests COMMAND json_serializer_tests)
