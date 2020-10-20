cmake_minimum_required(VERSION 3.17)
project(L07CairoText)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(THREAD_SAFE)

include_directories(
        /usr/local/include/SDL2
        /usr/local/include/cairo
)

link_directories(
        /usr/local/lib
)

link_libraries(
        SDL2
        cairo
)

add_executable(L07CairoText main.c)