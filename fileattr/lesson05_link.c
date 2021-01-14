#include "common.h"


int main(int argc, char *argv[])
{
	int ret = link(argv[1], argv[2]);
	if (ret == -1) {
		perror("link err");
		exit(-1);
	}
	return 0;
}
