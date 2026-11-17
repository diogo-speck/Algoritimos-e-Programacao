
cmake_minimum_required(VERSION 3.16)

project(SQLiteCpp
    VERSION 1.0.0
    LANGUAGES C CXX
)

# Padrão da linguagem C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Padrão da linguagem C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Biblioteca SQLite
add_library(sqlite3 STATIC
    lib/sqlite3.c
)

target_include_directories(sqlite3 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Aplicação principal
add_executable(sqlite_test
    src/main.cpp
)

target_link_libraries(sqlite_test PRIVATE sqlite3)

# Avisos de compilação para o código do projeto
if(MSVC)
    target_compile_options(sqlite_test PRIVATE /W4 /permissive-)
else()
    target_compile_options(sqlite_test PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()