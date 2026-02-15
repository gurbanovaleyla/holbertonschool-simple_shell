#include "shell.h"

/**
 * tokenize - Splits a string into an array of tokens (arguments)
 * @line: The string input from the user
 * Return: A null-terminated array of strings
 */
char **tokenize(char *line)
{
	char **args;
	char *token;
	int i = 0;
	char *delim = " \t\n\r";

	/* Allocate space for 64 pointers to strings */
	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);

	token = strtok(line, delim);
	while (token)
	{
		args[i] = token; /* Store the pointer to the word */
		i++;
		token = strtok(NULL, delim);
	}
	args[i] = NULL; /* Null-terminate the array for execve */
	return (args);
}

/**
 * free_args - Frees the array of pointers
 * @args: The array to free
 */
void free_args(char **args)
{
	if (args)
		free(args);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to check
 * Return: Length of string
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
