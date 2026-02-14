#include "shell.h"

/**
 * main - Entry point for the shell
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	(void)ac;
	shell_loop(av[0]);
	return (0);
}

/**
 * shell_loop - Main shell loop
 * @prog_name: Name of the program for errors
 */
void shell_loop(char *prog_name)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	int counter = 0;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(0);
		}

		args = tokenize(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free_args(args);
				exit(0);
			}
			execute(args, prog_name, counter);
		}
		free_args(args);
	}
	free(line);
}
