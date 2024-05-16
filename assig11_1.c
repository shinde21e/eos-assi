#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int arr1[2],arr2[2], ret,a,b,c,d, r,s,res;

int main() {
	
	ret = pipe(arr1);
	ret = pipe(arr2);
	ret = fork();
	if(ret == 0)
	{
	close(arr1[0]);
	close(arr2[1]);
	printf ("enter the no : \n");
	scanf("%d%d",&a,&b);

	write(arr1[1],&a,sizeof(a));
	write(arr1[1],&b,sizeof(b));
	printf("parent: waiting for data...\n");
	read(arr2[0],&r,sizeof(r));
	printf("result:%d\n",r);
	close(arr2[0]);
	close(arr1[1]);
	}
	else
	{
	close(arr1[1]);
	close(arr2[0]);
	read(arr1[0],&c,sizeof(c));
	read(arr1[0],&d,sizeof(d));
	r=c+d;
	write(arr2[1],&r,sizeof(r));
	close(arr2[1]);
	close(arr1[0]);
	waitpid(-1,&s,0);
	}
	}


