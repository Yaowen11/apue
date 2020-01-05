#include "../common/apue_error.h"
#include <pthread.h>
#include <stdio.h>

static pthread_attr_t attr;
static int detach_attr, err;
static void dump_pthread_attr_detach();
static void set_pthread_detach();

int main()
{
    if ((err = pthread_attr_init(&attr)) != 0) {
        err_sys("pthread attr init faild err is %d\n", err);
    }
    dump_pthread_attr_detach();
    if (detach_attr == PTHREAD_CREATE_JOINABLE) {
        detach_attr = PTHREAD_CREATE_DETACHED;
        set_pthread_detach();
    }
    dump_pthread_attr_detach();
    if (pthread_attr_destroy(&attr) == 0) {
        printf("destroy pthread attr\n");
    }
    dump_pthread_attr_detach();
    exit(0);
}

void dump_pthread_attr_detach()
{
    if ((err = pthread_attr_getdetachstate(&attr, &detach_attr)) != 0)  {   
        err_sys("can't get pthread detach state: %d\n", err);
    }
    if (detach_attr == PTHREAD_CREATE_DETACHED) {
        printf("pthread detach state is %d, detach value is PTHREAD_CREATE_DETACHED\n", detach_attr);
    }
    if (detach_attr == PTHREAD_CREATE_JOINABLE) {
        printf("pthread default detach status is %d, detach value is PTHREAD_CREATE_JOINABLE\n", detach_attr);
    }
}

void set_pthread_detach()
{
    if ((err = pthread_attr_setdetachstate(&attr, detach_attr)) == 0) {
        printf("success pthread detach state is %d\n", detach_attr);
    } else {
        err_sys("can't set pthread detach state: %d\n", err);
    }
}

// 以分离状态创建线程的函数
int makeDetachedThread(void *(*fn)(void *), void *arg)
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;
    err = pthread_attr_init(&attr);
    if (err != 0) {
        return(err);
    }
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err == 0) {
        err = pthread_create(&tid, &attr, fn, arg);
    }
    pthread_attr_destroy(&attr);
    return(err);
}