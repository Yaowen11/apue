//
// Created by 张耀文 on 2019/12/27.
//

#include "../common/apue.h"

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek\n");
    } else {
        printf("seek OK\n");
    }
    exit(0);
}