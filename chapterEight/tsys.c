//
// Created by z on 2019/12/30.
//

#include "../common/apue.h"
#include "../common/apue_error.h"

int main(int argc, char *argv[])
{
    int status;
    if (argc < 2) {
        err_quit("command-line argument required");
    }
    if ((status = system(argv[1])) < 0) {
        err_sys("system() error");
    }
    pr_exit(status);
    exit(0);
}