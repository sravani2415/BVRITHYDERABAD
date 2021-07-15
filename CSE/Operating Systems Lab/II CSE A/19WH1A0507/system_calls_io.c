#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int errno;
void seek();

char message[100] = "\nwriting into the file\n";
char str[100];
int main(){
    int to_write;
    int fd = open("text.txt", O_RDWR | O_CREAT);
    if (fd == -1){
        printf("Error Number %d\n", errno);
        return 0;
    }
    read(fd, &str, 100);
    printf("%s\n", str);
    to_write = write(fd, message, strlen(message));
    close(fd);
    // with the below statements we can see the updated file content
    /*
    fd = open("text.txt", O_RDONLY | O_CREAT);
    read(fd, &str, 100);               
    printf("After writing\n%s\n", str);
    */
    return 0;
}

