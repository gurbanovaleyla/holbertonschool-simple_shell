#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @ac: Argument count (unused)
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
 * shell_loop - Main shell loop that handles the prompt and input
 * @prog_name: Name of the program for error reporting
 */
void shell_loop(char *prog_name)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	int counter = 0, status = 0;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(status);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = tokenize(line);
		if (args && args[0])
		{
			/* Check for 'exit' before forking */
			if (handle_builtin(args, line) == -1)
				status = execute(args, prog_name, counter);
		}
		free_args(args);
	}
	free(line);
}
