#include&lt;stdio.h&gt;
#include&lt;unistd.h&gt;

int main() {
int pipefds[2];
int returnstatus;
int pid;
char writemessages[2][20]={&quot;Hi&quot;, &quot;Hello&quot;};
char readmessage[20];
returnstatus = pipe(pipefds);
if (returnstatus == -1) {
printf(&quot;Unable to create pipe\n&quot;);
return 1;
}
pid = fork();

// Child process

if (pid == 0) {
read(pipefds[0], readmessage, sizeof(readmessage));
printf(&quot;Child Process - Reading from pipe – Message 1 is %s\n&quot;, readmessage);
read(pipefds[0], readmessage, sizeof(readmessage));
printf(&quot;Child Process - Reading from pipe – Message 2 is %s\n&quot;, readmessage);
} else { //Parent process
printf(&quot;Parent Process - Writing to pipe - Message 1 is %s\n&quot;, writemessages[0]);
write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
printf(&quot;Parent Process - Writing to pipe - Message 2 is %s\n&quot;, writemessages[1]);
write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
}
return 0;
