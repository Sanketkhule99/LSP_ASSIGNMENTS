#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0;
    char Buffer[100];

    if(argc != 2)
    {
        printf("Usage: %s FileName\n", argv[0]);
        return -1;
    }

    printf("Enter string to write:\n");
    fgets(Buffer, sizeof(Buffer), stdin);

    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }

    iRet = write(fd, Buffer, strlen(Buffer));

    printf("%d bytes written successfully\n", iRet);

    close(fd);
    return 0;
}