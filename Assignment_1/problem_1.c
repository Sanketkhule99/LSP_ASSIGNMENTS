#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
    int fd = 0;

    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        perror("Demo.txt");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
    }

    return 0;
}