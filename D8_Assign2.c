#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	int hii, bye, pPa, cPb, cPc, cPd, s3, s2, s1, waitt;

	pPa = fork();
	if(pPa == 0){
		cPb = fork();
		if(cPb == 0){
			cPc = fork();
			if(cPd == 0){
				int count = 5;
				while(count != 0)
				{
					printf("Count: %d\n", count);
					count--;
				}
				_exit(0);
			 waitt = waitpid(cPc, &s3, 0);
			}
			_exit(0);
			
		       	waitt = waitpid(cPc, &s3, 0);
			}
			_exit(0);
			
			bye =	waitpid(cPb, &s2, 0);
			_exit(0);
	}

	else{
		
	        hii = waitpid(pPa, &s1, 0);
		printf("Exit: %d\n", hii);
	}
}
