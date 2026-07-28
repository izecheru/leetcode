add_executable(test_runner 
"problems_test.cpp"
)
target_link_libraries(test_runner PRIVATE GTest::gtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_runner)