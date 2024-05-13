#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int wait,i, ret1, ret2, ret3, ret4, ret5, count,s,ret;
	ret1 = fork();
	if(ret1 == 0){
         	count = 5;
		while(count != 0)
       		{
			printf("PID 1: %d\n", getpid());
                	printf("Count: %d\n", count);
               		count--;
               		sleep(1);
        	}
		_exit(0);
	}
	 ret2 = fork();
        if(ret2 == 0){
                count = 5;
                while(count != 0)
                {
                        printf("PID 2: %d\n", getpid());
                        printf("Count: %d\n", count);
                        count--;
                        sleep(1);
                }
		_exit(0);
        }

		 ret3 = fork();
       		 if(ret3 == 0){
                	count = 5;
                 while(count != 0)
                 {
                        printf("PID 3: %d\n", getpid());
                        printf("Count: %d\n", count);
                        count--;
                        sleep(1);
                 }
		 _exit(0);
        }

		 ret4 = fork();
         	 if(ret4 == 0){
                	count = 5;
                 while(count != 0)
                 {
                        printf("PID 4: %d\n", getpid());
                        printf("Count: %d\n", count);
                        count--;
                        sleep(1);
                 }
		 _exit(0);
        }
		 ret5 = fork();
       		 if(ret5 == 0){
                  	count = 5;
                 while(count != 0)
                 {
                        printf("PID 5: %d\n", getpid());
                        printf("Count: %d\n", count);
                        count--;
                        sleep(1);
                }
		 _exit(0);
        }
		 

		 for (i = 0; i <=5; i++){
			 wait = waitpid(-1,&s,0);
			 printf("Child Exit: %d\n", wait);
		 }

		 return 0;

}
 
        


