#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char * argv[]){
	int ret;

	ret = mknod("/dev/testdev1", S_IFCHR | 00600 | 00060 | 00006, (240<<8)|1);
	if (ret<0){
		perror("mknod()");
		return 1;
	}

	ret = open("/dev/testdev2", O_RDWR);
	if (ret<0){
		perror("open()");
		return EPERM;
//		return ENOENT;
	}

	return 0;
}
