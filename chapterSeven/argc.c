//
// Created by z on 2019/12/29.
//

#include "../common/apue.h"

int main(int argc, char *argv[])
{
    int i;
    // ISO C 和 POSIX.1 要求 `argv[argc]` 是一个空指针
    for (i = 0; argv[i] != NULL; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    // 环境表
    extern char **environ;
    for (int j = 0; j < sizeof(environ); ++j) {
        printf("%s\n", environ[j]);
    }
    exit(0);
}