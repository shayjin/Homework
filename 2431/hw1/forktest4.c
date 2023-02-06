/* Jay Shin */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_COUNT 200

void ChildProcess(void);  	/* child process prototype */
void ParentProcess(void);	/* parent process prototype */

int main()
{

	pid_t pid;
	
	int num = 20;

	pid = fork();

	if (pid == 0)
	{
		ChildProcess();
		printf ("Value of num: %d\n", num);
	}
	else
	{
		ParentProcess();
		num = num + 5;
	}
}

void ChildProcess()
{
	int i;
	pid_t pid;

	pid = getpid();

	for (i = 1; i <= MAX_COUNT; i++)
		printf ("    This line is from child, value =  %d, pid = %d\n", i, pid);
	printf("    ***Child process id done ***\n");
}

void ParentProcess()
{
	int i;
	pid_t pid;

	pid = getpid();

	for(i=1; i <= MAX_COUNT; i++)
		printf("This line is from parent, value = %d, pid = %d\n", i, pid);
	printf("***Parent is done***\n");
}

