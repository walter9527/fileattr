#include "common.h"



int main(int argc, char *argv[])
{
	if (open("pmain", O_RDONLY) == -1) {
		my_symlink("main.c", "pmain");
	}


	char file_name[256] = "";

	ssize_t ret = readlink("pmain", file_name, 256);
	if (-1 == ret) {
		perror("readlink err");
		exit(-1);
	}

	printf("%s\n", file_name);
	return 0;
}
