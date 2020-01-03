#include "../common/apue.h"
#include "../common/apue_error.h"
#include <signal.h>

unsigned int sleep1(unsigned int);
void sig_int(int);

int main(void)
{
    unsigned int unslept;
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal(SIGINT) error");
    }
    unslept = sleep1(5);
    printf("sleep1 returned: %u\n", unslept);
    exit(0);
}
