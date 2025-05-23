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

option(COMPILE_EXECUTABLE "Indicates whether to compile the executable or not" OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
add_git_submodule(external/json)


add_subdirectory(cmake)

add_subdirectory(external)

add_subdirectory(src)

add_subdirectory(inc)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("compilation will omit the executable")
endif()
