//
// Created by yaowen on 2019/12/23.
//

#include "../common/apue.h"

int main(void)
{
    // getpid 得到其进程 ID, 返回一个 pid_t 数据类型, 可以转为 long 型
    printf("hello world from process ID %ld\n", (long) getpid());
    exit(0);
}

