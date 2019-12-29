//
// Created by 张耀文 on 2019/12/28.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int main(void)
{
    char buf[MAXLINE];
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            err_sys("output error");
        }
    }
    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}