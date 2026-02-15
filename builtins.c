#include "shell.h"

/**
 * handle_builtin - Checks if a command is a built-in
 * @args: Tokenized arguments
 * @line: The original line buffer (to free before exiting)
 * Return: 0 if built-in handled, -1 if not found
 */
int handle_builtin(char **args, char *line)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(0);
	}
	return (-1);
}
