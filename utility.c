#include "utility.h"

char *dirname = NULL;
char *user = NULL;
char *hostname = NULL;
char *termstr = NULL;

#define BUFSIZE 80

static int process( char* readbuf,int read_size ){
    if( *readbuf != '\n')
    write(STDOUT_FILENO, readbuf, read_size);
}

int work_on_fd(int in_fd){
    char readbuf[BUFSIZE];
    int read_size;
    int termlen=strlen(termstr),dirlen;

    while(1){

    if( !file_mode ){
	getcwd(dirname,PATH_MAX);
        strcat(dirname,"$");
        dirlen = strlen(dirname);
        write(STDOUT_FILENO, termstr, termlen);
        write(STDOUT_FILENO, dirname, dirlen);

    }

        read_size = read(in_fd, readbuf, BUFSIZE);
        if( read_size == 0 )
            return 0;
        else if ( read_size < 0 ){
            perror("Error");
            return -1;
        }
        process(readbuf,read_size);
    }
return 0;
}
