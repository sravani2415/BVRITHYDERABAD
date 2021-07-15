#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

struct mssge_buffer {
	long mssge_type;
	char mssge_text[100];
} message;

int main() {
	key_t key;
	int mssgid;

	//ftok to generate a unique key
	key = ftok("progfile", 65);

	mssgid = msgget(key, 0666|IPC_CREAT);
	message.mssge_type = 1;

	printf("Write Data: ");
	fgets(message.mssge_text, MAX, stdin);

	// send message
	msgsnd(mssgid, &message, sizeof(message), 0);

	printf("Data send is: %s \n", message.mssge_text);

	return 0;
}
