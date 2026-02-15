#include "shell.h"

/**
 * handle_builtin - Handles shell built-in commands
 * @args: Arguments
 * @line: Line buffer to free
 * @status: Current exit status of the shell
 * Return: -1 if not a builtin, otherwise exits
 */
int handle_builtin(char **args, char *line, int status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(status); /* Exit with the last command's status */
	}
	return (-1);
}
