set(EXEC_NAME
    "main.cc"
)

add_executable(${EXECUTABLE_NAME} ${EXEC_NAME})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC
    ${LIBRARY_NAME}
    nlohmann_json
)
