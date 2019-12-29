//
// Created by 张耀文 on 2019/12/28.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int main(void)
{
    if (chdir("/tmp") < 0) {
        err_sys("chdir failed");
    }
    printf("chdir to /tmp succeeded\n");
    exit(0);
}
