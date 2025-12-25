#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

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
        if(strcmp(entry->d_name,".") != 0 &&
           strcmp(entry->d_name,"..") != 0)
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
    return 0;
}