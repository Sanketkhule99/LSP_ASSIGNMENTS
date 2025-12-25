#include<stdio.h>
#include <sys/stat.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    int iRet = 0;

    struct stat statObj;

    iRet = stat(argv[1], &statObj);

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        printf("Size : %ld\n",statObj.st_size);
        printf("Inode number : %lu\n",statObj.st_ino);
        printf("File Type: %u\n",statObj.st_mode);
        printf("Hard links: %lu\n",statObj.st_nlink);
        printf("Group Id: %d\n",statObj.st_gid);
        printf("User Id: %d\n",statObj.st_uid);
        printf("Block Size: %ld\n",statObj.st_blksize);
        printf("Last time acess: %ld\n",statObj.st_atime);
        printf("Last modification: %ld\n",statObj.st_mtime);
    }

    return 0;

}