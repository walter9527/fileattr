#include "common.h"

void read_file(int fd)
{
	char buf[128] = "";

	while(read(fd, buf, sizeof(buf))) {
		printf("%s", buf);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	int fd = open("hole_file.txt", O_RDWR | O_CREAT, 0644);

	//1. 使用 truncate 创建空洞文件
	//	my_ftruncate(fd, 8192);

	//2. 使用 lseek 创建空洞文件
	lseek(fd, 8192, SEEK_SET);

	// 使用 lseek 时必须要写一些内容进去，否则不能创建空洞文件
	write(fd, "hello", 5);

	lseek(fd, 0, SEEK_SET);
	read_file(fd);
	return 0;
}
