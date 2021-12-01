#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void how(int sig_num)
{
	signal(SIGINT,how);
	printf("How are you?\n");
}
void fine(int sig_num)
{
        signal(SIGINT,fine);
        printf("I am fine\n");
}
void BBB(int sig_num)
{
        signal(SIGINT,SIG_DFL);
}

void AAA(int sig_num)
{
	signal(SIGINT,fine);
	alarm(3);
	signal(SIGALRM,BBB);
}

int main()
{
	signal(SIGINT,how);
	alarm(3);
	signal(SIGALRM,AAA);
	while(1);
	return 0;
}
