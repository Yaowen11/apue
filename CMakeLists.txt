cmake_minimum_required(VERSION 3.15)
project(apue C)

set(CMAKE_C_STANDARD 99)

add_executable(apue main.c apue.h ls.c)