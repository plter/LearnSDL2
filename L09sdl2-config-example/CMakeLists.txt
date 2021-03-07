cmake_minimum_required(VERSION 3.0.0)
project(sdl2_config_example VERSION 0.1.0)

include_directories(/usr/local/include)

execute_process(
    COMMAND sdl2-config --static-libs
    OUTPUT_VARIABLE sdl2_static_libs_output
)

separate_arguments(sdl2_static_libs NATIVE_COMMAND ${sdl2_static_libs_output})


add_executable(sdl2_config_example main.c)

target_link_options(sdl2_config_example PRIVATE ${sdl2_static_libs})
