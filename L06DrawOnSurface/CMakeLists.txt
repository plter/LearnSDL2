cmake_minimum_required(VERSION 3.17)
project(L06DrawOnSurface)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(THREAD_SAFE)

include_directories(
        /usr/local/include/SDL2
)

link_directories(
        /usr/local/lib
)

link_libraries(
        SDL2
)

add_executable(L06DrawOnSurface main.c)