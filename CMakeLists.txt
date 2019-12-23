cmake_minimum_required(VERSION 3.15)
project(apue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(apue
        apue.h
        apue_error.h
        apue_log.h
        chapterOne/myls.c
        main.c chapterOne/copy.c chapterOne/inout.c chapterOne/dumpProcessId.c chapterOne/execInStdIn.c main.c chapterOne/err.c chapterOne/dumpUserGroupID.c chapterOne/signal.c)
