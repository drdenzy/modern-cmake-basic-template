cmake_minimum_required(VERSION 3.22)

project(
    CmakeC++ProjectTemplate
    DESCRIPTION "CMake C++ Project Template"
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)

option(COMPILE_EXECUTABLE "Indicates whether to compile the executable or not" OFF)

option(ENABLE_TESTING "Enable unit testing build" ON)
option(ENABLE_WARNINGS "Enable warnings during compilation" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable warnings as errors during compilation" OFF)


option(ENABLE_ADDRESS_SANITIZER "Enable Address Sanitizer" ON)
option(ENABLE_UNDEFINED_SANITIZER "Enable Undefined Behavior Sanitizer" ON)
option(ENABLE_THREAD_SANITIZER "Enable Thread Sanitizer in cases of data races" OFF)

# option(ENABLE_MEMORY_SANITIZER "Enable Memory Sanitizer" OFF)
# option(ENABLE_LEAK_SANITIZER "Enable Leak Sanitizer" OFF)

option(ENABLE_LTO "Enable LTO (Link Time Optimization) / IPO (Interprocedural Optimization)" ON)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)
# include(Docs)

if (ENABLE_WARNINGS)
    message(STATUS "Warnings enabled")
    include(Warnings)
else()
    message(STATUS "Warnings disabled")
endif()

# if (ENABLE_WARNINGS_AS_ERRORS)
#     message(STATUS "Warnings as errors enabled")
# else()
#     message(STATUS "Warnings as errors disabled")
# endif()

if (ENABLE_ADDRESS_SANITIZER OR ENABLE_UNDEFINED_SANITIZER)
    message(STATUS "Address Sanitizer enabled")
    include(Sanitizers)
    add_sanitizer_flags(ENABLE_ADDRESS_SANITIZER ENABLE_UNDEFINED_SANITIZER)
else()
    message(STATUS "Address Sanitizer disabled")
endif()

if (ENABLE_THREAD_SANITIZER)
    message(STATUS "Thread Sanitizer enabled")
    include(Sanitizers)
    add_sanitizer_flags(ENABLE_THREAD_SANITIZER)
else()
    message(STATUS "Thread Sanitizer disabled")
endif()

if (ENABLE_LTO)
    message(STATUS "Link Time Optimization enabled")
    include(LTO)
endif()

# Enable documentation in all builds
option(BUILD_DOCS "Build documentation" ON)
if(BUILD_DOCS)
    include(Docs)
endif()

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.12.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 11.2.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog
  GIT_TAG v1.15.3
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts
  GIT_TAG v3.2.1
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(cxxopts)

if (ENABLE_TESTING)
    FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.8.1
    GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

endif()

add_subdirectory(cmake)

add_subdirectory(external)

add_subdirectory(src)

add_subdirectory(inc)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("compilation will omit the executable")
endif()


if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
