cmake_minimum_required(VERSION 3.20)

project(gamejam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Caminhos da raylib
set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/raylib")

# Biblioteca raylib já compilada
add_library(raylib STATIC IMPORTED)

set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_DIR}/lib/libraylib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_DIR}/include"
)

# Executável de teste
add_executable(teste teste.cpp)
target_link_libraries(teste PRIVATE raylib gdi32 winmm opengl32)

# Executável do projeto 3D
add_executable(game3d 3d.cpp)
target_link_libraries(game3d PRIVATE raylib gdi32 winmm opengl32)