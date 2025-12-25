#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat statobj;
    char path[512];

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
        lstat(path, &statobj);

        if(S_ISREG(statobj.st_mode))
            printf("Regular File: %s\n", entry->d_name);
        else if(S_ISDIR(statobj.st_mode))
            printf("Directory: %s\n", entry->d_name);
        else if(S_ISLNK(statobj.st_mode))
            printf("Link: %s\n", entry->d_name);
        else if(S_ISFIFO(statobj.st_mode))
            printf("FIFO: %s\n", entry->d_name);
        else if(S_ISCHR(statobj.st_mode))
            printf("Character Device: %s\n", entry->d_name);
        else if(S_ISBLK(statobj.st_mode))
            printf("Block Device: %s\n", entry->d_name);
        else if(S_ISSOCK(statobj.st_mode))
            printf("Socket: %s\n", entry->d_name);
    }

    closedir(dp);
    return 0;
}