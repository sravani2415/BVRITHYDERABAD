#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int fd;
	fd = creat("datafile.dat", S_IREAD | S_IWRITE);
	if(fd == -1)
		printf("Error in opening the datafile.dat\n");
	else
	{
		printf("datafile.dat is opened for read/write access\n");
		printf("datafile.dat is currently empty\n");
	}
	close(fd);
	exit(0);
}

