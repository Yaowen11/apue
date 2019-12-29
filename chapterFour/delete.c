//
// Created by 张耀文 on 2019/12/28.
//

#include "../common/apue.h"
#include "../common/apue_error.h"
#include <fcntl.h>

int main(void)
{
    if (open("tempfile", O_RDWR) < 0) {
        err_sys("open error");
    }
    if (unlink("tempfile") < 0) {
        err_sys("unlink error");
    }
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    exit(0);
}
