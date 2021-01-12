#include "common.h"



int main(int argc, char *argv[])
{
	mode_t old  = umask(0); // 修改权限掩码，使程序可以获得满级权限
	int fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	if (fd == -1) {
		perror("error open");
		exit(-1);
	}

	struct stat statbuf;

	int ret = fstat(fd, &statbuf);
	if (ret == -1) {
		perror("fstat err");
		exit(-1);
	}

	char permission[] = "rwxrwxrwx";

	for (int i = 0; i < 9; i++) {
		if (!(statbuf.st_mode & 1 << i)) {
			permission[8 - i] = '-';
		}
	}

	umask(old);     // 也可以将掩码还原

	printf("%s\n", permission); // rwxrwxrwx

}
