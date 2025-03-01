cmake_minimum_required(VERSION 3.10)
project(console_utility C)

set(CMAKE_C_STANDARD 99)

add_executable(console_utility
    src/main.c
    src/users.c
    src/processes.c
    src/log.c
    src/errors.c
    src/help.c
)
