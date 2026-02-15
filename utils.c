#include "shell.h"

/**
 * _getenv - Simple getenv implementation
 * @name: Name of the environment variable
 * Return: Value of the variable, or NULL
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = _strlen((char *)name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * _get_path - Finds the full path of a command
 * @command: The command name (e.g., "ls")
 * Return: Full path or NULL if not found
 */
char *_get_path(char *command)
{
	char *path, *path_copy, *token, *file_path;
	struct stat st;

	/* Check if command is already a full path */
	if (stat(command, &st) == 0)
		return (command);

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		file_path = malloc(_strlen(token) + _strlen(command) + 2);
		sprintf(file_path, "%s/%s", token, command);
		if (stat(file_path, &st) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * tokenize - Splits a string into tokens
 */
char **tokenize(char *line)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);
	token = strtok(line, " \t\n\r");
	while (token)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n\r");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees the pointer array
 */
void free_args(char **args)
{
	if (args)
		free(args);
}

/**
 * _strlen - returns length of string
 */
int _strlen(char *s)
{
	int len = 0;
	if (!s) return (0);
	while (s[len]) len++;
	return (len);
}
