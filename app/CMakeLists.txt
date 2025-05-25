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
        target_set_warnings(
        TARGET
        ${EXECUTABLE_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
else()
    message(STATUS "Warnings disabled for: ${EXECUTABLE_NAME}")
endif()

if (ENABLE_LTO)
        target_enable_lto(
        TARGET
        ${EXECUTABLE_NAME}
        ENABLE
        ON)
else()
    message(STATUS "LTO disabled for: ${EXECUTABLE_NAME}")
endif()

if (${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${EXECUTABLE_NAME})
endif()
