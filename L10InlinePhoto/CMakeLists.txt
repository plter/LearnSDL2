cmake_minimum_required(VERSION 3.17)
project(L10InlinePhoto C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(THREAD_SAFE)

include_directories(
        /usr/local/include
)

execute_process(
    COMMAND sdl2-config --static-libs
    OUTPUT_VARIABLE sdl2_static_libs_output
)

separate_arguments(sdl2_static_libs NATIVE_COMMAND ${sdl2_static_libs_output})

add_executable(L10InlinePhoto main.c)

target_link_options(L10InlinePhoto PRIVATE ${sdl2_static_libs})