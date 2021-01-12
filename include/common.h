#ifndef FILEATTR_COMMON_H
#define FILEATTR_COMMON_H

//#define FILE_DEMO "file.txt"


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>

#include <errno.h>

#include <stdlib.h>

#include <string.h>

#include <dirent.h>

#include <fcntl.h>

extern int my_stat(const char *pathname, struct stat *statbuf);
extern int my_lstat(const char *pathname, struct stat *statbuf);
extern int my_fstat(int fd, struct stat *statbuf);
extern int my_truncate(const char *path, off_t length);
extern int my_ftruncate(int filds, off_t length);

#endif //FILEATTR_COMMON_H
