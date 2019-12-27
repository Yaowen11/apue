cmake_minimum_required(VERSION 3.15)
project(apue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(apue
        common/apue.h
        common/apue_error.h
        common/apue_log.h
        chapterOne/myls.c
        main.c chapterOne/copy.c chapterOne/inout.c chapterOne/dumpProcessId.c chapterOne/execInStdIn.c main.c chapterOne/err.c chapterOne/dumpUserGroupID.c chapterOne/signal.c chapterOne/wrfile.c chapterTwo/sysconf.c chapterTwo/pathMax.c chapterTwo/openFile.c chapterThree/checkLseek.c "chapterThree/cavityFile.c" chapterThree/ioEffect.c chapterThree/changFdAttribute.c)
