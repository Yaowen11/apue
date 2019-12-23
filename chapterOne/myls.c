//
// Created by 张耀文 on 2019/12/21.
//

#include "apue.h"
#include <dirent.h>
#include "apue_error.h"

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        err_quit("usage: ls dirctory_name");
    // opendir函数返回指向 DIR 结构的指针
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    // 并将该指针传向 readdir 函数返回一个指向 dirent 结构指针,无目录项时返回 null 指针
    while ((dirp = readdir(dp)) != NULL)
        // 每个目录项的名字
        printf("%s\n", dirp->d_name);
    closedir(dp);
    exit(0);
}