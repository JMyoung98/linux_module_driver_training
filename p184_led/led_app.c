#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#define DEVICE_FILENAME "/dev/leddev"
void print_led(unsigned char led)
{
	int i;
	puts("1:2:3:4");
	for(i=0;i<=3;i++)
	{
		if(led & (0x01 << i))
		putchar('O');
		else
		putchar('X');
		if(i < 3 )
		putchar(':');
		else
		putchar('\n');
	}
	return;
}
int main(int argc,char* argv[])
{
	int dev;
	char buff=atoi(argv[1]);
	int ret;
	printf("1) device file open\n");	
	dev = open(DEVICE_FILENAME, O_RDWR | O_NDELAY);
	if(dev>=0)
	{
		printf("4) write function call \n");
		ret = write(dev,&buff,sizeof(buff));	
		printf("ret = %08X\n",buff);
		buff=0;
		ret = read(dev,&buff,sizeof(buff));
		print_led(buff);
	}
	else
		perror("open");
		return 0;
	}
