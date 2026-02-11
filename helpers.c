#include "shell.h"

/**
 * tokenize - splits a string into an array of tokens
 * @line: string to be tokenized
 *
 * Return: pointer to array of strings
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * execute - forks a child process to run a command
 * @args: array of command and arguments
 * @argv: original argv for error reporting
 */
void execute(char **args, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * free_args - frees the allocated memory for arguments
 * @args: array of strings
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
