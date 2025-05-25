cmake_minimum_required(VERSION 3.22)

project(
    CmakeC++ProjectTemplate
    DESCRIPTION "CMake C++ Project Template"
    VERSION 1.0.0
    LANGUAGES C CXX
)

# Set Global CMake properties
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# set target names for the executable and library
# These names are used in the CMakeLists.txt files in the src and app directories
set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)

# Options for the build process and executable compilation (for demonstration purposes)
option(COMPILE_EXECUTABLE "Indicates whether to compile the executable or not" ON)

# Enable documentation in all builds
option(BUILD_DOCS "Build documentation" ON)

# Options for unit testing and code coverage
option(ENABLE_TESTING "Enable unit testing build" ON)
option(ENABLE_COVERAGE "Enable code coverage build" ON)

# Options for code quality tools
option(ENABLE_CLANG_TIDY "Enable clang-tidy checks" OFF)
option(ENABLE_CLANG_FORMAT "Enable clang-format checks" OFF)


# Options for compiler warnings, sanitizers and optimizations
option(ENABLE_WARNINGS "Enable warnings during compilation" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable warnings as errors during compilation" OFF)
option(ENABLE_ADDRESS_SANITIZER "Enable Address Sanitizer" ON)
option(ENABLE_UNDEFINED_SANITIZER "Enable Undefined Behavior Sanitizer" ON)
option(ENABLE_THREAD_SANITIZER "Enable Thread Sanitizer in cases of data races (GCC/CLANG)" OFF)
# option(ENABLE_MEMORY_SANITIZER "Enable Memory Sanitizer" OFF)
option(ENABLE_LEAK_SANITIZER "Enable Leak Sanitizer (GCC/CLANG)" OFF)
option(ENABLE_LTO "Enable LTO (Link Time Optimization) / IPO (Interprocedural Optimization)" ON)


# Options for package management
option(USE_CPM "Add CPM (C++ Package Manager) support" ON)

# Set cmake module path to include custom modules
# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)
include(BuildTypeSafeGuard)
include(Tools)

# Include warnings checks if enabled
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

add_cmake_format_target()
add_clang_format_target()


if (ENABLE_ADDRESS_SANITIZER
    OR ENABLE_UNDEFINED_SANITIZER
    OR ENABLE_THREAD_SANITIZER
    OR ENABLE_LEAK_SANITIZER
    )
    message(STATUS "Leak, Thread, Address Sanitizer enabled")
    include(Sanitizers)
    # add_sanitizer_flags(ENABLE_ADDRESS_SANITIZER ENABLE_UNDEFINED_SANITIZER)
    add_sanitizer_flags()
else()
    message(STATUS "Leak, Thread, Address Sanitizer disabled")
endif()

# if (ENABLE_THREAD_SANITIZER)
#     message(STATUS "Thread Sanitizer enabled")
#     include(Sanitizers)
#     add_sanitizer_flags(ENABLE_THREAD_SANITIZER)
# else()
#     message(STATUS "Thread Sanitizer disabled")
# endif()

if (ENABLE_LTO)
    message(STATUS "Link Time Optimization enabled")
    include(LTO)
endif()

if(BUILD_DOCS)
    include(Docs)
endif()

# options to choose CPM (C++ Package Manager) or cmake's FetchContent for dependency management
if (USE_CPM)
    message(STATUS "Using CPM (C++ Package Manager) for dependency management")
    include(CPM)
    CPMAddPackage("gh:nlohmann/json@3.12.0")
    CPMAddPackage("gh:fmtlib/fmt#11.2.0")
    CPMAddPackage("gh:gabime/spdlog@1.15.3")
    CPMAddPackage("gh:jarro2783/cxxopts@3.2.1")
    if(ENABLE_TESTING)
        cpmaddpackage("gh:catchorg/Catch2@3.8.1")
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
    endif()
else()
    message(STATUS "Using the builtin cmake FetchContent for dependency management")
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
    # Enable testing if requested
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

endif()


# Add subdirectories for the project structure
add_subdirectory(cmake)

add_subdirectory(external)

add_subdirectory(src)

add_subdirectory(inc)

# Add the app subdirectory if the executable should be compiled
if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("compilation will omit the executable")
endif()

# Add tests subdirectory if testing alone is enabled
if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# Add the code coverage target if enabled
if (ENABLE_TESTING AND ENABLE_COVERAGE)
    message(STATUS "Code coverage enabled")
    include(CodeCoverage)
    append_coverage_compiler_flags()
else()
    message(STATUS "Code coverage disabled")
endif()
