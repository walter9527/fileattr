#include "common.h"

void is_err(ssize_t ret, const char *fun_name) {
    char buf[strlen(fun_name) + 5];
    memset(buf, 0, sizeof(buf));

    strcat(buf, fun_name);
    strcat(buf, " err");

    if (ret == -1) {
        perror(buf);
        exit(-1);
    }
}

int my_stat(const char *pathname, struct stat *statbuf) {
    int ret = stat(pathname, statbuf);
    is_err(ret, "stat");
    return ret;
}

int my_lstat(const char *pathname, struct stat *statbuf) {
    int ret = lstat(pathname, statbuf);
    is_err(ret, "lstat");
    return ret;
}

int my_fstat(int fd, struct stat *statbuf) {
    int ret = fstat(fd, statbuf);
    is_err(ret, "fstat");
    return ret;
}

int my_truncate(const char *path, off_t length)
{
	int ret = truncate(path, length);
	is_err(ret, "truncate");
	return ret;
}

int my_ftruncate(int filds, off_t length)
{
	int ret = ftruncate(filds, length);
	is_err(ret, "ftruncate");
	return ret;
}

int my_link(const char *oldpath, const char *newpath)
{
	int ret = link(oldpath, newpath);
	is_err(ret, "link");
	return ret;
}

int my_unlink(const char *pathname)
{
	int ret = unlink(pathname);
	is_err(ret, "unlink");
	return ret;
}

int my_remove(const char *pathname)
{
	int ret = remove(pathname);
	is_err(ret, "remove");
	return ret;
}

int my_rename(const char *oldpath, const char *newpath)
{
	int ret = rename(oldpath, newpath);
	is_err(ret, "rename");
	return ret;
}

int my_symlink(const char *oldpath, const char *newpath)
{
	int ret = symlink(oldpath, newpath);
	is_err(ret, "symlink");
	return ret;
}


ssize_t my_readlink(const char *restrict path, char *restrict buf, size_t bufsize)
{
	ssize_t ret = readlink(path, buf, bufsize);
	is_err(ret, "readlink");
	return ret;
}

int my_chdir(const char *path) 
{
	int ret = chdir(path);
	is_err(ret, "chdir");
	return ret;
}

int my_rmdir (const char *path)
{
	int ret = rmdir(path);
	is_err(ret, "rmdir");
	return ret;
}

DIR *my_opendir(const char *name) 
{
	DIR *dirp = opendir(name);
	if (dirp == NULL) {
		perror("opendir err");
		exit(-1);
	}
	return dirp;
}

int my_chmod(const char *path, mode_t mode) 
{
	int ret = chmod(path, mode);
	is_err(ret, "chmod");
	return ret;
}
