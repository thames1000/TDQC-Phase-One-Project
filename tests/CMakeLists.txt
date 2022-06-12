enable_testing()
include(GoogleTest)

add_executable(
        stack_gtest
        stack_gtest.cpp
)
target_link_libraries(
        stack_gtest
        PUBLIC
        stack
        gtest
        gtest_main
)

gtest_discover_tests(stack_gtest)
