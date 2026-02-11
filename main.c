#include "shell.h"

/**
 * main - entry point for the simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	(void)ac;

	run_shell(av);
	return (0);
}

/**
 * run_shell - loop that reads and processes commands
 * @argv: argument vector from main
 */
void run_shell(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = tokenize(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free_args(args);
				free(line);
				exit(EXIT_SUCCESS);
			}
			execute(args, argv);
		}
		free_args(args);
	}
	free(line);
}
