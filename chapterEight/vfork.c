//
// Created by z on 2019/12/30.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int globvar = 6;

int main(void)
{
    int var;
    pid_t pid;
    var = 88;
    printf("befor vfork\n");
    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) {
        globvar++;
        var++;
        _exit(0);
    }
    printf("pid = %ld, glob = %d, var = %d\n", (long) getpid(), globvar, var);
    exit(0);
}
