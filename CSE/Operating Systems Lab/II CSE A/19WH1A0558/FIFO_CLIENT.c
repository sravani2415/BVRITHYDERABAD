//Create a text file as "fifo_twoway.txt" and enter some sample text as below in the file
//content of fifo_twoway.txt file
//LINUX
//OS
//Memory

//FIFO client side
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "fifo_twoway"

int main() {
	int fd;
	int end_process;
	int stringlen;
	int read_bytes;
	char read_buf[80];
	char end_str[5];

	printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
	fd = open(FIFO_FILE, O_CREAT|O_RDWR);
	strcpy(end_str, "end");

	while (1) {
		printf("Enter a string: ");
		fgets(read_buf, sizeof(read_buf), stdin);
		stringlen = strlen(read_buf);
		read_buf[stringlen - 1] = '\0';
		end_process = strcmp(read_buf, end_str);

		if (end_process != 0) {
			write (fd, read_buf, strlen(read_buf));
			printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", read_buf, (int)strlen(read_buf));
			read_bytes = read(fd, read_buf, sizeof(read_buf));
			read_buf[read_bytes] = '\0';
			printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", read_buf, (int)strlen(read_buf));

		}
		else {
		  write(fd, read_buf, strlen(read_buf));
		  printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", read_buf, (int)strlen(read_buf));
		  close(fd);
		  break;
		}
	}
		return 0;
}
