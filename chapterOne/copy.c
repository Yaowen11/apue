//
// Created by yaowen on 2019/12/23.
//

#include "../apue.h"
#include "../apue_error.h"
#define BUFFSIZE 8192

int main(void)
{
    int n;
    char buf[BUFFSIZE];
    // read函数返回读得的字节数，此值用作要写的字节数。当到达文件的尾端时返回0 ,如果发生了一个读错误返回－1。出错时大多数系统函数返回－1
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        // 写入标准输出
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");
    if (n < 0)
        err_sys("read error");

    exit(0);

}