#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int main() {

	int ret, ret1, err, s,s1, fd, ret2;
	int arr[2], err1;
	printf("Parent Started!\n");

	ret = pipe(arr);
	if(ret <  0) {
		perror("Pipe() failed");
		_exit(1);
	}

	ret1 = fork();
	if(ret1 == 0) {
		close(arr[0]);
		dup2(arr[1], 1);
		close(arr[1]);

		err1 = execlp("in.txt", "/Practise", NULL);
		if(err1 < 0) {
			perror("Exec() failed");
			_exit(1);
		}

	}
	ret2 = fork();
	if(ret2 == 0)
	{
		close(arr[1]);
		dup2(arr[0], 0);
		close(arr[0]);

		err = execlp("wc", "wc", NULL);
		if(err < 0) {
			perror("exec() failed to execute wc cmd");
			_exit(2);
		}
	}

	close(arr[1]);
	close(arr[0]);
	waitpid(ret1, &s, 0);
	waitpid(ret2, &s1, 0);
	printf("Parent Completed\n");

	return 0;
}

