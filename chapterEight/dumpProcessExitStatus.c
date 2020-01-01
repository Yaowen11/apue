//
// Created by z on 2019/12/30.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int main(void)
{
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        exit(7);
    }
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        abort();
    }
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        err_sys("wait error");
    } else if (pid == 0) {
        status = status / pid;
    }
    if (wait(&status) != pid) {
        err_sys("wait error");
    }
    pr_exit(status);

    exit(0);
}