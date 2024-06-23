cmake_minimum_required(VERSION 3.10)

project(hexdump)

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(hexdump ${SOURCES})
target_include_directories(hexdump PUBLIC "${PROJECT_BINARY_DIR}/include")

install(TARGETS hexdump DESTINATION bin)
