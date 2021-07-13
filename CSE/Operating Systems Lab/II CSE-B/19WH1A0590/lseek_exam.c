#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
    int n,f;
    char buff[100];
    f=open("Interview.c",O_RDWR);
    read(f,buff,10);
    write(1,buff,10);
    lseek(f,5,SEEK_CUR);
    read(f,buff,10);
    write(1,buff,10);
    close(f);
}
