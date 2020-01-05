#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("pthread destructor iterations: %ld\n", sysconf(_SC_THREAD_DESTRUCTOR_ITERATIONS));
    printf("pthread key max: %ld\n", sysconf(_SC_THREAD_KEYS_MAX));
    printf("pthread stack min: %ld\n", sysconf(_SC_THREAD_STACK_MIN));
    printf("pthread threads max: %ld\n", sysconf(_SC_THREAD_THREADS_MAX));
}