#include "common.h"

void rmpath(char *path) {

	int ret = rmdir(path);
	if (ret == -1) {
		perror("rmdir err");
		exit(-1);
	}
}

void recursive_rmpath(char *path) {
	DIR *dir = NULL;	
	struct dirent *entry = NULL;

	if ((dir = opendir(path)) != NULL) {
		while ((entry = readdir(dir))) {
			if (strcmp(entry->d_name, ".") && strcmp(entry->d_name,"..")) {
				char buf[256] = "";
				sprintf(buf, "%s/%s", path, entry->d_name);
				if (entry->d_type == DT_DIR) {
					recursive_rmpath(buf);
				} else {
					printf("%s\n", buf);
					my_unlink(buf);
				}
			}
		}
	}

	printf("%s\n", path);
	int ret = rmdir(path);
	if (-1 == ret) {
		perror("rmdir err");
	}

	closedir(dir);
}

int main(int argc, char *argv[])
{
	char path[256] = "/home/zhangliao/workspace/aaa";
	//rmdir(path);

	recursive_rmpath(path);

	return 0;
}
