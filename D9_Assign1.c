#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void process_handler(int pid, int signum)
{
	int ret;
        ret =kill( pid, signum);
	printf("Process Killed\n");
}

int main(){

	int pid,signum;
	printf("Enter the PID:: ");
	scanf("%d", &pid);

	printf("Enter the Signum:: ");
	scanf("%d", &signum);

	//signal(signum, pid);
	process_handler(pid,signum);

	return 0;
}

