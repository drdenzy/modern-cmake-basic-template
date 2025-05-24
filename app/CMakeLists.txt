set(EXEC_NAME
    "main.cc"
)

add_executable(${EXECUTABLE_NAME} ${EXEC_NAME})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC
    ${LIBRARY_NAME}
    nlohmann_json
    fmt::fmt
    spdlog::spdlog
)


if (ENABLE_WARNINGS)
    target_set_warnings(${EXECUTABLE_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})
else()
    message(STATUS "Warnings disabled for: ${EXECUTABLE_NAME}")
endif()

if (ENABLE_LTO)
    target_enable_lto(${EXECUTABLE_NAME} ${ENABLE_LTO})
else()
    message(STATUS "LTO disabled for: ${EXECUTABLE_NAME}")
endif()

