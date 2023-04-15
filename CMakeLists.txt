cmake_minimum_required(VERSION 3.18)
project(dino)

add_executable(dino src/main.c)
target_link_libraries(dino PRIVATE SDL2)
