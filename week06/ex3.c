#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("SIGINT received\n");
}

int main(void)
{
  signal(SIGINT, sig_handler);
  while(1) 
    sleep(1);
  return 0;
}