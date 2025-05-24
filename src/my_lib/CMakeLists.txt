set(SRC_NAME
    "my_lib.cc"
)
set(LIB_INCLUDES
    "${CMAKE_SOURCE_DIR}/inc"
    "${CMAKE_BINARY_DIR}/generated/my_lib"
)

add_library(${LIBRARY_NAME} STATIC ${SRC_NAME})


target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIB_INCLUDES}
)

# Only add this if you want STRICT build ordering
if(BUILD_DOCS)
    add_dependencies(${LIBRARY_NAME} docs)
endif()
