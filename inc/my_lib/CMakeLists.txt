set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/generated/my_lib"
)

target_include_directories("mylib" PUBLIC
    ${LIBRARY_INCLUDES}
)

target_link_libraries("mylib" PUBLIC
    nlohmann_json::nlohmann_json
    fmt::fmt
    spdlog::spdlog
    cxxopts::cxxopts
)


if (${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("mylib")
endif()
