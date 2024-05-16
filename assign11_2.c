#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int arr[32];
void sigint_handler(int sig) 
{
close(arr[1]);
  close(arr[0]);
  _exit(0);
printf("SIGINT caught: %d\n", sig);
}
int main()
{
char ch;
int ret;
int count=0;
ret = pipe(arr);

printf("enter the charater:\n");
scanf("%s",&ch);
struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler = sigint_handler;
ret = sigaction(SIGINT,&sa,NULL);
if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
		}
while(1)
{
write(arr[1],&ch,1);
count++;
printf("byte written: %d\n",count);
}
}



