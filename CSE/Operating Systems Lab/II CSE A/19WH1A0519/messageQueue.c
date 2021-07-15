#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 20

struct msg_buffer {
	long msg_type;
	char msg_txt[100];
} message;

int main() {
	key_t key;
	int mssgid;

	//ftok to generate a unique key
	key = ftok("progfile", 65);

	mssgid = msgget(key, 0666|IPC_CREAT);
	message.msg_type = 1;

	printf("Write Data: ");
	fgets(message.msg_txt, MAX, stdin);

	// send message
	msgsnd(mssgid, &message, sizeof(message), 0);

	printf("Data send is: %s \n", message.msg_txt);

	return 0;
}