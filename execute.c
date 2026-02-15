#include "shell.h"

/**
 * execute - Executes the command
 * @args: Tokenized arguments
 * @prog_name: Program name
 * @counter: Execution count
 * Return: 1 on success
 */
int execute(char **args, char *prog_name, int counter)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			print_error(prog_name, counter, args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}

/**
 * print_error - Prints error in specific format
 * @prog_name: Name of shell
 * @counter: Loop count
 * @cmd: Command that failed
 */
void print_error(char *prog_name, int counter, char *cmd)
{
	/* Requirements state errors should go to stderr */
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, counter, cmd);
}
