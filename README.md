# modern cmake patterns for c++ projects

Modern CMake makes it easy to build C++ projects with a variety of features, including:

- **CMake**: A powerful build system that can generate build files for various platforms.
- **GoogleTest**: A popular testing framework for C++.
- **Doxygen**: A documentation generator for C++ projects.
- **Conan**: A package manager for C++ libraries.
- **CPM**: A CMake package manager that simplifies dependency management.
- **GitHub Actions**: A CI/CD platform that automates the build and test process.
- **clang-format**: A tool to format C++ code according to style guidelines.
- **clang-tidy**: A static analysis tool for C++ code.
- **cppcheck**: A static analysis tool for C++ code.
- **cpplint**: A tool to check C++ code style against Google C++ Style Guide.

## Build C++ Libraries and Executables

```bash
mkdir build

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DENABLE_TESTING=ON -DENABLE_DOCS=ON
cmake --build build
```

## Build Docs

This project uses [Doxygen](https://www.doxygen.nl/) to generate documentation.

```bash
cmake --build build --target docs
```

## Build and Run Unit Tests

```bash
cmake --build build --target test
cd build
ctest --output-on-failure
```
