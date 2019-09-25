#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{   
    int     fd[2], status;
    pid_t   childpid1;
    pid_t   childpid2;
    pid_t   receivedid;

    pipe(fd);
    if((childpid1 = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if(childpid1 == 0)
    {   
        close(fd[1]);

        read(fd[0], &receivedid, sizeof(pid_t));
        printf("The id of second child process received by the first one: %d\n", receivedid);
        
        sleep(3);
        printf("The first child stopping the second one...\n");
        kill(receivedid, SIGSTOP);
    }
    else
    {
        if((childpid2 = fork()) == -1)
        {
            perror("fork");
            exit(1);
        }

        if (childpid2 == 0){
            close(fd[0]);
            int curid = getpid();
            write(fd[1], &curid, sizeof(pid_t));
            while (1)
            {
                printf("Child 2 is alive\n");
                sleep(1);
            }
            
            exit(0);
        } else {
            printf("Status of the first process: %s\n", status != 0 ? "process running." : "process stopped.");
            waitpid(childpid1, &status, WUNTRACED);
            printf("Status of the first process: %s\n", status != 0 ? "process running." : "process stopped.");            
        }
    }
    
    return(0);
}