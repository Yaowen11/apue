//
// Created by yaowen on 2019/12/23.
//
#include "../common/apue.h"
#include "../common/apue_error.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    // 标准 I/O 函数 fgets 从标准输入一次读取一行，返回的每一行都以换行符终止接一个 null 字节。
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        // 替换末尾换行符
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        if ((pid == fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            // execlp 要求参数以 null 结束而不是换行符结束
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("wait pid error");
        }
        printf("%% ");
    }
    exit(0);
}


