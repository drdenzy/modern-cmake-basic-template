set(EXEC_NAME
    "main.cc"
)

add_executable("myapp" ${EXEC_NAME})

target_link_libraries("myapp" PUBLIC
    "mylib"
    nlohmann_json
    fmt::fmt
    spdlog::spdlog
)


if (ENABLE_WARNINGS)
        target_set_warnings(
        TARGET
        "myapp"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
else()
    message(STATUS "Warnings disabled for: 'myapp'")
endif()

if (ENABLE_LTO)
        target_enable_lto(
        TARGET
        "myapp"
        ENABLE
        ON)
else()
    message(STATUS "LTO disabled for: 'myapp'")
endif()

if (${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("myapp")
endif()
