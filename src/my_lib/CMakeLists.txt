set(SRC_NAME
    "my_lib.cc"
)
set(LIB_INCLUDES
    "${CMAKE_SOURCE_DIR}/inc"
    "${CMAKE_BINARY_DIR}/generated/my_lib"
)

add_library("mylib" STATIC ${SRC_NAME})


target_include_directories("mylib" PUBLIC
    ${LIB_INCLUDES}
)


# Only add this if you want STRICT build ordering
if(BUILD_DOCS)
    add_dependencies("mylib" docs)
endif()

if (ENABLE_WARNINGS)
    # target_set_warnings(${LIBRARY_NAME} ON OFF)
        target_set_warnings(
        TARGET
        "mylib"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
else()
    message(STATUS "Warnings disabled for: 'mylib'")
endif()

if (ENABLE_LTO)
    # target_enable_lto(${LIBRARY_NAME} ${ENABLE_LTO})
        target_enable_lto(
        TARGET
        "mylib"
        ENABLE
        ON)
else()
    message(STATUS "LTO disabled for: 'mylib'")
endif()



if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("mylib")
endif()
