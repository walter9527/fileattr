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
extern int my_link(const char *oldpath, const char *newpath);
extern int my_unlink(const char *pathname);
extern int my_remove(const char *pathname);
extern int my_rename(const char *oldpath, const char *newpath);
extern int my_symlink(const char *oldpath, const char *newpath);
extern ssize_t my_readlink(const char *restrict path, char *restrict buf
	, size_t bufsize);
extern int my_chdir(const char *path);
extern int my_rmdir (const char *path);
extern DIR *my_opendir(const char *name); 
extern int chmod(const char *path, mode_t mode);

#endif //FILEATTR_COMMON_H
