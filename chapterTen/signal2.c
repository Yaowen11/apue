//
// Created by z on 2020/1/2.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

static void  sig_alrm(int);

int main(void)
{
    int n;
    char line[MAXLINE];
    if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
        err_sys("signal(SIGALRM) error");
    }
    alarm(10);
    if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0) {
        err_sys("read error");
    }
    alarm(0);
    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void sig_alrm(int signo)
{
    int i, j;
    volatile int k;
    printf("\nsig_int starting\n");
    for (i = 0; i < 300000; ++i) {
        for (j = 0; j < 4000; ++j) {
            k += i * j;
        }
    }
    printf("sig_int finished\n");
}