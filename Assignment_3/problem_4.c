#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat statobj;
    char path[512];
    int count = 0;

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

        if(S_ISREG(statobj.st_mode) && statobj.st_size == 0)
        {
            unlink(path);
            printf("Deleted: %s\n", entry->d_name);
            count++;
        }
    }

    printf("Total empty files deleted: %d\n", count);

    closedir(dp);
    return 0;
}