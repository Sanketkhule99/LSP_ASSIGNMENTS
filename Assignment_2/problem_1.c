#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0, iTotal = 0;
    char Buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        printf("Usage: %s FileName\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }

    while((iRet = read(fd, Buffer, BUFFER_SIZE)) > 0)
    {
        write(1, Buffer, iRet);
        iTotal += iRet;
    }

    printf("\nTotal bytes read: %d\n", iTotal);

    close(fd);
    return 0;
}