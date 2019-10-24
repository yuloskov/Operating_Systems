#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
    DIR *dirptr = opendir("tmp");

    if (dirptr == NULL) { return -1; }
    
    struct dirent *dp;
    ino_t Nodes[127];
    char *names[255];
    int i = 0;

    while ((dp = readdir(dirptr)) != NULL) {
        Nodes[i] = dp->d_ino;
        names[i++] = dp->d_name;
    }
    int n = i;
    int found = 0;
    for (i = 0; i < n; i++){
        found = 0;
        for (int j = i+1; j < n; j++){
            if (Nodes[i]==Nodes[j] && found == 0){
                printf("Found a link! %s %s ", names[i], names[j]);
                found = 1;
            } else if (found == 1){
                printf("%s\n",names[j]);
            }
        }
    }
    return 0;
}