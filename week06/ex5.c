
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    pid_t   childpid;

    if((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if(childpid == 0)
    { 
        while (1)
        {
            printf("I am alive\n");
            sleep(1);
        }
        
    }
    else
    {
        sleep(10);
        kill(childpid, SIGTERM); 
    
    }
    
    return(0);
}