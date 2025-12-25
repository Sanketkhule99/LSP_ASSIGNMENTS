#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat statobj;
    char path[512];
    char LargestFile[256];
    long MaxSize = 0;

    if(argc != 2)
    {
        printf("Usage: %s DirectoryName\n", argv[0]);
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
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &statobj);

        if(S_ISREG(statobj.st_mode))
        {
            if(statobj.st_size > MaxSize)
            {
                MaxSize = statobj.st_size;
                strcpy(LargestFile, entry->d_name);
            }
        }
    }

    printf("Largest File: %s\n", LargestFile);
    printf("Size: %ld bytes\n", MaxSize);

    closedir(dp);
    return 0;
}