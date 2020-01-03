//
// Created by z on 2020/1/2.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

static void sig_usr(int);

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSER1");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSER2");
    }
    for (; ;) {
        pause();
    }
}

static void sig_usr(int signo)
{
    if (signo == SIGUSR1) {
        printf("received SIGUSR1\n");
    } else if (signo == SIGUSR2) {
        printf("received SIGUSER2\n");
    } else {
        err_dump("received signal %d\n", signo);
    }
}