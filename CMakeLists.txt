cmake_minimum_required(VERSION 3.22)

project(
    mathOps
    VERSION 1.0.0
    LANGUAGES C CXX
)

# add_library(Library STATIC src/my_lib.cc)

# add_executable(Executable app/main.cc)

# target_link_libraries(Executable PUBLIC Library)

# Tell cmake where to find subdirectories
add_subdirectory(src)
add_subdirectory(app)
