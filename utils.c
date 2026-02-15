#include "shell.h"

/**
 * tokenize - Splits a string into tokens
 * @line: The string to split
 * Return: Array of pointers to tokens
 */
char **tokenize(char *line)
{
	char **args;
	char *token;
	int i = 0;
	char *delim = " \t\n\r";

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);

	token = strtok(line, delim);
	while (token)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees the array of strings
 * @args: The array to free
 */
void free_args(char **args)
{
	if (args)
		free(args);
}

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
