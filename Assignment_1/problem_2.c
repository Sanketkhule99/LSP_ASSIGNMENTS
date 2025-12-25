#include<stdio.h>
#include<fcntl.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    
   
    if(strcmp (argv[2],"R") == 0)
    {
        fd = open(argv[1], O_RDONLY | O_CREAT);

        if(fd == -1)
        {
            perror(argv[1]);
        }
        else
        {
            printf("Filed opened in Read mode only with fd : %d\n",fd);
        }
    }

    else if(strcmp (argv[2],"W") == 0)
    {
      fd = open(argv[1], O_WRONLY | O_CREAT);

        if(fd == -1)
        {
            perror(argv[1]);
        }
        else
        {
            printf("Filed opened in Write mode only with fd : %d\n",fd);
        }  
    }
    else if(strcmp (argv[2],"WR") == 0)
    {
      fd = open(argv[1], O_RDWR | O_CREAT);

        if(fd == -1)
        {
            perror(argv[1]);
        }
        else
        {
            printf("Filed opened in Read and Write mode with fd : %d\n",fd);
        }  
    }
    else if(strcmp (argv[2],"A") == 0)
    {
      fd = open(argv[1], O_APPEND | O_CREAT);

        if(fd == -1)
        {
            perror(argv[1]);
        }
        else
        {
            printf("Filed opened in Append mode  with fd : %d\n",fd);
        }  
    }
    
        
    return 0;
}