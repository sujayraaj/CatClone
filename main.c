#include"utility.h"

extern char *dirname;
extern char *user;
extern char *hostname;
extern char *termstr;


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
        file_mode = 1;
    }
    else {
        scriptfd = STDIN_FILENO;
        file_mode = 0;
    }


    dirname = (char*) malloc(PATH_MAX);
    user=getenv("USER");
    termstr = (char*) malloc(PATH_MAX+80);
    strcat(termstr,user);
    strcat(termstr,"@");
    strcat(termstr,":");

    work_on_fd(scriptfd);

    close(scriptfd);

    return 0;
}
