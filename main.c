#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("/home/zhangliao", O_RDONLY);
	if (-1 == fd) {
		perror("open err");
		exit(-1);
	}

//	char buf[1024] = "";
//
//	read(fd, buf, sizeof(buf));
//
//	printf("%s\n", buf);

	int length = lseek(fd, 0, SEEK_END);

	printf("%d\n", length);
	return 0;
}
