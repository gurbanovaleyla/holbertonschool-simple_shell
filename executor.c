#include "shell.h"

/**
 * execute - Forks and executes a command
 * @args: Command and arguments
 * @prog_name: Shell name
 * @counter: Command count
 * Return: 1 on success
 */
int execute(char **args, char *prog_name, int counter)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			print_error(prog_name, counter, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		wait(&status);
	}
	return (1);
}
