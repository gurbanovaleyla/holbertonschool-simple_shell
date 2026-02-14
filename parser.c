#include "shell.h"

/**
 * tokenize - Splits a string into tokens
 * @line: String to split
 * Return: Array of strings
 */
char **tokenize(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		exit(EXIT_FAILURE);

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_args - Frees the array of strings
 * @args: Array to free
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
