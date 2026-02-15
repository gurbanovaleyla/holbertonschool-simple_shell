#include "shell.h"

/**
 * execute - Executes command and ensures fork isn't called for invalid cmds
 * @args: Tokenized arguments
 * @prog_name: Program name
 * @counter: Execution count
 * Return: 1 on success
 */
int execute(char **args, char *prog_name, int counter)
{
	pid_t child_pid;
	int status;
	char *full_path;

	/* Check if command exists before forking */
	full_path = _get_path(args[0]);
	if (!full_path)
	{
		print_error(prog_name, counter, args[0]);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		if (full_path != args[0])
			free(full_path);
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Execve Error");
			exit(127);
		}
	}
	else
		wait(&status);

	if (full_path != args[0])
		free(full_path);
	return (1);
}

/**
 * print_error - Prints error in specific format to stderr
 */
void print_error(char *prog_name, int counter, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, counter, cmd);
}
