#include "shell.h"

/**
 * execute - Executes a command
 * Return: status of the command
 */
int execute(char **args, char *prog_name, int counter)
{
	pid_t child_pid;
	int status;
	char *full_path;

	full_path = _get_path(args[0]);
	if (!full_path)
	{
		print_error(prog_name, counter, args[0]);
		return (127);
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
			exit(2);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	if (full_path != args[0])
		free(full_path);

	return (status);
}

void print_error(char *prog_name, int counter, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, counter, cmd);
}
