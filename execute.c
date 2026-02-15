#include "shell.h"

/**
 * execute - Forks a child process and executes a command with arguments
 * @args: Array of strings (command and its arguments)
 * @prog_name: Name of the shell for error reporting
 * @counter: Command execution count
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
		/* execve takes args[0] as the path, and args as the argument list */
		if (execve(args[0], args, environ) == -1)
		{
			print_error(prog_name, counter, args[0]);
			exit(127);
		}
	}
	else
	{
		/* Wait for the specific child process to finish */
		wait(&status);
	}
	return (1);
}

/**
 * print_error - Prints the error message in the required format
 * @prog_name: Shell name (argv[0])
 * @counter: Line/command count
 * @cmd: The command that failed
 */
void print_error(char *prog_name, int counter, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, counter, cmd);
}
