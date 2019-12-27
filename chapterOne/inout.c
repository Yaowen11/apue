//
// Created by yaowen on 2019/12/23.
//

#include "../common/apue.h"
#include "../common/apue_error.h"
int main(void)
{
    int c;
    // getc 一次读取一个字符,读到输入的最后一个字节时，getc 返回常量 EOF
    while ((c = getc(stdin)) != EOF)
        // putc 将此字符写到标准输出
        if (putc(c, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    exit(0);
}