cmake_minimum_required(VERSION 3.20)
project(BBlocEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Download SFML auto
include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x # Stable 2.6 version
)
FetchContent_MakeAvailable(SFML)

# Engine source files
set(ENGINE_SOURCES
  src/main.cpp
  src/Application.cpp
  src/Math/Vector2.cpp
)

# Engine headers
set(ENGINE_HEADERS
  includes/Application.hpp
  includes/Math/Vector2.hpp
)

# Main Executable "the engine"
add_executable(BBlocEngine ${ENGINE_SOURCES})
target_include_directories(BBlocEngine PRIVATE includes)
target_link_libraries(BBlocEngine PRIVATE sfml-graphics sfml-window sfml-system)

# 4. Include all the warrning flags
target_compile_options(BBlocEngine PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)

# == TEST EXECUTABLE ==
add_executable(Vector2Tests tests/Math/Vector2Tests.cpp src/Math/Vector2.cpp)
target_include_directories(Vector2Tests PRIVATE includes)
target_compile_options(Vector2Tests PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)
enable_testing()
add_test(NAME Vector2Tests COMMAND Vector2Tests)
