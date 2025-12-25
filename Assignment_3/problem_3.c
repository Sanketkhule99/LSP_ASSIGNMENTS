#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat statobj;
    char src[512], dest[512];
    int count = 0;

    if(argc != 3)
    {
        printf("Usage: %s SourceDir DestDir\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(src, "%s/%s", argv[1], entry->d_name);
        sprintf(dest, "%s/%s", argv[2], entry->d_name);

        stat(src, &statobj);

        if(S_ISREG(statobj.st_mode))
        {
            rename(src, dest);
            count++;
        }
    }

    printf("Total files moved: %d\n", count);

    closedir(dp);
    return 0;
}