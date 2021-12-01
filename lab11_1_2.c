#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int kill(pid_t pid,int sig);
int main()
{
	pid_t PID = fork();
	if(PID == 0)
	{
		printf("I am child,pid=%d and ppid=%d\n",getpid(),getppid());
		kill(getpid(),SIGTERM);
	}
	else if(PID > 0)
	{
		printf("I am parent,pid=%d and ppid=%d\n",getpid(),getppid());
		wait(NULL);
		kill(getpid(),SIGTERM);
	}
	for(;;);
	return 0;
}
