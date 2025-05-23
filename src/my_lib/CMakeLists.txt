set(SRC_NAME
"my_lib.cc"
)

add_library(${LIBRARY_NAME} STATIC ${SRC_NAME})

# Add dependency to ensure docs build before the library
# add_dependencies(${LIBRARY_NAME} docs)


# Only add this if you want STRICT build ordering
if(BUILD_DOCS)
    add_dependencies(${LIBRARY_NAME} docs)
endif()
