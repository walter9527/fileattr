#include "common.h"

char *get_filename(int argc, char **argv) {
    char *pathname = NULL;
    if (argc > 3 || argc < 2 ){
        printf("命令个数有误， 请重新输入!\n");
        exit(-1);
    }

    if (argc == 3 && strcmp(argv[2], "-l") != 0 && strcmp(argv[3], "-l") != 0) {
        printf("命令输入有误， 请重新输入!\n");
        exit(-1);
    }

    if (argc >= 2) {
        pathname = argv[1];
    }

    return pathname;
}

// 获取文件类型
char get_file_type(const struct stat *statbuf) {
    // 文件类型
    mode_t mode = statbuf->st_mode;

    // 转换文件类型
    char file_type = S_ISBLK(mode) ? 'b' :
                     S_ISCHR(mode) ? 'c' :
                     S_ISDIR(mode) ? 'd' :
                     S_ISREG(mode) ? '-' :
                     S_ISLNK(mode) ? 'l' :
                     S_ISSOCK(mode) ? 's' :
                     S_ISFIFO(mode) ? 'p' : '0';

    return file_type;
}

// 获取文件权限
void get_file_permission(const struct stat *statbuf, char *pmss) {
    strcat(pmss, "rwxrwxrwx");

    int size = 9;
    for (int i = 0; i < size; ++i) {
        if (!(statbuf->st_mode & (1 << i))) {
            pmss[size - i] = '-';
        }
    }
}

// 从路径中提取文件名
char *get_file_name(const char *pathname) {
	char *file_name = strrchr(pathname, '/');
	if (file_name != NULL) {
		if (!strcmp(file_name, strchr(pathname, '/'))) {
			return file_name + 1;	
		}
	}
    return (char *)pathname;
}

void get_info(const char *pathname, int argc) {
    struct stat statbuf;

    int fd = open(pathname, O_RDONLY);
    if (fd == -1) {
	    perror("open err");
	    return;
    }	

    // 获取文件属性
//    my_stat(pathname, &statbuf);
//    my_lstat(pathname, &statbuf);
	// 获取文件描述符, 用于fstat 获取属性	
    my_lstat(pathname, &statbuf);
    if (argc == 2) {
	    char *file_name = get_file_name(pathname);
        printf("%s\n", file_name);
        return;
    }

    // 打印文件属性
    char buf[512];

    // 硬链接数
    nlink_t nlink = statbuf.st_nlink;
    // 用户id
    uid_t uid = statbuf.st_uid;
    // 组id
    gid_t gid = statbuf.st_gid;
    // 文件大小
    off_t size = statbuf.st_size;
    // 上次修改时间
    struct timespec mtim = statbuf.st_mtim;

    // 获取文件类型
    char file_type = get_file_type(&statbuf);

    // 获取文件名
    char *file_name = get_file_name(pathname);

	// 根据文件类型修饰文件名
    if (file_type == 'l') {
	    char buf[256] = "";
	    my_readlink(pathname, buf, sizeof(buf));
	  	strcat(file_name, " -> ");
	  	strcat(file_name, buf);
    } else if (file_type == 'd') {
		strcat(file_name, "/");
	}

    // 获取文件权限
    char pmss[11] = {file_type};
    get_file_permission(&statbuf, pmss);
	
    sprintf(buf, "%s %2lu %4u %4u %5ld %ld %s", pmss, nlink, \
            uid, gid, size, mtim.tv_sec, file_name);

    printf("%s\n", buf);
}

void iter_dir(const char *file_path, int argc)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;

    if ((dir = opendir(file_path)) != NULL) {
        while ((entry = readdir(dir))) {
            char sub_file[256] = "";
            sprintf(sub_file, "%s/%s", file_path, entry->d_name);
            get_info(sub_file, argc);
        }
        closedir(dir);
    } else {
		get_info(file_path, argc);
    }
}


int main(int argc, char *argv[]) {
    char *pathname = get_filename(argc, argv);
	
    iter_dir(pathname, argc);

    return 0;
}
