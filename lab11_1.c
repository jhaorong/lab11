#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t PID = fork();
	if(PID == -1)
	{
		printf("fork error");
		exit(-1);
	}
	else if(PID == 0)
	{
		printf("I am child,pid = %d and ppid = %d\n",getpid(),getppid());
	}
	else
	{
		printf("I am parent,pid = %d and ppid = %d\n",getpid(),getppid());
		wait(NULL);
	}
	pause();
	return 0;
}
