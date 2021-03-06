//
// Created by z on 2019/12/29.
//

#include "../common/apue.h"
#include "../common/apue_error.h"
#include <sys/resource.h>

#define doit(name) pr_limits(#name, name)

static void pr_limits(char * , int);

int main(void)
{
#ifdef RLIMIT_AS
    doit(RLIMIT_AS);
#endif
    doit(RLIMIT_CORE);
    doit(RLIMIT_CPU);
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);
#ifdef RLIMIT_MEMLOCK
    doit(RLIMIT_MEMLOCK);
#endif

#ifdef RLIMIT_MSGQUEUE
    doit(RLIMIT_MSGQUEUE);
#endif

    doit(RLIMIT_NOFILE);

#ifdef RLIMIT_NPROC
    doit(RLIMIT_NPROC);
#endif

#ifdef RLIMIT_NPTS
    doit(RLIMIT_NPTS);
#endif

#ifdef RLIMIT_RSS
    doit(RLIMIT_RSS);
#endif

#ifdef RLIMIT_SBSIZE
    doit(RLIMIT_SBSIZE);
#endif

#ifdef RLIMIT_SIGPENDING
    doit(RLIMIT_SIGPENDING);
#endif

    doit(RLIMIT_STACK);
    struct rlimit stackLimit;
    stackLimit.rlim_cur = 8388608 * 2;
    stackLimit.rlim_max = 8388608 * 4;
    if (setrlimit(RLIMIT_STACK, &stackLimit) == 0) {
        doit(RLIMIT_STACK);
    } else {
        err_sys("no setting process stack size");
    }

#ifdef RLIMIT_SWAP
    doit(RLIMIT_SWAP);
#endif

#ifdef RLIMT_VEME
    doie(RLIMIT_VMEM);
#endif

    exit(0);
}

static void pr_limits(char *name, int resource)
{
    struct rlimit limit;
    unsigned long long lim;
    if (getrlimit(resource, &limit) < 0) {
        err_sys("getrlimit error for %s", name);
    }
    printf("%-14s ", name);
    if (limit.rlim_cur == RLIM_INFINITY) {
        printf("(infinite) ");
    } else {
        lim = limit.rlim_cur;
        printf("%10lld ", lim);
    }
    putchar((int)'\n');
}