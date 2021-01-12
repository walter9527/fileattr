#include "common.h"



int main(int argc, char *argv[])
{
	int fd = open("book.txt.bak", O_RDWR);

 //	int ret = truncate("book.txt.bak", 10);
	
	ftruncate(fd, 10);

	char buf[128] = "";
	
	while(read(fd, buf, sizeof(buf))) {
		printf("%s", buf);
	}

	printf("\n");
	return 0;
}
