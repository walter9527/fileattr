#include "common.h"

void tmpfile_remove(const char *pathname)
{
	int fd = open(pathname, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		perror("open err");
		exit(-1);
	}

	remove(pathname);
	
	// 此时文件仍然可以操作，一直持续到进程结束
	write(fd,"hello world", 11);

	lseek(fd, 0, SEEK_SET);

	char buf[128] = "";
	
	while (read(fd, buf, sizeof(buf))) {
		printf("%s", buf);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int ret = remove(argv[1]);
	if (-1 == ret) {
		perror("remove err");
		exit(-1);
	}
	
	/* remove 在删除普通文件时，跟 unlink 一样 */
//	tmpfile_remove("tmpfile");
	return 0;
}
