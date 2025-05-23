find_package(Doxygen REQUIRED)

if(Doxygen_FOUND)
    # set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/docs")
    # set(DOXYGEN_INPUT "${CMAKE_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/src")

    set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_SOURCE_DIR}/docs/Doxyfile)

    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    add_custom_target(
        docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} "${DOXYFILE_OUT}"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()
