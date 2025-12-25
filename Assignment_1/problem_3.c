
#include<stdio.h>
#include<fcntl.h>
#include <string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int iRet = 0;
    
    if(strcmp(argv[2],"R") == 0)
    {
        iRet = access(argv[1],R_OK);
        if(iRet == -1)
        {
            printf("NOT ACESSIBLE\n");
        }
        else
        {
            printf("ACCESSIBLE\n");
        }     
    }
    else if(strcmp(argv[2],"W") == 0)
    {
        iRet = access(argv[1],W_OK);
        if(iRet == -1)
        {
            printf("NOT ACESSIBLE\n");
        }
        else
        {
            printf("ACCESSIBLE\n");
        }     
    }
    else if(strcmp(argv[2],"X") == 0)
    {
        iRet = access(argv[1],X_OK);
        if(iRet == -1)
        {
            printf("NOT ACESSIBLE\n");
        }
        else
        {
            printf("ACCESSIBLE\n");
        }     
    }  
    
        
    return 0;
}
