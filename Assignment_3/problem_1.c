#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[BUFFER_SIZE];

    if(argc != 3)
    {
        printf("Usage: %s SourceFile DestFile\n", argv[0]);
        return -1;
    }

    fdSrc = open(argv[1], O_RDONLY);
    fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if(fdSrc == -1 || fdDest == -1)
    {
        perror("open");
        return -1;
    }

    while((iRet = read(fdSrc, Buffer, BUFFER_SIZE)) > 0)
    {
        write(fdDest, Buffer, iRet);
    }

    printf("File copied successfully\n");

    close(fdSrc);
    close(fdDest);
    return 0;
}