
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include <stdlib.h>


#define SIZE_BUFFER 100

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0;
    char Buffer[SIZE_BUFFER];

    memset(Buffer,'\0',sizeof(SIZE_BUFFER));

    if(argc < 3)
    {
        printf("Please provide number of bytes you want read\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd < 1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    
    iRet = read(fd,Buffer,atoi(argv[2]));
    
    if(iRet < 1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    else
    {   
        Buffer[iRet + 1] = '\0';
        printf("%u Bytes get read sucessfully\n",iRet);
        printf("%s\n",Buffer);
    }

    close(fd);

    return 0;
}
