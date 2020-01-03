#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep1(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
        return(seconds);
    }
    alarm(seconds);
    pause();
    return(alarm(0));
}