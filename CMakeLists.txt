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

# Collect automaticly all the source and header files
file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "includes/*.hpp")

# Target configuration
add_executable(BBlocEngine ${ENGINE_SOURCES} ${ENGINE_HEADERS})
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

# == Shape Tests ==
add_executable(ShapeTests tests/Shapes/ShapeTests.cpp
    src/Math/Vector2.cpp
    src/Shapes/Shape.cpp
    src/Shapes/Circle.cpp
    src/Shapes/Rectangle.cpp
    src/Shapes/Triangle.cpp
    src/Shapes/Line.cpp
)
target_include_directories(ShapeTests PRIVATE includes)
target_link_libraries(ShapeTests PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_options(ShapeTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME ShapeTests COMMAND ShapeTests)

# Input Tests
add_executable(InputTests tests/Input/InputTests.cpp
    src/Math/Vector2.cpp
    src/Input/InputManager.cpp
)
target_include_directories(InputTests PRIVATE includes)
target_link_libraries(InputTests PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_options(InputTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME InputTests COMMAND InputTests)

# Physics Tests
add_executable(PhysicsTests tests/Physics/PhysicsTests.cpp
    src/Math/Vector2.cpp
    src/Physics/Rigidbody.cpp
)
target_include_directories(PhysicsTests PRIVATE includes)
target_compile_options(PhysicsTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME PhysicsTests COMMAND PhysicsTests)

# Collision Tests
add_executable(CollisionTests tests/Physics/CollisionTests.cpp
    src/Math/Vector2.cpp
    src/Physics/Collision.cpp
)
target_include_directories(CollisionTests PRIVATE includes)
target_compile_options(CollisionTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME CollisionTests COMMAND CollisionTests)

# GameObject Tests
add_executable(GameObjectTests tests/Core/GameObjectTests.cpp
    src/Math/Vector2.cpp
    src/Core/Component.cpp
    src/Core/Transform.cpp
    src/Core/Sprite.cpp
    src/Core/PhysicsComponent.cpp
    src/Core/GameObject.cpp
    src/Core/Scene.cpp
    src/Physics/Rigidbody.cpp
    src/Shapes/Shape.cpp
    src/Shapes/Circle.cpp
)
target_include_directories(GameObjectTests PRIVATE includes)
target_link_libraries(GameObjectTests PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_options(GameObjectTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME GameObjectTests COMMAND GameObjectTests)

# Integration Tests
add_executable(IntegrationTests tests/Integration/IntegrationTests.cpp
    src/Math/Vector2.cpp
    src/Core/Component.cpp
    src/Core/Transform.cpp
    src/Core/Sprite.cpp
    src/Core/PhysicsComponent.cpp
    src/Core/GameObject.cpp
    src/Core/Scene.cpp
    src/Physics/Rigidbody.cpp
    src/Physics/Collision.cpp
    src/Shapes/Shape.cpp
    src/Shapes/Circle.cpp
    src/Shapes/Rectangle.cpp
    src/Shapes/Triangle.cpp
    src/Shapes/Line.cpp
    src/Input/InputManager.cpp
)
target_include_directories(IntegrationTests PRIVATE includes)
target_link_libraries(IntegrationTests PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_options(IntegrationTests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME IntegrationTests COMMAND IntegrationTests)
