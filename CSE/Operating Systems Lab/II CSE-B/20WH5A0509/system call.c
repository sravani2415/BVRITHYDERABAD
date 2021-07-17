#include&lt;unistd.h&gt;
#include&lt;fcntl.h&gt;
#include&lt;sys/types.h&gt;
#include&lt;sys/stat.h&gt;
int main()
{
int n,f;
char buff[10];
f=open(&quot;Interview.c&quot;,O_RDWR);
read(f,buff,10);
write(1,buff,10);
lseek(f,5,SEEK_CUR);//skips 5 characters from the current position
read(f,buff,10);
write(1,buff,10);
close(f);
}
