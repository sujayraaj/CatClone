#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int work_on(int x){return 0;}

int main(int argc, char **argv){
    char *name;
    int scriptfd;
    if(argv[0][0]=='.' && argv[0][1]=='/')
        name = argv[0]+2;
    else
        name = argv[0];

    if(argc>2){
        printf("Usage: %s [batchfile]\n",name);
    }
    else if(argc==2){
        scriptfd= open(argv[1],O_RDONLY);
        if(scriptfd < 0){
            perror("Error");
            return -1;
        }
    }
    else
        scriptfd = STDIN_FILENO;
    work_on(scriptfd);

    return 0;
}
