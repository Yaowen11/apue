//
// Created by 张耀文 on 2019/12/28.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }
    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}