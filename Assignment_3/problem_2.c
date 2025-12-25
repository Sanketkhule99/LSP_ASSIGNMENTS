
#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 3)
    {
        printf("Usage: %s DirectoryName FileName\n", argv[0]);
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
        if(strcmp(entry->d_name, argv[2]) == 0)
        {
            printf("File found: %s/%s\n", argv[1], argv[2]);
            closedir(dp);
            return 0;
        }
    }

    printf("File not found\n");
    closedir(dp);
    return 0;
}
