#include "common.h"

int test_unlink(const char *pathname)
{
	int ret = unlink(pathname);
	if (ret == -1) {
		perror("unlink err");
		exit(-1);
	}
	return ret;
}

void tmpfile_unlink(const char *pathname)
{
	int fd = open(pathname, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		perror("open err");
		exit(-1);
	}

	unlink(pathname);
	
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
//	test_unlink(argv[1]);
	
	/* 使用 unlink 实现临时文件 */
	tmpfile_unlink("tmpfile");
	return 0;
}
