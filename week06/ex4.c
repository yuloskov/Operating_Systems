#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("SIGUSR1 received\n");
    else if (signo == SIGKILL)
        printf("SIGKILL received\n");
    else if (signo == SIGSTOP)
        printf("SIGSTOP received\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    
    while(1) 
        sleep(1);
    return 0;
}
/*The output is the following:
can't catch SIGKILL
can't catch SIGSTOP
SIGUSR1 received

The system cannot register SIGKILL and SIGSTOP because, by definition, this signals cannot be caught. 
*/