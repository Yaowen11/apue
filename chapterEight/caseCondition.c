//
// Created by z on 2019/12/30.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

static void charatatime(char *);

int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
}

static void charatatime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout, NULL); // set unbuffered
    for (ptr = str; (c = *ptr++); ) {
        putc(c, stdout);
    }
}