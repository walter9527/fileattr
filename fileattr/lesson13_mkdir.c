#include "common.h"

void print_current_path()
{
	char path[256] = "";
	getcwd(path, sizeof(path));

	printf("%s\n", path);
}

int main(int argc, char *argv[])
{
	print_current_path();
	
	char buf[256] = "/home/zhangliao/abc";

	int ret = mkdir(buf, 0775);
	if (-1 == ret) {
			perror("mkdir err");
			exit(-1);
	}

	my_chdir(buf);
	
	print_current_path();
}
		
		
