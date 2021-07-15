#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
    char message[] = "Hello, world!";
    int fd = open("seek_file.txt", O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
    char buffer[100];
    if (fd == -1){
        printf("File already exists!\n");
        return 0;
    }
    printf("file opened for read/write access\n");
    write(fd, message, sizeof(message));
    lseek(fd, 0L, 0); //will take the file pointer to beg of file (as it'll be at the end of file as we wrote)
    if (read(fd, buffer, sizeof(message)) == sizeof(message))
        printf("\"%s\" was written to seek_file.txt\n", buffer);
    else
        printf("error reading seek_file.txt\n");
    close(fd);
}
