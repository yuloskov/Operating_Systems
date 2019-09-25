
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int     fd[2];
    char    string[] = "Innopolis\n";
    char    readbuffer[80];

    pipe(fd);
    write(fd[1], string, (strlen(string)+1));
    read(fd[0], readbuffer, sizeof(readbuffer));
    printf("Received string: %s", readbuffer);
    
    return(0);
}