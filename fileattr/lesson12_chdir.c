#include "common.h"


int main(int argc, char *argv[])
{
	char buf[256] = "";
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);

	char *target_path = "/home/zhangliao";
	chdir(target_path);

	memset(buf, 0, sizeof(buf));

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);

	return 0;
}
		
		
