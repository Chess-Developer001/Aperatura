cmake_minimum_required(VERSION 3.10)
project(Aperatura VERSION 0.2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(aperatura
    src/main.cpp
    src/uci.cpp
    src/engine.cpp
    src/board.cpp
    src/search.cpp
    src/eval_nnue.cpp
)

target_include_directories(aperatura PRIVATE src)
