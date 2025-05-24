include(Catch)

set(TEST_MAIN "unit_tests")

set(TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/test_my_lib.cc")
set(TEST_INCLUDES ${CMAKE_SOURCE_DIR}/inc)

add_executable(${TEST_MAIN} ${TEST_SOURCES})
target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES})
target_link_libraries(${TEST_MAIN} PUBLIC ${LIBRARY_NAME} Catch2::Catch2WithMain)

catch_discover_tests(${TEST_MAIN})
