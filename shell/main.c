#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void get_user_input(char* buf)
{
	if(fgets(buf, 512, stdin) == NULL)
		exit(0);

	int last = strlen(buf) - 1;

	if (buf[last] == '\n')
		buf[last] = '\0';
}

int parse_user_input(char* buf, char** argv)
{
	int count = 0;
	char delimiter[] = " ";

	char *ptr = strtok(buf, delimiter);

	while(ptr != NULL)
	{

		argv[count++] = ptr;
		ptr = strtok(NULL, delimiter);
	}

	argv[count] = NULL;

	return count;
}

//Execute program using execvp.
void child_program(char** argv)
{
	execvp(argv[0], argv);
}

void parent_program(pid_t child_pid)
{
	wait(NULL);
	printf("%d\n", child_pid);
}

void run_user_input(char** argv)
{
	//Used to determine if child or parent. Parent uses pid to print
	//after child executes the program
	pid_t pid_value = fork();

	if (pid_value == 0)
	{
		//Child executes user input
		child_program(argv);
	}
	else
	{
		//Parent waits then prints child's pid.
		parent_program(pid_value);
	}
}

int main()
{
	char buf[512];		//buffer for input
	char *argv[512];	//argv for execvp

	//Loop infinitly to grab several inputs to execute.
	while (1)
	{
		//Get user input.
		get_user_input(buf);

		//Parse the input. Return value used for debugging.
		int argc = parse_user_input(buf, argv);

		//fork and execute user input
		run_user_input(argv);
		
		
	}

	return 0;
}
