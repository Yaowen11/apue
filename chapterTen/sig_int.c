#include <stdio.h>

void sig_int(int signo)
{
    int i,j;
    volatile int k;
    printf("\nsig_int starting\n");
    for (i = 0; i < 300000; i++) {
        for (j = 0; j < 4000; j++) {
            k += i * j;
        }
    }
    printf("sig_int finished\n");
}