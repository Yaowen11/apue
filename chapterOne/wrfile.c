//
// Created by 张耀文 on 2019/12/25.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    FILE *fd;
    char msg[] = "Hello world";
    char buf[20];
    fd = fopen("test.txt", "w+");
    if (fd == NULL) {
        printf("The file error");
    }
    fwrite(msg, strlen(msg), 1, fd);
    fflush(fd);
    fseek(fd, 0, SEEK_SET);
    fread(buf, strlen(msg), 1, fd);
    buf[strlen(msg)] = '\0';
    printf("buf = %s\n", buf);
    printf("strlen(buf) = %lu\n", strlen(buf));
    fclose(fd);
}