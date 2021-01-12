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
