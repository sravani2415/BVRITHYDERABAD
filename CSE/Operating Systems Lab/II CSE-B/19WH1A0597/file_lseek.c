#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int n, f;
	char buff[10];
	f = open("sample.c", O_RDWR);
	read(f, buff, 10);
	write(1, buff, 10);
	lseek(f, 5, SEEK_CUR); // SKIPS 5 CHARACTERS FROM CURRENT POSITION
	read(f, buff, 10);
	write(1, buff, 10);
	printf("\n");
	close(f);
}

