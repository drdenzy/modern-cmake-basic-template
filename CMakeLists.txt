cmake_minimum_required(VERSION 3.22)

project(
    mathOps
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)

# add first dependency
add_subdirectory(src)

# add second dependency
add_subdirectory(inc)

# add target
add_subdirectory(app)
