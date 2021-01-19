#include "common.h"

int main(int argc, char *argv[])
{
	char buf[256] = "/home/zhangliao";

	DIR *dirp = my_opendir(buf);

	struct dirent *entry = NULL;

	while ((entry = readdir(dirp)))	{
		printf("%llu -- %s\n", entry->d_ino, entry->d_name);
	}
	
	if (errno != 0) {
		printf("readdir err");
		exit(-1);
	}

	closedir(dirp);
	return 0;
}
