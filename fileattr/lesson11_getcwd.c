#include "common.h"



int main(int argc, char *argv[])
{
	char buf[256] = "";
	char *ret = getcwd(buf, sizeof(buf));
	
	printf("%d\n", buf);
	printf("%s\n", buf);
	printf("%d\n", ret);
	printf("%s\n", ret);
	return 0;	
}
		
		
		
