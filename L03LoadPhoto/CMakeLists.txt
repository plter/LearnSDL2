cmake_minimum_required(VERSION 3.17)
project(L03LoadPhoto C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(THREAD_SAFE)

include_directories(
        /usr/local/include/SDL2
)

link_directories(
        /usr/local/lib
)

link_libraries(
        SDL2
        SDL2_image
)

add_executable(L03LoadPhoto main.c)