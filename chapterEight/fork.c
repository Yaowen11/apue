//
// Created by z on 2019/12/30.
//
#include "../common/apue.h"
#include "../common/apue_error.h"

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
    int var;
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        err_sys("write error");
    }
    printf("before fork\n");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        globvar++;
        var++;
        fprintf(stdout, "child process pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    } else {
        printf("parent pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    };
    exit(0);
}
