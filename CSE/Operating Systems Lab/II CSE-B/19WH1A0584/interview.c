#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int n,f;
	char buff[50];
	f=open("Interview.c",O_RDWR);
	read(f,buff,26);
	write(1,buff,26);
	
	lseek(f,5,SEEK_CUR);
	read(f,buff,26);
	write(1,buff,26);
	close(f);
}
