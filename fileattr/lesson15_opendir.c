#include "common.h"

int main(int argc, char *argv[])
{
	char buf[256] = "";

	DIR *dir = opendir(buf);
	if (dir == NULL) {
		perror("opendir err");
		exit(-1);
	}
	
	closedir(dir);
	return 0;
}
