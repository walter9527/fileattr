#include "common.h"


int main(int argc, char *argv[])
{
	
	int ret = symlink(argv[1], argv[2]);
	if (-1 == ret) {
		perror("symlink err");
		exit(-1);
	}
	return 0;
}
