#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int file_mode;
int work_on_fd(int x);
#endif
